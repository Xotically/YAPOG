#ifndef YAPOG_CLIENT_PLAYERTRAINER_HPP
# define YAPOG_CLIENT_PLAYERTRAINER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/Battle/PlayerTrainer.hpp"

namespace yap
{
  class Pokedex;
}

namespace ycl
{
  class BattleInterface;
  //class PokemonFighterTeam;
  class PokemonTeam;

  class PlayerTrainer : public yap::PlayerTrainer
  {
  public:
    PlayerTrainer ();
    virtual ~PlayerTrainer ();

    /// @name Getters.
    /// @{
    //PokemonFighterTeam& GetTeam ();
    PokemonTeam& GetTeam ();
    yap::UInt32 GetPokemonCaughtCount () const;
    /// @}

    /// @name Setters.
    /// @{
    //void SetTeam (PokemonFighterTeam* value);
    void SetTeam (PokemonTeam* value);
    void SetPokedex (yap::Pokedex* value);

    /// @}

    //PokemonFighterTeam* team_;
    PokemonTeam* team_;
    yap::Pokedex* pokedex_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_PLAYERTRAINER_HPP
