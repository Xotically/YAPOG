#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/Network/Packet.hpp"

#include "Client/Session.hpp"
#include "Configuration/GameData.hpp"

#include "YAPOG/System/IO/Log/DebugLogger.hpp"
namespace ycl
{
  const yap::Int16 Session::DEFAULT_REMOTE_PORT = 8008;

  const yap::Time Session::DEFAULT_RECEPTION_SLEEP_DELAY = yap::Time (0.005f);

  Session::Session ()
    : packetHandler_ ()
    , receptionThread_ ([this] () { HandleReception (); })
    , receptionIsActive_ (false)
    , socket_ ()
    , networkHandler_ (socket_)
    , networkHandlerMutex_ ()
    , user_ ()
    , isConnected_ (false)
  {
    ADD_HANDLER(
      ServerInfoLoginValidation,
      Session::HandleServerInfoLoginValidation);

    ADD_HANDLER(
      ServerInfoRegistrationValidation,
      Session::HandleServerInfoRegistrationValidation);

    ADD_HANDLER(ServerInfoLoginError, Session::HandleServerInfoLoginError);

    ADD_HANDLER(
      ServerInfoRegistrationError,
      Session::HandleServerInfoRegistrationError);

    ADD_HANDLER(ServerInfoPrimaryData, Session::HandleServerInfoPrimaryData);
  }

  Session::~Session ()
  {
  }

  Session& Session::Instance ()
  {
    static Session instance;

    return instance;
  }

  void Session::Refresh ()
  {
    {
      yap::Lock lock (networkHandlerMutex_);

      while (!networkHandler_.IsEmpty ())
      {
        yap::PacketPtrType packet (networkHandler_.GetPacket ());
        yap::DebugLogger::Instance ().LogLine (
          "Packet: " +
          yap::StringHelper::ToString (static_cast<int> (packet->GetType ())));
        if (!HandlePacket (*packet))
        {
          Disconnect ();
          YAPOG_THROW("Wrong packet received.");
        }
      }
    }
  }

  void Session::Login (const yap::String& login, const yap::String& password)
  {
    if (!Connect ())
      return;
    //  YAPOG_THROW("Failed to connect to the server `"
    //  + DEFAULT_REMOTE_IP
    //  + "'.");

    user_.SetLogin (login);

    /// @todo login request
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ClientRequestLogin);
    packet.Write (login);
    packet.Write (password);
    SendPacket (packet);
  }

  void Session::Register (
    const yap::String& login,
    const yap::String& password,
    const yap::String& email)
  {
    if (!Connect ())
      return;

    /// @todo registration request
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ClientRequestRegistration);
    packet.Write (login);
    packet.Write (password);
    packet.Write (email);
    SendPacket (packet);
  }

  User& Session::GetUser ()
  {
    return user_;
  }

  bool Session::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool Session::SendPacket (yap::IPacket& packet)
  {
    return socket_.Send (packet);
  }

  void Session::AddRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.AddRelay (relay);
  }

  void Session::RemoveRelay (yap::IPacketHandler* relay)
  {
    relay->SetParent (nullptr);

    packetHandler_.RemoveRelay (relay);
  }

  void Session::SetParent (yap::IPacketHandler* parent)
  {
    YAPOG_THROW("Unallowed to set parent for Session.");
  }

  bool Session::Connect ()
  {
    if (isConnected_)
      return true;

    if (!socket_.Connect (GameData::RemoteIPAddress (), DEFAULT_REMOTE_PORT))
      return false;

    AddRelay (&user_);
    user_.SetParent (this);

    receptionIsActive_ = true;
    receptionThread_.Launch ();

    isConnected_ = true;

    return true;
  }

  void Session::Disconnect ()
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ClientInfoDeconnection);
    SendPacket (packet);

    socket_.Disconnect ();

    receptionIsActive_ = false;

    isConnected_ = false;
  }

  void Session::HandleReception ()
  {
    if (!isConnected_)
      return;

    while (receptionIsActive_)
    {
      yap::Thread::Sleep (DEFAULT_RECEPTION_SLEEP_DELAY);

      {
        yap::Lock lock (networkHandlerMutex_);

        networkHandler_.Refresh ();
      }
    }
  }

  void Session::HandleServerInfoLoginValidation (yap::IPacket& packet)
  {
    OnLoginValidation (*this, yap::EmptyEventArgs ());

    yap::DebugLogger::Instance ().LogLine ("Login successful !");

    yap::Packet response;
    response.CreateFromType (yap::PacketType::ClientRequestStartInfo);
    SendPacket (response);
  }

  void Session::HandleServerInfoRegistrationValidation (yap::IPacket& packet)
  {
    OnRegistrationValidation (*this, yap::EmptyEventArgs ());

    yap::DebugLogger::Instance ().LogLine ("Registration successful !");
  }

  void Session::HandleServerInfoLoginError (yap::IPacket& packet)
  {
    OnLoginError (*this, yap::EmptyEventArgs ());

    yap::DebugLogger::Instance ().LogLine ("Wrong login.");
  }

  void Session::HandleServerInfoRegistrationError (yap::IPacket& packet)
  {
    OnRegistrationError (*this, yap::EmptyEventArgs ());

    yap::DebugLogger::Instance ().LogLine ("Registration error.");
  }

  void Session::HandleServerInfoPrimaryData (yap::IPacket& packet)
  {
    UpdateObjectFactory (packet, yap::ObjectFactory::Instance ());
  }

  void Session::UpdateObjectFactory (
    yap::IPacket& packet,
    yap::ObjectFactory& objectFactory)
  {
    yap::UInt64 typeCount = packet.ReadUInt64 ();

    for (yap::UInt64 count = 0; count < typeCount; ++count)
    {
      yap::ID id = packet.ReadID ();
      yap::String type = packet.ReadString ();

      objectFactory.AddType (id, type);
    }
  }
} // namespace ycl
