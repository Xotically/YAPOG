#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

#include "Battle/Phase/BeginTrainerBattlePhase.hpp"
#include "Battle/OpponentBattleInfoWidget.hpp"
#include "Battle/BattleInterface.hpp"
#include "Battle/Battle.hpp"
#include "Game.hpp"

namespace ycl
{
  const bool BeginTrainerBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color BeginTrainerBattlePhase::DEFAULT_COLOR = sf::Color ();

  BeginTrainerBattlePhase::BeginTrainerBattlePhase (Battle& battle, BattleInterface& battleInterface)
    : yap::BeginTrainerBattlePhase (battle)
    , battle_ (battle)
    , battleInterface_  (battleInterface)
  {
  }

  BeginTrainerBattlePhase::~BeginTrainerBattlePhase ()
  {
  }

  void BeginTrainerBattlePhase::HandleStart (yap::PhaseArgs* args)
  {
    yap::BeginTrainerBattlePhase::HandleStart (args);
  }

  void BeginTrainerBattlePhase::HandleUpdate (const yap::Time& dt)
  {
    yap::BeginTrainerBattlePhase::HandleUpdate (dt);
  }

  void BeginTrainerBattlePhase::HandleEnd ()
  {
    yap::BeginTrainerBattlePhase::HandleEnd ();
  }

  void BeginTrainerBattlePhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void BeginTrainerBattlePhase::HandleShow (bool isVisible)
  {
  }

  void BeginTrainerBattlePhase::HandleChangeColor (const sf::Color& color)
  {
  }
}