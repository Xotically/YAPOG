#include "World/Map/NPC.hpp"

#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogManager.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"

namespace ycl
{
  const yap::String NPC::OBJECT_FACTORY_TYPE_NAME = "NPC";

  const yap::String NPC::DEFAULT_NAME = "<UNKNOWN_NPC>";

  NPC::NPC (const yap::ID& id)
    : Character (id)
    , name_ (DEFAULT_NAME)
    , dialogNode_ (nullptr)
  {
  }

  NPC::~NPC ()
  {
  }

  NPC::NPC (const NPC& copy)
    : Character (copy)
    , name_ (copy.name_)
    , dialogNode_ (
        copy.dialogNode_ == nullptr ? nullptr : copy.dialogNode_->Clone ())
  {
  }

  NPC* NPC::Clone () const
  {
    return new NPC (*this);
  }

  void NPC::SetDialogNode (yap::IDialogNode* dialogNode)
  {
    dialogNode_ = dialogNode;
  }

  const yap::String& NPC::GetName () const
  {
    return name_;
  }

  const yap::ID& NPC::GetWorldID () const
  {
    return Character::GetWorldID ();
  }

  bool NPC::CanTalk (yap::IDialogActor& dialogActor) const
  {
    return true;
  }

  void NPC::Talk (yap::IDialogActor& dialogActor)
  {
  }

  void NPC::StopTalking ()
  {
  }

  bool NPC::CanListen (yap::IDialogActor& dialogActor) const
  {
    return false;
  }

  void NPC::Listen (yap::IDialogActor& dialogActor)
  {
  }

  void NPC::StopListening ()
  {
  }

  bool NPC::TryStartDialog (yap::IDialogManager& dialogManager)
  {
    if (dialogNode_ == nullptr)
      return false;

    dialogManager.StartDialog (*this, *dialogNode_);

    return true;
  }

  void NPC::Accept (yap::IDynamicWorldObjectVisitor& visitor)
  {
    Character::Accept (visitor);

    visitor.VisitNPC (*this);
  }

  void NPC::Accept (
    yap::IDynamicWorldObjectConstVisitor& visitor) const
  {
    Character::Accept (visitor);

    visitor.VisitNPC (*this);
  }

  const yap::String& NPC::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }
} // namespace ycl
