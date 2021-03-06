#ifndef YAPOG_CLIENT_BATTLE_HPP
# define YAPOG_CLIENT_BATTLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Game/Battle/Battle.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"

#include "Battle/IDrawableBattleEntity.hpp"

namespace yap
{
  class ISprite;
}

namespace ycl
{
  class BattleInterface;
  class PokemonFighterTeam;
  class PokemonFighter;

  class Battle 
    : public yap::Battle
    , public yap::IDrawable
  {
  public:
    explicit Battle (BattleInterface& battleInterface);
    virtual ~Battle ();

    /// @name IDrawable members.
    /// @{
    virtual void Draw (yap::IDrawingContext& context);

    virtual bool IsVisible () const;
    virtual void Show (bool isVisible);

    virtual void ChangeColor (const sf::Color& color);
    /// @}

    /// @name Getters.
    /// @{
    yap::ISprite& GetBackground () const;
    yap::ISprite& GetPlayerGround () const;
    yap::ISprite& GetOpponentGround () const;
    yap::ISprite& GetPlayerTrainerBack () const;
    yap::ISprite& GetPlayerTeamSprite ();
    yap::ISprite& GetOpponentSprite ();
    const yap::Vector2& GetPlayerGroundPosition () const;
    const yap::Vector2& GetOpponentGroundPosition () const;
    const yap::Vector2& GetOpponentInfoPosition () const;
    const yap::Vector2& GetPokemonInfoPosition () const;
    IDrawableBattleEntity& GetPlayerTeam ();
    IDrawableBattleEntity& GetOpponent ();
    /// @}

    /// @name Setters.
    /// @{
    void SetPlayerTeam (PokemonFighterTeam* playerTeam);
    void SetOpponent (IDrawableBattleEntity* opponent);

    void SetPlayerTeamPosition (const yap::Vector2& value);
    void SetOpponentPosition (const yap::Vector2& value);
    /// @}

    void ShowPlayerTeam (bool isVisible);
    void ShowOpponent (bool isVisible);

    static const yap::Vector2 DEFAULT_OPPONENT_GROUND_SPRITES_SCALE;

    /// @name Events.
    /// @{
    yap::Event<const Battle&> OnBattleEnd;
    /// @}

    static const yap::Vector2 OPPONENT_POSITION;
    static const yap::Vector2 OPPONENT_INFO_POSITION;
    static const yap::Vector2 OPPONENT_GROUND_POSITION;
    static const yap::Vector2 PLAYER_POSITION;
    static const yap::Vector2 POKEMON_POSITION;
    static const yap::Vector2 POKEMON_INFO_POSITION;
    static const yap::Vector2 POKEMON_GROUND_POSITION;

  protected:
    virtual void HandleInit ();
    virtual void HandleUpdate (const yap::Time& dt);

    virtual void HandleDraw (yap::IDrawingContext& context);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    static const bool DEFAULT_VISIBLE_STATE;
    static const sf::Color DEFAULT_COLOR;

    bool isVisible_;
    sf::Color color_;
    BattleInterface& battleInterface_;

  private:
    /// General sprites
    yap::ISprite* background_;
    yap::ISprite* playerGround_;
    yap::ISprite* opponentGround_;
    yap::ISprite* playerTrainerBack_;

    /// Sprite positions
    yap::Vector2 playerGroundPosition_;
    yap::Vector2 opponentGroundPosition_;
    yap::Vector2 opponentInfoPosition_;
    yap::Vector2 pokemonInfoPosition_;

    // Fighters
    IDrawableBattleEntity* playerTeam_;
    IDrawableBattleEntity* opponent_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_WILDBATTLE_HPP
