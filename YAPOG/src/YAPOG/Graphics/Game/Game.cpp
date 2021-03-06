#include "YAPOG/Graphics/Game/Game.hpp"
#include "YAPOG/System/Time/Time.hpp"
#include "YAPOG/Graphics/Game/IGameScreenManager.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"
#include "YAPOG/Graphics/Gui/GuiEvent.hpp"

namespace yap
{
  Game::Game (const String& name)
    : drawingContext_ (nullptr)
    , window_ (nullptr)
    , name_ (name)
    , screenManager_ (nullptr)
    , isRunning_ (false)
    , timer_ ()
  {
  }

  Game::~Game ()
  {
    delete screenManager_;
    screenManager_ = nullptr;

    delete drawingContext_;
    drawingContext_ = nullptr;
  }

  void Game::Init ()
  {
    HandleInit ();
  }

  void Game::Launch ()
  {
    isRunning_ = true;

    while (isRunning_)
    {
      Time dt (timer_.GetCurrentTime ());
      timer_.Reset ();

      screenManager_->NextFrame ();

      GuiEvent guiEvent;

      GameInputManager::Instance ().BeginUpdate ();

      while (window_->pollEvent (guiEvent))
      {
        GameInputManager::Instance ().Update (guiEvent);

        if (screenManager_->OnPriorityEvent (guiEvent))
          continue;

        if (screenManager_->OnEvent (guiEvent))
          continue;

        HandleOnEvent (guiEvent);
      }

      GameInputManager::Instance ().EndUpdate ();

      window_->clear (drawingContext_->GetTargetClearColor ());

      HandleRun (dt, *drawingContext_);

      isRunning_ &= window_->isOpen ();

      window_->display ();
    }

    Dispose ();
  }

  void Game::Dispose ()
  {
    HandleDispose ();
  }

  void Game::Stop ()
  {
    isRunning_ = false;
  }

  IGameScreenManager& Game::GetScreenManager ()
  {
    return *screenManager_;
  }

  void Game::SetScreenManager (IGameScreenManager* screenManager)
  {
    screenManager_ = screenManager;

    GetScreenManager ().OnGameExitedEvent () += [this] (
      IGameScreenManager& sender,
      const EmptyEventArgs& args)
    {
      Stop ();
    };
  }

  void Game::HandleRun (const Time& dt, IDrawingContext& context)
  {
    screenManager_->Run (dt, context);
  }

  bool Game::HandleOnEvent (const GuiEvent& guiEvent)
  {
    switch (guiEvent.type)
    {
      case sf::Event::Resized:

        drawingContext_->ChangeSize (
          Vector2 (
            guiEvent.size.width,
            guiEvent.size.height));

        break;

      default: break;
    }

    return false;
  }

  void Game::HandleDispose ()
  {
  }
} // namespace yap
