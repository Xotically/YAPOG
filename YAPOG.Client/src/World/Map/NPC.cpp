#include "World/Map/NPC.hpp"

NPC::NPC (const yap::ID& id)
  : Character (id)
{
}

NPC::~NPC ()
{
}

NPC::NPC (const NPC& copy)
  : Character (copy)
{
}

NPC* NPC::Clone () const
{
  return new NPC (*this);
}
