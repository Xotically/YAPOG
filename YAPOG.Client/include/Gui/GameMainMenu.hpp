#ifndef YAPOG_CLIENT_GAMEMAINMENU_HPP
# define YAPOG_CLIENT_GAMEMAINMENU_hpp

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Menu.hpp"

namespace ycl
{
  class GameMainMenu : public yap::Menu
  {
      DISALLOW_COPY(GameMainMenu);

    public:
      GameMainMenu();
      virtual ~GameMainMenu ();

      void Init (yap::String playerName);
      
  };
} // namespace ycl

#endif // YAPOG_CLIENT_GAMEMAINMENU_HPP