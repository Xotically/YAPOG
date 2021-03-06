#ifndef YAPOG_MENU_HPP
# define YAPOG_MENU_HPP

# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Graphics/Gui/MenuItem.hpp"
# include "YAPOG/Graphics/Gui/LayoutBox.hpp"
# include "YAPOG/Graphics/Gui/Padding.hpp"
# include "YAPOG/Graphics/Gui/PartialLayoutManager.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  class YAPOG_LIB Menu : public BaseWidget
  {
    DISALLOW_COPY(Menu);

  public:
    Event<const Menu&, const EmptyEventArgs&> OnDesactivated;

    enum class Type
    {
      VERTICAL,
      HORIZONTAL
    };

    Menu (Type type, Padding ext, Padding in, bool fixed);
    void AddChild (MenuItem& child, LayoutBox::Align align
      = LayoutBox::Align::CENTER);
    virtual ~Menu ();

    void SetSelectedBackground (WidgetBackground& background);
    void SetSelectedBorder (WidgetBorder& border);
    virtual bool IsFocusable () const;
    uint GetCurrentSelect () const;
    void SetFixed (bool state);
    void Clear ();
    protected:
    virtual void HandleItemActivated ();
    virtual void HandleItemSelected ();

    virtual Vector2 HandleGetSize () const;
    virtual void HandleMove (const Vector2& offset);
    virtual void HandleScale (const Vector2& factor);

    virtual void HandleDraw (IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const Time& dt);
    bool HandleOnEvent (const GuiEvent& guiEvent);
  private:
    void SetFormItem ();
    void SetUnformItem ();

    collection::Array<MenuItem*> itemz_;
    uint currentSelec_;
    LayoutBox* layout_;

    WidgetBackground* selecBckgrd_;
    WidgetBorder* selecBrdr_;
    uint selecBrdSize_;
    bool isFixed_;
    Type type_;
    PartialLayoutManager* layoutManager_;

  };
} // namespace yap

#endif /* YAPOG_MENU_HPP! */
