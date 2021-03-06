#include "YAPOG/Game/World/Map/Character.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"

namespace yap
{
  const Direction Character::DEFAULT_DIRECTION = Direction::South;

  Character::Character (const ID& id)
    : DynamicWorldObject (id)
    , direction_ (DEFAULT_DIRECTION)
  {
  }

  Character::~Character ()
  {
  }

  Character::Character (const Character& copy)
    : DynamicWorldObject (copy)
    , direction_ (copy.direction_)
  {
  }

  void Character::Accept (IDynamicWorldObjectVisitor& visitor)
  {
    DynamicWorldObject::Accept (visitor);

    visitor.VisitCharacter (*this);
  }

  void Character::Accept (IDynamicWorldObjectConstVisitor& visitor) const
  {
    DynamicWorldObject::Accept (visitor);

    visitor.VisitCharacter (*this);
  }

  const Direction& Character::GetDirection () const
  {
    return direction_;
  }

  void Character::RawSetDirection (Direction direction)
  {
    SetDirection (direction);
  }

  void Character::SetDirection (Direction direction)
  {
    direction_ = direction;

    HandleSetDirection (direction);
  }

  void Character::HandleSetDirection (Direction direction)
  {
  }

  void Character::HandleOnVelocityChanged (
    const Vector2& oldVelocity,
    const Vector2& currentVelocity)
  {
    DynamicWorldObject::HandleOnVelocityChanged (oldVelocity, currentVelocity);

    UpdateDirection (currentVelocity);
  }

  void Character::UpdateDirection (const Vector2& velocity)
  {
    if (velocity.x < 0.0f)
      SetDirection (Direction::West);
    else if (velocity.y < 0.0f)
      SetDirection (Direction::North);
    else if (velocity.x > 0.0f)
      SetDirection (Direction::East);
    else if (velocity.y > 0.0f)
      SetDirection (Direction::South);
  }
} // namespace yap
