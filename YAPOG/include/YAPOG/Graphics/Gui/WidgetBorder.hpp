#ifndef YAPOG_WIDGET_BORDER_HPP
# define YAPOG_WIDGET_BORDER_HPP

# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Texture.hpp"
# include "YAPOG/Graphics/Gui/TextureManager.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Collection/Array.hpp"

namespace yap
{
  class YAPOG_LIB WidgetBorder : public BaseWidget
  {
    DISALLOW_COPY(WidgetBorder);

  public:

    struct EventArgsTexture
    {
      Texture& newContent;
      EventArgsTexture (Texture& content)
        : newContent (content)
      {
      }
    };

    WidgetBorder ();
    WidgetBorder (String file);
    WidgetBorder (Texture& top,
      Texture& topRight,
      Texture& right,
      Texture& botRight,
      Texture& bot,
      Texture& botLeft,
      Texture& left,
      Texture& topLeft,
      bool isScalable);

    virtual ~WidgetBorder ();

    virtual bool IsFocusable () const;
    Event<const WidgetBorder&, const EventArgsTexture&> OnBorderSet;
    void SetBorder (Vector2 size, uint width);
    void SetBorder (Vector2 size);
    const Texture& GetTexture () const;
    void SetScalable (bool state);
    uint GetWidth () const;

  private:
    uint GetTextureWidth () const;
    virtual Vector2 HandleGetSize () const;
    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);

    Texture* border_;
    String file_;

    collection::Array<Texture*> textures_;
    collection::Array<TextureManager*> tms_;
    TextureManager* tmTop_;
    TextureManager* tmBottom_;
    TextureManager* tmLeft_;
    TextureManager* tmRight_;
    uint width_;

    bool isInit;
    bool basic_;
    bool isScalable_;

  };
} // namespace yap

#endif /* YAPOG_WIDGET_BORDER_HPP! */