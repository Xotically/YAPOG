#include "YAPOG/Game/Battle/IBattleEntity.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"

#include "TestGame.hpp"
#include "Battle/Battle.hpp"

namespace ycl
{
  const bool Battle::DEFAULT_VISIBLE_STATE = true;
  const sf::Color Battle::DEFAULT_COLOR = sf::Color ();
  const yap::Vector2 Battle::DEFAULT_OPPONENT_GROUND_SPRITES_SCALE
    = yap::Vector2 (0.75f, 0.75f);

  Battle::Battle (
    yap::IBattleEntity& playerTeam, 
    yap::IBattleEntity& opponent)
    : yap::Battle (playerTeam, opponent)
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
    , background_ (nullptr)
    , playerGround_ (nullptr)
    , opponentGround_ (nullptr)
  {
  }

  Battle::~Battle ()
  {
    delete background_;
    delete playerGround_;
    delete opponentGround_;
  }

  void Battle::HandleInit ()
  {
    /// Load sprites
    background_ = new yap::Sprite (yap::ObjectFactory::Instance ().
      Create<yap::Texture> ("Texture", yap::ID (42)));
    opponentGround_ = new yap::Sprite (yap::ObjectFactory::Instance ().
      Create<yap::Texture> ("Texture", yap::ID (43)));
    playerGround_ = new yap::Sprite (yap::ObjectFactory::Instance ().
      Create<yap::Texture> ("Texture", yap::ID (43)));

    /// Adjust sprites
    background_->SetSize (TestGame::SCREEN_SIZE);
    opponentGround_->Scale (DEFAULT_OPPONENT_GROUND_SPRITES_SCALE);
  }

  /// Getters
  yap::ISprite* Battle::GetBackground () const
  {
    return background_;
  }

  yap::ISprite* Battle::GetPlayerGround () const
  {
    return playerGround_;
  }

  yap::ISprite* Battle::GetOpponentGround () const
  {
    return opponentGround_;
  }

  const yap::Vector2& Battle::GetPlayerGroundPosition () const
  {
    return playerGroundPosition_;
  }

  const yap::Vector2& Battle::GetOpponentGroundPosition () const
  {
    return opponentGroundPosition_;
  }

  /// Setters
  void Battle::SetPlayerGroundPosition (const yap::Vector2& position)
  {
    playerGroundPosition_ = position;
  }

  void Battle::SetOpponentGroundPosition (const yap::Vector2& position)
  {
    opponentGroundPosition_ = position;
  }

  void Battle::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;
  }

  bool Battle::IsVisible () const
  {
    return isVisible_;
  }

  void Battle::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void Battle::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void Battle::HandleUpdate (const yap::Time& dt)
  {
    background_->Update (dt);
    playerGround_->Update (dt);
    opponentGround_->Update (dt);
  }

  void Battle::HandleDraw (yap::IDrawingContext& context)
  {
    background_->Draw (context);
    playerGround_->Draw (context);
    opponentGround_->Draw (context);
  }

  void Battle::HandleShow (bool isVisible)
  {
  }

  void Battle::HandleChangeColor (const sf::Color& color)
  {
  }

} // namespace yap