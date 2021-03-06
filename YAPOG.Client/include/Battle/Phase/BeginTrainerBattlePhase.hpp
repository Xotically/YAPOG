#ifndef YAPOG_CLIENT_BEGINTRAINERBATTLEPHASE_HPP
# define YAPOG_CLIENT_BEGINTRAINERBATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"

# include "Battle/Phase/BeginBattlePhase.hpp"

namespace yap
{
  class PhaseArgs;
} // namespace yap

namespace ycl
{
  class Battle;
  class BattleInterface;

  class BeginTrainerBattlePhase
    : public BeginBattlePhase
  {
  public:
    BeginTrainerBattlePhase (Battle& battle, BattleInterface& battleInterface);
    virtual ~BeginTrainerBattlePhase ();

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (const yap::PhaseArgs& args);
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
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BEGINTRAINERBATTLEPHASE_HPP
