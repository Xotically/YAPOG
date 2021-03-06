#ifndef YAPOG_EXPERIENCEERRATIC_HPP
# define YAPOG_EXPERIENCEERRATIC_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/PokemonExperience.hpp"

namespace yap
{
  class YAPOG_LIB ExperienceErratic : public PokemonExperience
  {
    DISALLOW_COPY (ExperienceErratic);

  public:
    ExperienceErratic ();

  private:
    virtual UInt32 ComputeExperienceFromLevel (const UInt16& level) const;
  };
} // namespace yap

#endif // YAPOG_EXPERIENCEERRATIC_HPP
