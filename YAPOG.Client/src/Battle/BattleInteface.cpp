#include "YAPOG/Graphics/Gui/WidgetDialogBox.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"

#include "Battle/BattleInterface.hpp"

#include "TestGame.hpp"

namespace ycl
{
  BattleInterface::BattleInterface ()
    : battleInfoDialogBox_ (nullptr)
  {
    battleInfoDialogBox_ = new yap::WidgetDialogBox ();

    // Init Battle Text Dialog
    battleInfoDialogBox_->SetSize (
      yap::Vector2 (TestGame::SCREEN_SIZE.x, TestGame::SCREEN_SIZE.y / 4));

    battleInfoDialogBox_->SetPadding (new yap::Padding (35, 35, 25, 25));

    battleInfoDialogBox_->SetPosition (
      yap::Vector2 (0, TestGame::SCREEN_SIZE.y - battleInfoDialogBox_->GetSize ().y));

    battleInfoDialogBox_->SetBackground (
    *(new yap::WidgetBackground ("WindowSkins/dummy1.png", true)));

    this->AddChild (*battleInfoDialogBox_);
  }

  yap::WidgetDialogBox* BattleInterface::GetBattleInfoDialogBox () const
  {
    return battleInfoDialogBox_;
  }
}