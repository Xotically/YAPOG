#ifndef YAPOG_CLIENT_BATTLESCREEN_HPP
# define YAPOG_CLIENT_BATTLESCREEN_HPP

# include "YAPOG/Macros.hpp"

# include "GameScreen/BaseScreen.hpp"
# include "Battle/BattleInterface.hpp"

namespace ycl
{
  class Battle;
  class PokemonTeam;

  class BattleScreen : public BaseScreen
  {
      DISALLOW_COPY(BattleScreen);

    public:

      explicit BattleScreen (yap::IDrawingContext& context);
      virtual ~BattleScreen ();

    protected:

      virtual void HandleInit ();

      virtual void HandleRun (
        const yap::Time& dt,
        yap::IDrawingContext& context);
                                     
    virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);
    virtual void HandleActivate ();
    virtual void HandleDeactivate ();

    void SetBattle (Battle* value);
  private:

      Battle* battle_;
      BattleInterface* battleInterface_;

      static const yap::ScreenType DEFAULT_NAME;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLESCREEN_HPP
