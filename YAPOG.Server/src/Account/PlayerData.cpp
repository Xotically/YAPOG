#include "YAPOG/System/MathHelper.hpp"

#include "Account/PlayerData.hpp"
#include "Database/Tables/PlayerDataTable.hpp"

namespace yse
{
  const yap::ID PlayerData::DEFAULT_ACCOUNT_ID (1);
  const yap::Vector2 PlayerData::DEFAULT_POSITION (0, 0);
  const yap::ID PlayerData::DEFAULT_MAP_ID (1);
  const yap::Vector2 PlayerData::DEFAULT_RESPAWN_SPOT (42, 42);
  const int PlayerData::DEFAULT_BOX_NUMBER = 1;
  const int PlayerData::DEFAULT_MONEY = 500;

  PlayerData::PlayerData ()
    : accountID_ (DEFAULT_ACCOUNT_ID)
    , position_ (DEFAULT_POSITION)
    , mapID_ (DEFAULT_MAP_ID)
    , playTime_ (0)
    , stepCount_ (0)
    , respawnSpot_ (DEFAULT_RESPAWN_SPOT)
    , fleeCount_ (0)
    , boxNumber_ (DEFAULT_BOX_NUMBER)
    , battleCount_ (0)
    , money_ (DEFAULT_MONEY)
  {
  }

  void PlayerData::LoadFromTable (const PlayerDataTable& at)
  {
    SetAccountID (at.GetAccountID ());
    SetPosition (at.GetPosition ());
    SetMapID (at.GetMapID ());
    SetPlayTime (yap::Time  (at.GetPlayTime ()));
    SetStepCount (at.GetStepCount ());
    SetRespawnSpot (at.GetRespawnSpot ());
    SetFleeCount (at.GetFleeCount ());
    SetBoxNumber (at.GetBoxNumber ());
    SetBattleCount (at.GetBattleCount ());
    SetMoney (at.GetMoney ());
  }

  void PlayerData::UpdatePlayTime (const yap::Time& dt)
  {
    playTime_ += dt;
  }

  void PlayerData::ChangeMoney (int value)
  {
     money_ = yap::MathHelper::Clamp (
      money_ + value, 
      static_cast<yap::UInt32>(0), 
      money_);
  }

  /// Getters
  const yap::ID& PlayerData::GetAccountID () const 
  { return accountID_; }
  const yap::Vector2& PlayerData::GetPosition () const 
  { return position_; }
  const yap::ID& PlayerData::GetMapID () const
  { return mapID_; }
  const yap::Time& PlayerData::GetPlayTime () const
  { return playTime_; }
  int PlayerData::GetStepCount () const
  { return stepCount_; }
  const yap::Vector2& PlayerData::GetRespawnSpot () const
  { return respawnSpot_; }
  int PlayerData::GetFleeCount () const
  { return fleeCount_; }
  int PlayerData::GetBoxNumber () const
  { return boxNumber_; }
  int PlayerData::GetBattleCount () const
  { return battleCount_; }
  yap::UInt32 PlayerData::GetMoney () const
  { return money_; }

  /// Setters
  void PlayerData::SetAccountID (const yap::ID& value)
  { accountID_ = value; }
  void PlayerData::SetPosition (const yap::Vector2& value)
  { position_ = value; }
  void PlayerData::SetMapID (const yap::ID& value)
  { mapID_ = value; }
  void PlayerData::SetPlayTime (const yap::Time& value)
  { playTime_ = value; }
  void PlayerData::SetStepCount (int value)
  { stepCount_ = value; }
  void PlayerData::SetRespawnSpot (const yap::Vector2& value)
  { respawnSpot_ = value; }
  void PlayerData::SetFleeCount (int value)
  { fleeCount_ = value; }
  void PlayerData::SetBoxNumber (int value)
  { boxNumber_ = value; }
  void PlayerData::SetBattleCount (int value)
  { battleCount_ = value; }
  void PlayerData::SetMoney (yap::UInt32 value)
  { money_ = value; }

} // namespace yse