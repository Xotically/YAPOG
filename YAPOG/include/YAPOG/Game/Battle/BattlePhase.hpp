#ifndef YAPOG_BATTLEPHASE_HPP
# define YAPOG_BATTLEPHASE_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class YAPOG_LIB BattlePhase
  {
  public:
    BattlePhase ();

    virtual void Update ();
  };
} // namespace yap

#endif // YAPOG_BATTLEPHASE_HPP
