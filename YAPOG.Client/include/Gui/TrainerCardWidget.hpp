#ifndef YAPOG_CLIENT_TRAINERCARDWIDGET_HPP
# define YAPOG_CLIENT_TRAINERCARDWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{
  class Label;
  class PictureBox;
  class VerticalLayout;
  class HorizontalLayout;
}

namespace ycl
{
  class User;

  class TrainerCardWidget : public yap::BaseWidget
  {
    DISALLOW_COPY(TrainerCardWidget);

  public:
    TrainerCardWidget (const User& user);
    virtual ~TrainerCardWidget();

    void Init ();

    virtual bool IsFocusable () const;

  protected:
    void Open ();
    virtual yap::Vector2 HandleGetSize () const;
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);

    virtual void HandleDraw (yap::IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const yap::Time& dt);

    virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);

  private:
    const User& user_;

    // Labels
    yap::Label* uniqueIDLabel_;
    yap::Label* uniqueID_;
    yap::Label* nameLabel_;
    yap::Label* name_;
    yap::Label* moneyLabel_;
    yap::Label* money_;
    yap::Label* pokedexLabel_;
    yap::Label* pokedex_;
    yap::Label* gameTimeLabel_;
    yap::Label* gameTime_;

    // P�ctureBoxes
    yap::PictureBox* playerSprite_;

    // Layouts
    yap::VerticalLayout* mainLayout_;

    yap::VerticalLayout* firstLine_;

    yap::HorizontalLayout* uniqueIDLayout_;

    yap::HorizontalLayout* secondLine_;

    yap::VerticalLayout* secondLinePartLeft_;

    yap::HorizontalLayout* nameLayout_;
    yap::HorizontalLayout* playerDataLayout_;
    yap::VerticalLayout* playerDataLabelsLayout_;
    yap::VerticalLayout* playerDataValuesLayout_;

    yap::VerticalLayout* secondLinePartRight_;

    yap::HorizontalLayout* playerSpriteLayout_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_TRAINERCARDWIDGET_HPP