#ifndef YAPOG_CLIENT_OPTIONSCREEN_HPP
# define YAPOG_CLIENT_OPTIONSCREEN_HPP

# include "YAPOG/Macros.hpp"

# include "GameScreen/BaseScreen.hpp"

namespace ycl
{
  class OptionScreen : public BaseScreen
  {
      DISALLOW_COPY(OptionScreen);

    public:

      explicit OptionScreen (yap::IDrawingContext& context);
      virtual ~OptionScreen ();

    private:

      static const yap::ScreenType DEFAULT_NAME;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_OPTIONSCREEN_HPP
