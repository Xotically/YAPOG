#ifndef YAPOG_CLIENT_LOGINSCREEN_HPP
# define YAPOG_CLIENT_LOGINSCREEN_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
# include "YAPOG/Graphics/Gui/TextBoxWidget.hpp"

# include "Gui/LoginWidget.hpp"
# include "GameScreen/BaseScreen.hpp"

namespace ycl
{
  class LoginScreen : public BaseScreen
  {
      DISALLOW_COPY(LoginScreen);

    public:

      explicit LoginScreen (yap::IDrawingContext& context);
      virtual ~LoginScreen ();

    protected:

      virtual void HandleInit ();
      virtual bool HandleOnPriorityEvent (const yap::GuiEvent& guiEvent);

      virtual void HandleRun (
        const yap::Time& dt,
        yap::IDrawingContext& context);

      virtual void HandleDeactivate ();

    private:

      LoginWidget loginWidget_;

      static const yap::ScreenType DEFAULT_NAME;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_LOGINSCREEN_HPP
