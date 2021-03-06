#ifndef YAPOG_WIDGET_TEXT_BOX_HPP
# define YAPOG_WIDGET_TEXT_BOX_HPP

# include "YAPOG/Graphics/Texture.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class YAPOG_LIB TextBoxWidget : public BaseWidget
  {
    DISALLOW_COPY(TextBoxWidget);

  public:

    TextBoxWidget ();
    TextBoxWidget (String content, uint size = 30);
    virtual ~TextBoxWidget ();

    virtual const String& GetContent () const;
    virtual void SetText (const String& contentArg);
    void SetCursor (Texture& cursor);
    virtual bool IsFocusable () const;
    void SetTextSize (uint size);
    void Clear ();

  protected:
    void Refresh ();
    virtual bool HandleOnEvent (const GuiEvent& guiEvent);
    virtual Vector2 HandleGetSize () const;
    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);

  private:
    String content_;
    Label* label_;
    Texture* curser_;
    uint curserPos_;
    uint curserRelPos_;

  };
} // namespace yap

#endif /* YAPOG_WIDGET_TEXT_BOX_HPP! */
