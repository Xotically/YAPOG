#ifndef YAPOG_CLIENT_BEGINBATTLEPHASE_HPP
# define YAPOG_CLIENT_BEGINBATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Game/Battle/Phase/BeginWildBattlePhase.hpp"

namespace yap
{
  class PhaseArgs;
} // namespace yap

namespace ycl
{
  class Battle;
  class BattleInterface;

  class BeginWildBattlePhase
    : public yap::BeginWildBattlePhase
    , public yap::IDrawable
  {
  public:
    BeginWildBattlePhase (Battle& battle, BattleInterface& battleInterface);
    virtual ~BeginWildBattlePhase ();

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (yap::PhaseArgs* args);
    virtual void HandleUpdate (const yap::Time& dt);
    virtual void HandleEnd ();
    /// @}

  protected:
    virtual void HandleDraw (yap::IDrawingContext& context);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    static const bool DEFAULT_VISIBLE_STATE;
    static const sf::Color DEFAULT_COLOR;

    bool isVisible_;
    sf::Color color_;

  private:
    void UpdatePlayerTrainerBack ();
    void UpdateOpponentFront ();

    Battle& battle_;
    BattleInterface& battleInterface_;

    yap::String nextState_;

    static const float GROUND_SPEED;
    static const yap::String FISRT_STATE;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BEGINBATTLEPHASE_HPP
