#ifndef YAPOG_GRIDCOLLIDABLEAREA_HPP
# define YAPOG_GRIDCOLLIDABLEAREA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Physics/CollidableArea.hpp"
# include "YAPOG/Collection/Matrix.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class CollidableAreaCell;

  class YAPOG_LIB GridCollidableArea : public CollidableArea
  {
      DISALLOW_COPY(GridCollidableArea);

    public:

      GridCollidableArea ();
      virtual ~GridCollidableArea ();

      void SetSegmentCount (uint vSegmentCount, uint hSegmentCount);

      virtual bool CollidesWith (
        const ICollidable& collidable,
        const Vector2& offset,
        const WorldObject& parent) const;

      virtual void GetEventsCollidingWith (
        const ICollidable& collidable,
        MapEventQueue& events,
        DynamicWorldObject& parent) const;

    protected:

      virtual void HandleSetSize (const Vector2& size);

      virtual void HandleAddPhysicsCollidable (
        ICollidable* collidable,
        const MapCollidableInfo::PtrType& mapCollidableInfo);
      virtual void HandleRemovePhysicsCollidable (ICollidable* collidable);

      virtual void HandleAddEventCollidable (
        ICollidable* collidable,
        const MapEventInfo::PtrType& mapEventInfo);
      virtual void HandleRemoveEventCollidable (ICollidable* collidable);

    private:

      void GetCollidableRectangle (
        const ICollidable& collidable,
        UIntRect& rectangle) const;
      void GetCollidableRectangle (
        const ICollidable& collidable,
        const Vector2& offset,
        UIntRect& rectangle) const;

      static const uint MIN_VSEGMENT_COUNT;
      static const uint MIN_HSEGMENT_COUNT;

      uint vSegmentCount_;
      uint hSegmentCount_;

      Vector2 cellSize_;

      collection::Matrix<CollidableAreaCell*> cells_;
  };
} // namespace yap

#endif // YAPOG_GRIDCOLLIDABLEAREA_HPP
