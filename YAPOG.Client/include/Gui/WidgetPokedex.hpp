#ifndef YAPOG_CLIENT_WIDGETPOKEDEX_HPP
# define YAPOG_CLIENT_WIDGETPOKEDEX_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class Pokedex;
}

namespace ycl
{
  class WidgetPokedex : public yap::BaseWidget
  {
    DISALLOW_COPY(WidgetPokedex);

  public:
    WidgetPokedex ();
    void Init ();
    virtual ~WidgetPokedex();
    virtual bool IsFocusable () const;

  protected:
    virtual yap::Vector2 HandleGetSize () const;
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);

    virtual void HandleDraw (yap::IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const yap::Time& dt);

  private:
    yap::Pokedex* pokedex_;

  };
} // namespace ycl

#endif // YAPOG_CLIENT_WIDGETPOKEDEX_HPP