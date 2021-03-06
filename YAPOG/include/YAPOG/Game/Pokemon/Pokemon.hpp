#ifndef YAPOG_POKEMON_HPP
# define YAPOG_POKEMON_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"
# include "YAPOG/Game/Pokemon/PokemonStatus.hpp"
# include "YAPOG/Game/Pokemon/PokemonStat.hpp"
# include "YAPOG/Game/Pokemon/PokemonType.hpp"
# include "YAPOG/Game/Pokemon/PokemonMoveSet.hpp"
# include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
# include "YAPOG/Game/Pokemon/PokemonExperience.hpp"
# include "YAPOG/Game/Pokemon/NatureInfo.hpp"
# include "YAPOG/System/Path.hpp"

namespace yap
{
  class YAPOG_LIB Pokemon
  {
    DISALLOW_COPY (Pokemon);

  public:
    Pokemon (const ID& staticID);

    Pokemon (
      const ID& staticID, 
      const UInt16& level, 
      const bool& shiny);

    Pokemon (
      const ID& uniqueID,
      const ID& staticID,
      const String& trainerName,
      const String& nickname,
      const PokemonStat& stats,
      const Gender& gender,
      const PokemonStatus& status,
      const bool shiny,
      const Int16& loyalty,
      const PokemonMoveSet& moveSet,
      const ID& natureID,
      const uint& exp,
      const UInt8& boxNumber,
      const ID& boxIndex,
      const String& catchDate);

    Pokemon (
      const ID& staticID,
      const PokemonStat& stats,
      const Gender& gender,
      const bool shiny,
      const PokemonMoveSet& moveSet,
      const ID& natureID,
      const uint& exp);

    /// Getters
    const ID& GetUniqueID () const;
    const ID& GetStaticID () const;
    const String& GetTrainerName () const;
    const String& GetName () const;
    const String& GetNickname () const;
    const TypeInfo& GetType1 () const;
    const TypeInfo& GetType2 () const;
    float GetTypeEffectFactor (const TypeInfo& type) const;
    const PokemonExperience& GetExperience () const;
    UInt32 GetTotalExperience () const;
    UInt32 GetExperienceToNextLevel () const;
    UInt32 GetTotalExperienceToNextLevel () const;
    float GetExperiencePercentage () const;
    UInt16 GetLevel () const;
    bool GetShiny () const;
    Int16 GetLoyalty () const;
    const yap::NatureInfo& GetNature () const;
    const yap::ID& GetNatureID () const;
    const PokemonStat& GetStats () const;
    const Gender& GetGender () const;
    const PokemonStatus& GetStatus () const;
    const yap::UInt8& GetBoxNumber () const;
    const yap::ID& GetBoxIndex () const;
    const yap::String& GetCatchDate () const;
    UInt16 GetCurrentHP () const;
    UInt16 GetMaxHP () const;
    const PokemonMoveSet& GetMoveSet () const;
    const String& GetIconPath () const;

    ///

    bool LearnMove (const ID& moveID);
    void ReplaceMove (const ID& moveID, UInt8 index);

    /// @brief Restore all the hp of the Pokemon
    void RestoreHP ();
    void SetCurrentHP (int value);

    void AddExperience (const Int32& value);

    static const uchar MAX_POKEMON_MOVE_NUMBER;
    static const ID DEFAULT_NATURE_ID;
    static const UInt32 DEFAULT_EXPERIENCE_AMOUNT;

  protected:
    ID uniqueID_;
    ID staticID_;
    String trainerName_;
    String nickname_;
    PokemonStat stats_;
    PokemonType type_;
    Gender gender_;
    PokemonStatus status_;
    bool shiny_;
    Int16 loyalty_;
    PokemonMoveSet moveSet_;
    PokemonInfo* pokemonInfo_;
    NatureInfo* nature_;
    PokemonExperience* exp_;
    UInt8 boxNumber_;
    ID boxIndex_;
    String catchDate_;

  private:
    void InitExperience ();
    void InitMoveSet ();
    void Evolve ();
    void SpecifyGender ();
  };
} // namespace yap

#endif // YAPOG_POKEMON_HPP

