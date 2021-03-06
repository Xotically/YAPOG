#ifndef YAPOG_CLIENT_CREDITSCREEN_HPP
# define YAPOG_CLIENT_CREDITSCREEN_HPP

# include "YAPOG/Macros.hpp"

# include "GameScreen/BaseScreen.hpp"

namespace ycl
{
  class CreditScreen : public BaseScreen
  {
      DISALLOW_COPY(CreditScreen);

    public:

      explicit CreditScreen (yap::IDrawingContext& context);
      virtual ~CreditScreen ();

    protected:

      virtual void HandleRun (
        const yap::Time& dt,
        yap::IDrawingContext& context);

    private:

      static const yap::ScreenType DEFAULT_NAME;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_CREDITSCREEN_HPP
