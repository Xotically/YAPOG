#include "YAPOG/Graphics/Gui/GuiManager.hpp"

#include "GameScreen/RegistrationScreen.hpp"

namespace ycl
{
  const yap::ScreenType RegistrationScreen::DEFAULT_NAME = "Registration";

  RegistrationScreen::RegistrationScreen ()
    : BaseScreen (DEFAULT_NAME)
    , registrationWidget_ ()
  {
    registrationWidget_.Init ();
  }

  RegistrationScreen::~RegistrationScreen ()
  {
  }

  void RegistrationScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();

    guiManager_->AddChild (registrationWidget_);
  }

  void RegistrationScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    BaseScreen::HandleRun (dt, context);
  }

  bool RegistrationScreen::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Escape)
      {
        nextScreen_ = "MainMenu";
        return true;
      }

      return true;
    }
    return false;
  }
} // namespace ycl
