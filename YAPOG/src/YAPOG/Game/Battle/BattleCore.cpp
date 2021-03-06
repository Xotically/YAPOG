#include "YAPOG/Game/Battle/BattleCore.hpp"
#include "YAPOG/System/RandomHelper.hpp"
#include "YAPOG/Game/Battle/IBattleEntity.hpp"

namespace yap
{
  BattleCore::BattleCore ()
  {
  }

  int BattleCore::ComputeDamage (
    const PokemonMove& move, 
    const IBattleEntity& attacker, 
    const IBattleEntity& defender) const
  {
    float stab = 1.f;

    if (move.GetType () == attacker.GetType1 () 
      || move.GetType () == attacker.GetType1 ())
      stab = 1.5f;

    float type = defender.GetTypeEffectFactor (move.GetType ());
    float critical = 1.f;

    if (RandomHelper::Percentage (6.25f))
      critical = 2.f;

    float other = 1.f;
    float rand = RandomHelper::GetNext (0.85f, 1.0f);
    float modifier = stab * type * critical * other * rand;
    float levelFactor = (2 * attacker.GetLevel () + 10) / 250.f;
    float atkOverDef = 1.f;

    if (move.GetCategory () == 1)
    {
      if (defender.GetDefense ().GetValue () != 0)
      {
        atkOverDef = 
          attacker.GetAttack ().GetValue () / 
          defender.GetDefense ().GetValue ();
      }
    }
    else
    {
      if (defender.GetSpecialDefense ().GetValue () != 0)
      {
        atkOverDef = 
          attacker.GetSpecialAttack ().GetValue () / 
          defender.GetSpecialDefense ().GetValue ();
      }
    }

    float base = move.GetPower ();

    float damage = levelFactor * atkOverDef * base + 2;
    damage *= modifier;

    return damage;
  }

  UInt32 BattleCore::ComputeExperienceGain () const
  {
    /// @todo Compute experience amount
    return 4242;
  }

} // namespace yap