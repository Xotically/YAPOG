#include "TestGame.hpp"
#include "YAPOG/Graphics/Game/GameScreenManager.hpp"
#include "YAPOG/Graphics/DrawingContext.hpp"
#include "YAPOG/Graphics/Camera.hpp"
#include "GameScreen/TestScreen.hpp"
#include "YAPOG/Graphics/Gui/GameInput/KeyboardGameInputEntry.hpp"
#include "YAPOG/Content/ContentManager.hpp"
#include "YAPOG/System/IO/Log/DebugLogger.hpp"
#include "YAPOG/System/IO/Log/CountLoggerMode.hpp"
#include "YAPOG/System/IO/Log/TimeLoggerMode.hpp"

TestGame::TestGame (const yap::String& name)
  : yap::Game (name)
{
}

TestGame::~TestGame ()
{
}

void TestGame::HandleInit ()
{
  yap::ContentManager::Instance ().Init (yap::Path ("../Content/"));

  yap::DebugLogger::Instance ().AddMode (new yap::CountLoggerMode ());
  yap::DebugLogger::Instance ().AddMode (new yap::TimeLoggerMode ());

  // initialization of the drawing context
  yap::DrawingContext* drawingContext = new yap::DrawingContext (
    yap::Vector2 (800, 600), name_);
  drawingContext_ = drawingContext;

  // add of the world camera to the drawing context
  drawingContext_->AddCamera (
    "World", new yap::Camera (yap::Vector2 (),  yap::Vector2 (800, 600)));
  drawingContext_->AddCamera (
    "Background World",
    new yap::Camera (yap::Vector2 (),  yap::Vector2 (800, 600)));

  // add of the GUI camera to the drawing context
  drawingContext_->AddCamera (
    "Gui", new yap::Camera (yap::Vector2 (), yap::Vector2 (800, 600)));

  window_ = &drawingContext->GetWindow ();

  // initialization of the screen manager
  screenManager_ = new yap::GameScreenManager ();
  // add of the screens
  screenManager_->AddGameScreen (new TestScreen ());
  // initialization of all the screens
  screenManager_->Init ("Test");
}

bool TestGame::HandleOnEvent (const yap::GuiEvent& guiEvent)
{
  switch (guiEvent.type)
  {
    case yap::GuiEventType::Closed:

      window_->close ();

      return true;

    case yap::GuiEventType::KeyPressed:

      switch (guiEvent.key.code)
      {
        case yap::Key::Escape:

          window_->close ();

          return true;

        default:
          break;
      }

      break;

    default:
      break;
  }

  return false;
}