#ifndef YAPOG_CLIENT_DESTRUCTIBLEOBJECT_HPP
# define YAPOG_CLIENT_DESTRUCTIBLEOBJECT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/DestructibleObject.hpp"
# include "YAPOG/Graphics/Game/World/Map/IDrawableDynamicWorldObject.hpp"

namespace yap
{
  struct ISprite;
} // namespace yap

namespace ycl
{
  class DestructibleObject : public yap::DestructibleObject
                           , public yap::IDrawableDynamicWorldObject
  {
      DISALLOW_ASSIGN(DestructibleObject);

    public:

      explicit DestructibleObject (const yap::ID& id);
      virtual ~DestructibleObject ();

      void SetSprite (yap::ISprite* sprite);

      /// @name ICloneable members.
      /// @{
      virtual DestructibleObject* Clone () const;
      /// @}

      /// @name IDrawable members.
      /// @{
      virtual void Draw (yap::IDrawingContext& context);

      virtual bool IsVisible () const;
      virtual void Show (bool isVisible);

      virtual void ChangeColor (const sf::Color& color);
      /// @}

      /// @name IDrawableWorldObject members.
      /// @{
      virtual float GetComparisonPoint () const;

      virtual int GetLayerDepth () const;

      virtual void ChangeWorldDrawingPolicy (
        const yap::IWorldDrawingPolicy& worldDrawingPolicy);
      /// @}

      /// @name IDrawableDynamicWorldObject members.
      /// @{
      virtual yap::Event<
        IDrawableDynamicWorldObject&,
        const yap::Vector2&>& OnOrderStateChangedEvent ();
      /// @}

      yap::Event<
        IDrawableDynamicWorldObject&,
        const yap::Vector2&> OnOrderStateChanged;

    protected:

      DestructibleObject (const DestructibleObject& copy);

      virtual const yap::String& GetObjectFactoryTypeName () const;

      virtual void HandleUpdate (const yap::Time& dt);

      virtual yap::Vector2 HandleGetSize () const;

      virtual void HandleMove (const yap::Vector2& offset);

      virtual void HandleDraw (yap::IDrawingContext& context);

      virtual void HandleShow (bool isVisible);
      virtual void HandleChangeColor (const sf::Color& color);

      virtual float HandleGetComparisonPoint () const;

      virtual int HandleGetLayerDepth () const;

      virtual void HandleChangeWorldDrawingPolicy (
        const yap::IWorldDrawingPolicy& worldDrawingPolicy);

    private:

      static const bool DEFAULT_VISIBLE_STATE;
      static const sf::Color DEFAULT_COLOR;

      static const int DEFAULT_LAYER_DEPTH;

      static const yap::String OBJECT_FACTORY_TYPE_NAME;

      bool isVisible_;
      sf::Color color_;

      const yap::IWorldDrawingPolicy* worldDrawingPolicy_;

      yap::ISprite* sprite_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_DESTRUCTIBLEOBJECT_HPP
