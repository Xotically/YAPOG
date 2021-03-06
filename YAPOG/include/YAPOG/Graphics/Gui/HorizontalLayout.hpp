#ifndef YAPOG_LAYOUT_H_HPP
# define YAPOG_LAYOUT_H_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/LayoutBox.hpp"

namespace yap
{
  class YAPOG_LIB HorizontalLayout : public LayoutBox
  {
    DISALLOW_COPY(HorizontalLayout);

  public:

    HorizontalLayout ();
    HorizontalLayout (Padding ext, Padding in, bool isExt);
    virtual ~HorizontalLayout ();
    virtual void GeneratePosition ();
    virtual float GetWidthItem ();
    

  private:

    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);
  };
} // namespace yap

#endif /* YAPOG_LAYOUT_H! */