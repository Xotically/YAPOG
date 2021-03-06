#ifndef YAPOG_WIDGET_DIALOG_BOX_HPP
# define YAPOG_WIDGET_DIALOG_BOX_HPP

# include "YAPOG/Graphics/Texture.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/Time/UpdateableTimer.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  class YAPOG_LIB DialogBoxWidget : public BaseWidget
  {
    DISALLOW_COPY(DialogBoxWidget);

  public:
    Event<const BaseWidget&, const EmptyEventArgs&> OnTextChanged;

    DialogBoxWidget ();
    DialogBoxWidget (const String& content);  
    virtual ~DialogBoxWidget ();

    virtual String GetContent () const;
    virtual void AddText (const String& contentArg);
    virtual bool IsFocusable () const;
    void SetShowText (bool state);

    void SkipText ();

    bool IsEmpty () const;

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
    collection::Array<Label*> labels_;
    uint currentText_;
    UpdateableTimer textSpeed_;
    bool showText_;

  };
} // namespace yap

#endif /* YAPOG_WIDGET_TEXT_BOX_HPP! */