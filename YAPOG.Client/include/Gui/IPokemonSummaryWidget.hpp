#ifndef YAPOG_CLIENT_POKEMONSUMMARYWIDGET_HPP
# define YAPOG_CLIENT_POKEMONSUMMARYWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

# include "Pokemon/Pokemon.hpp"

namespace ycl
{
  struct IPokemonSummaryWidget : public yap::BaseWidget
  {
  public:
    virtual ~IPokemonSummaryWidget() {}

    virtual void Init () = 0;

    virtual void SetPokemon (const Pokemon& pokemon) = 0;
  };
} // namespace yap

#endif /* YAPOG_CLIENT_POKEMONSUMMARYWIDGET_HPP! */