#ifndef YAPOG_CLIENT_MAP_HXX
# define YAPOG_CLIENT_MAP_HXX

# include                                                               \
  "YAPOG/Graphics/Game/World/Map/DrawableWorldObjectOrderComparator.hpp"

namespace ycl
{
  template <typename T>
  inline void Map::AddDrawableStaticObject (T* object)
  {
    AddStaticObject (object);
    AddDrawableObject (object);
  }

  template <typename T>
  inline void Map::RemoveDrawableStaticObject (T* object)
  {
    RemoveStaticObject (object);
    RemoveDrawableObject (object);
  }

  template <typename T>
  inline void Map::AddDrawableDynamicObject (T* object)
  {
    AddDynamicObject (object);

    object->OnDrawableMovedEvent ().AddHandler (
      DRAW_ORDER_HANDLER_NAME,
      [&] (yap::IDrawableDynamicWorldObject& sender,
           const yap::Vector2& args)
      {
        /// @todo Sort by adding manually.
        drawableObjects_.Sort<yap::DrawableWorldObjectOrderComparator> ();
      });

    AddDrawableDynamicObject (object->GetWorldID (), object);
  }

  template <typename T>
  inline void Map::RemoveDrawableDynamicObject (T* object)
  {
    RemoveDynamicObject (object);

    object->OnDrawableMovedEvent ().RemoveHandler (DRAW_ORDER_HANDLER_NAME);

    RemoveDrawableDynamicObject (object->GetWorldID ());
  }
} // namespace ycl

#endif // YAPOG_CLIENT_MAP_HXX