#include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{
  const bool BaseWidget::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BaseWidget::DEFAULT_COLOR = sf::Color ();

  BaseWidget::BaseWidget ()
    : spatialInfo_ ()
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
    , drawables_ ()
    , eventHandlers_ ()
    , childen_ ()
    , root_ (nullptr)
    , parent_ (nullptr)
    , focusedChildren_ (nullptr)
    , padding_ ()
    , background_ (nullptr)
    , border_ (nullptr)
  {
  }

  BaseWidget::~BaseWidget ()
  {
  }

  const Vector2& BaseWidget::GetPosition () const
  {
    return spatialInfo_.GetPosition ();
  }

  const Vector2& BaseWidget::GetSize () const
  {
    spatialInfo_.SetSize (HandleGetSize ());

    return spatialInfo_.GetSize ();
  }

  const Vector2& BaseWidget::GetTopLeft () const
  {
    return spatialInfo_.GetTopLeft ();
  }

  const Vector2& BaseWidget::GetBottomRight () const
  {
    return spatialInfo_.GetBottomRight ();
  }

  const Vector2& BaseWidget::GetCenter () const
  {
    return spatialInfo_.GetCenter ();
  }

  const sf::FloatRect& BaseWidget::GetRectangle () const
  {
    return spatialInfo_.GetRectangle ();
  }

  void BaseWidget::Move (const Vector2& offset)
  {
    spatialInfo_.SetPosition (GetPosition () + offset);

    HandleMove (offset);
  }

  void BaseWidget::Scale (const Vector2& factor)
  {
    spatialInfo_.SetSize (
      Vector2 (
        GetSize ().x * factor.x,
        GetSize ().y * factor.y));

    HandleScale (factor);
  }

  void BaseWidget::SetPosition (const Vector2& position)
  {
    Move (position - GetPosition ());
  }

  void BaseWidget::SetSize (const Vector2& size)
  {
    Scale (
      Vector2 (
        size.x / GetSize ().x,
        size.y / GetSize ().y));
  }

  void BaseWidget::Draw (IDrawingContext& context)
  {
    if (!isVisible_)
      return;

    HandleDraw (context);
  }

  bool BaseWidget::IsVisible () const
  {
    return isVisible_;
  }

  void BaseWidget::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void BaseWidget::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  bool BaseWidget::OnEvent (const GuiEvent& guiEvent)
  {
    return HandleOnEvent (guiEvent);
  }

  bool BaseWidget::OnPriorityEvent (const GuiEvent& guiEvent)
  {
    return HandleOnPriorityEvent (guiEvent);
  }

  void BaseWidget::Update (const Time& dt)
  {
    for each (IWidget* child in childen_)
    {
      child->Update (dt);
    }

    HandleUpdate (dt);
  }

  Vector2 BaseWidget::HandleGetSize () const
  {
    return spatialInfo_.GetSize ();
  }

  void BaseWidget::AddDrawable (IDrawable& drawable)
  {
    drawables_.Add (&drawable);
  }

  void BaseWidget::AddChild (IWidget& child)
  {
    childen_.Add (&child);
  }

  IWidget& BaseWidget::GetRoot () const
  {
    return *root_;
  }

  void BaseWidget::SetParent (IWidget& parent)
  {
    parent_ = &parent;
  }

  void BaseWidget::SetPadding (Padding* padding)
  {
    padding_ = padding;
  }

  void BaseWidget::SetBackground (WidgetBackground& background)
  {
    background_= &background;
  }

  void BaseWidget::SetBorder (WidgetBorder& border)
  {
    border_ = &border;
  }
} // namespace yap
