#ifndef YAPOG_GAMESCREEN_HPP
# define YAPOG_GAMESCREEN_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/IGameScreen.hpp"
# include "YAPOG/Graphics/Gui/IGuiManager.hpp"

namespace yap
{
  /// @brief A basic implementation of IGameScreen, a game phase.
  class GameScreen : public IGameScreen
  {
    public:

      /// @brief Initializes a GameScreen with the ScreenType @a type.
      /// @param type ScreenType of this GameScreen.
      GameScreen (const ScreenType& type);
      virtual ~GameScreen ();

      /// @name IGameScreen members.
      /// @{
      virtual void Init ();
      virtual void Activate ();
      virtual void Deactivate ();

      virtual const ScreenType& Run (const Time& dt, IDrawingContext& context);

      virtual const IGuiManager& GetGuiManager () const;
      virtual IGuiManager& GetGuiManager ();

      virtual const ScreenType& GetType () const;
      /// @}

      /// @name IEventHandler members.
      /// @{
      virtual bool OnEvent (const GuiEvent& guiEvent);
      /// @}

    protected:

      /// Type of the Screen to be executed on next frame.
      ScreenType nextScreen_;
      /// Root widget if this GameScreen.
      IGuiManager* guiManager_;

    private:

      /// @brief Behavior of Run.
      virtual const ScreenType& HandleRun (
        const Time& dt,
        IDrawingContext& context) = 0;
      /// @brief Behavior of Init.
      virtual void HandleInit () = 0;
      /// @brief Behavior of Activate.
      virtual void HandleActivate () = 0;
      /// @brief Behavior of Deactivate.
      virtual void HandleDeactivate () = 0;
      /// @brief Behavior of OnEvent.
      virtual bool HandleOnEvent (const GuiEvent& guiEvent) = 0;

      /// Type of this GameScreen.
      ScreenType type_;
  };
} // namespace yap

#endif // YAPOG_GAMESCREEN_HPP
