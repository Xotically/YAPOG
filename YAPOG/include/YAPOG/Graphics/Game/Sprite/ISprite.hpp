#ifndef YAPOG_ISPRITE_HPP
# define YAPOG_ISPRITE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Game/IUpdateable.hpp"

namespace yap
{
  /// @brief Interface for a static or dynamic graphical element of the game.
  struct ISprite :
      public IDrawable,
      public IUpdateable
  {
      virtual ~ISprite () {}
  };
} // namespace yap

#endif // YAPOG_ISPRITE_HPP