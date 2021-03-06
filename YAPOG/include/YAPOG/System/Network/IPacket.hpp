#ifndef YAPOG_IPACKET_HPP
# define YAPOG_IPACKET_HPP

# include <SFML/Network/Packet.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IWriter.hpp"
# include "YAPOG/System/IO/IReader.hpp"
# include "YAPOG/System/Network/PacketType.hpp"

namespace yap
{
  struct IPacket : public IWriter
                 , public IReader
  {
      using IWriter::Accept;
      using IReader::Accept;

      virtual ~IPacket () { }

      virtual const PacketType& GetType () const = 0;

      virtual sf::Packet& GetInnerPacket () = 0;
  };
} // namespace yap

#endif // YAPOG_IPACKET_HPP
