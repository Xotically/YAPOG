#ifndef YAPOG_TESTSCREEN_HPP
# define YAPOG_TESTSCREEN_HPP

# include "YAPOG/Graphics/Game/GameScreen.hpp"
# include "YAPOG/Graphics/Gui/GuiManager.hpp"
# include "YAPOG/Graphics/Texture.hpp"

class TestScreen : public yap::GameScreen
{
  public:

    TestScreen ();

    virtual const yap::ScreenType& HandleRun (
      const yap::Time& dt,
      yap::IDrawingContext& context);

    virtual void HandleInit ();

    virtual void HandleActivate ();
    virtual void HandleDeactivate ();

    virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);

  private:

    yap::Texture texture_;
};

#endif // YAPOG_TESTSCREEN_HPP
