#ifndef YAPOG_CLIENT_POKEMONFIGHTER_HPP
# define YAPOG_CLIENT_POKEMONFIGHTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Game/Battle/PokemonFighter.hpp"

# include "Battle/IDrawableBattleEntity.hpp"

namespace yap
{
  struct ISprite;
} // namespace yap

namespace ycl
{
  class Pokemon;

  class PokemonFighter
    : public yap::PokemonFighter
    , public IDrawableBattleEntity
  {
    DISALLOW_COPY (PokemonFighter);

  public:
    PokemonFighter (Pokemon* originalPokemon, bool isOpponent);
    virtual ~PokemonFighter ();

    /// @name IDrawable members.
    /// @{
    virtual void Draw (yap::IDrawingContext& context);

    virtual bool IsVisible () const;
    virtual void Show (bool isVisible);

    virtual void ChangeColor (const sf::Color& color);
    /// @}

    /// @name IDrawableBattleEntity members
    /// @{
    virtual const yap::ISprite& GetBattleSprite () const;
    virtual yap::ISprite& GetBattleSprite ();
    virtual const yap::ISprite& GetIcon () const;
    virtual const yap::ISprite& GetGenderIcon () const;
    virtual const yap::ISprite& GetBattleBack () const;
    virtual const yap::ISprite& GetBattleFront () const;
    virtual const yap::ISprite& GetType1Icon () const;
    virtual const yap::ISprite& GetType2Icon () const;
    virtual void SetPosition (const yap::Vector2& value);
    virtual void PlayCry () const;
    /// @}

  protected:
    virtual void HandleInit ();
    virtual void HandleUpdate (const yap::Time& dt);
    virtual void HandleDraw (yap::IDrawingContext& context);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    static const bool DEFAULT_VISIBLE_STATE;
    static const sf::Color DEFAULT_COLOR;

    bool isVisible_;
    sf::Color color_;

  private:
    /// @name Private setters.
    /// @{
    void SetCurrentHP (int value);
    /// @}

    yap::ISprite* battleSprite_;
    bool isOpponent_;
    Pokemon* originalPokemon_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONFIGHTER_HPP