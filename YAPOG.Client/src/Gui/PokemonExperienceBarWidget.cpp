#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"

#include "Gui/PokemonExperienceBarWidget.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  PokemonExperienceBarWidget::PokemonExperienceBarWidget ()
    : yap::ProgressBarWidget ()
    , experienceBarContent_ (nullptr)
    , mainLayout_ (nullptr)
  {
    mainLayout_ = new yap::HorizontalLayout (
      yap::Padding (60, 0, 0, 11), yap::Padding (), false);
    experienceBarContent_ = new yap::PictureBox ();
  }

  void PokemonExperienceBarWidget::Init ()
  {
    SetSize (yap::Vector2 (258, 26));

    SetBackground (*new yap::WidgetBackground (
      "Pictures/TeamManager/ExperienceBarContainer.png", true));

    experienceBarContent_->SetPicture (new yap::Sprite (
      "Pictures/TeamManager/ExperienceBarContent.png"));

    mainLayout_->SetSize (GetSize ());

    mainLayout_->AddChild (*experienceBarContent_, yap::LayoutBox::Align::TOP);

    AddChild (*mainLayout_);
  }

  void PokemonExperienceBarWidget::SetPokemon (const Pokemon& pokemon)
  {
    experienceBarContent_->SetSize (yap::Vector2 (
      137 * pokemon.GetExperiencePercentage (), 8));
  }

  bool PokemonExperienceBarWidget::IsFocusable () const
  {
    return false;
  }

  void PokemonExperienceBarWidget::HandleMove (const yap::Vector2& offset)
  {
  }

  void PokemonExperienceBarWidget::HandleScale (const yap::Vector2& factor)
  {
  }
  void PokemonExperienceBarWidget::HandleDraw (yap::IDrawingContext& offset)
  {
  }

  void PokemonExperienceBarWidget::HandleShow (bool isVisible)
  {
  }

  void PokemonExperienceBarWidget::HandleChangeColor (const sf::Color& color)
  {
  }

  void PokemonExperienceBarWidget::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl
