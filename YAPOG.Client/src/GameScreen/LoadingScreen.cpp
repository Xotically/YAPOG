#include "GameScreen/LoadingScreen.hpp"

namespace ycl
{
  const yap::ScreenType LoadingScreen::DEFAULT_NAME = "Loading";

  LoadingScreen::LoadingScreen (yap::IDrawingContext& context)
    : BaseScreen (DEFAULT_NAME, context)
  {
  }

  LoadingScreen::~LoadingScreen ()
  {
  }

  void LoadingScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    /// @TODO Next screen must be "Update" to launch the updater

    nextScreen_ = "Splash";

    BaseScreen::HandleRun (dt, context);
  }
} // namespace ycl
