#ifndef YAPOG_DRAWINGCONTEXT_HPP
# define YAPOG_DRAWINGCONTEXT_HPP

# include <SFML/Graphics/RenderWindow.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Graphics/IDrawingContext.hpp"
# include "YAPOG/Graphics/ICamera.hpp"

namespace yap
{
  /// @brief A common implementation of an IDrawingContext.
  class YAPOG_LIB DrawingContext : public IDrawingContext
  {
      DISALLOW_COPY(DrawingContext);

    public:

      DrawingContext (const Vector2& size, const String& name);
      virtual ~DrawingContext ();

      /// @name IDrawingContext members.
      /// @{
      virtual void AddCamera (const CameraMode& mode, ICamera* camera);
      virtual void RemoveCamera (const CameraMode& mode);

      virtual const ICamera& GetCamera () const;
      virtual ICamera& GetCamera ();
      virtual const ICamera& GetCamera (const CameraMode& mode) const;
      virtual ICamera& GetCamera (const CameraMode& mode);

      virtual void SetMode (const CameraMode& mode);
      virtual void SetDefaultMode (const CameraMode& mode);
      virtual void SetDefaultCamera ();

      virtual const sf::RenderTarget& GetRenderTarget () const;
      virtual sf::RenderTarget& GetRenderTarget ();

      virtual void Draw (const sf::Drawable& drawable);
      virtual void Draw (
        const sf::Drawable& drawable,
        const sf::RenderStates& states);

      virtual const sf::Color& GetTargetClearColor () const;
      virtual void SetTargetClearColor (const sf::Color& color);

      virtual void ChangeSize (const Vector2& size);
      /// @}

      sf::RenderWindow& GetWindow ();

    protected:

      virtual void HandleDraw (
        const sf::Drawable& drawable,
        const sf::RenderStates& states);

    private:

      void SetCurrentMode (const CameraMode& mode);

      static const sf::Color DEFAULT_TARGET_CLEAR_COLOR;

      sf::RenderWindow window_;
      CameraMode currentMode_;
      CameraMode defaultMode_;
      collection::Map<CameraMode, ICamera*> cameras_;

      sf::Color targetClearColor_;
  };
} // namespace yap

#endif // YAPOG_DRAWINGCONTEXT_HPP
