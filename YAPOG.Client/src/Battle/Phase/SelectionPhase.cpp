#include "Battle/Phase/SelectionPhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"

namespace ycl
{
  const bool SelectionPhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color SelectionPhase::DEFAULT_COLOR = sf::Color ();

  SelectionPhase::SelectionPhase (Battle& battle, BattleInterface& battleInterface)
    : yap::SelectionPhase (battle)
    , battle_ (battle)
    , battleInterface_  (battleInterface)
  {
  }

  SelectionPhase::~SelectionPhase ()
  {
  }

  void SelectionPhase::HandleStart ()
  {
    BattlePhase::HandleStart ();
  }

  void SelectionPhase::HandleUpdate (const yap::Time& dt)
  {
    nextPhase_ = yap::BattlePhaseState::BeginBattle;
  }

  void SelectionPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
  }

  void SelectionPhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool SelectionPhase::IsVisible () const
  {
    return isVisible_;
  }

  void SelectionPhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void SelectionPhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void SelectionPhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void SelectionPhase::HandleShow (bool isVisible)
  {
  }

  void SelectionPhase::HandleChangeColor (const sf::Color& color)
  {
  }
}