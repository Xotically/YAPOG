#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/GridMenu.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Audio/AudioManager.hpp"

#include "Gui/PokemonTeamWidget.hpp"
#include "Gui/PokemonInfoBox.hpp"

#include "Pokemon/PokemonTeam.hpp"

namespace ycl
{
  PokemonTeamWidget::PokemonTeamWidget (const PokemonTeam& team)
    : state_ (nullptr)
    , menu_ (nullptr)
    , team_ (team)
    , pokemonInfoBoxes_ ()
    , index_ (0)
    , pokemonInfoWidget_ ()
  {
    state_ = new yap::Label ();

    for (int i = 0; i < team_.GetPokemonCount (); i++)
    {
      PokemonInfoBox* box = nullptr;

      if (i == 0)
        box = new PokemonInfoBox (team_.GetPokemon (i), true);
      else
        box = new PokemonInfoBox (team_.GetPokemon (i), false);

      pokemonInfoBoxes_.Add (box);
    }
  }

  PokemonTeamWidget::~PokemonTeamWidget ()
  {
  }

  void PokemonTeamWidget::Init ()
  {
    SetBackground (*new yap::WidgetBackground (
      "Pictures/TeamManager/Partyfond.png", true));

    // State
    state_->SetText ("Choisir un POK�MON.");
    state_->SetSize (yap::Vector2 (250, 64));

    yap::Texture* t = new yap::Texture ();
    t->LoadFromFile ("WindowSkins/BasicSkin/Global/TopBorder.png");
    yap::Texture* tr = new yap::Texture ();
    tr->LoadFromFile ("WindowSkins/BasicSkin/Global/TopRightCorner.png");
    yap::Texture* r = new yap::Texture ();
    r->LoadFromFile ("WindowSkins/BasicSkin/Global/RightBorder.png");
    yap::Texture* br = new yap::Texture ();
    br->LoadFromFile  ("WindowSkins/BasicSkin/Global/BottomRightCorner.png");
    yap::Texture* b = new yap::Texture ();
    b->LoadFromFile ("WindowSkins/BasicSkin/Global/BottomBorder.png");
    yap::Texture* bl = new yap::Texture ();
    bl->LoadFromFile ("WindowSkins/BasicSkin/Global/BottomLeftCorner.png");
    yap::Texture* l = new yap::Texture ();
    l->LoadFromFile ("WindowSkins/BasicSkin/Global/LeftBorder.png");
    yap::Texture* tl = new yap::Texture ();
    tl->LoadFromFile ("WindowSkins/BasicSkin/Global/TopLeftCorner.png");

    yap::WidgetBorder* stateBorder =
      new yap::WidgetBorder (*t, *tr, *r, *br, *b, *bl, *l, *tl, true);

    state_->SetBackground (*new yap::WidgetBackground ("Test/White.png", true));
    state_->SetPadding (yap::Padding (32, 0, 5, 32));

    state_->SetPosition (GetSize () - state_->GetSize () - 
      yap::Vector2 (15, 15));
    state_->SetBorder (*stateBorder);

    AddChild (*state_);

    // Pokemon info boxes
    for (yap::uint i = 0; i < pokemonInfoBoxes_.Count (); i++)
    {
      pokemonInfoBoxes_[i]->Init ();

      if (i == 0)
      {
        pokemonInfoBoxes_[i]->SetPosition (
          GetPosition () + yap::Vector2 (39, 101));
      }
      else
      {
        pokemonInfoBoxes_[i]->SetPosition (GetPosition () + 
          yap::Vector2 (364, 41 + 90 * (i - 1)));
      }

      AddChild (*pokemonInfoBoxes_[i]);
    }

    pokemonInfoBoxes_[index_]->SetIsSelected (true);

    // Pokemon info widget (summary)
    AddChild (pokemonInfoWidget_);

    pokemonInfoWidget_.Init ();
    pokemonInfoWidget_.Close ();
  }

  bool PokemonTeamWidget::IsFocusable () const
  {
    return true;
  }

  bool PokemonTeamWidget::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (pokemonInfoBoxes_.Count () == 0)
      return false;

    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Up)
      {
        // Play a sound
        yap::AudioManager::Instance ().PlaySound ("SE/Select.wav");

        pokemonInfoBoxes_[index_]->SetIsSelected (false);

        if (index_ == 0)
          index_ = pokemonInfoBoxes_.Count () - 1;
        else
          index_--;

        if (pokemonInfoWidget_.IsVisible ())
        {
          pokemonInfoWidget_.Close ();
          team_.GetPokemon (index_).PlayCry ();
          pokemonInfoWidget_.SetPokemon (team_.GetPokemon (index_));
          pokemonInfoWidget_.Open ();
        }

        pokemonInfoBoxes_[index_]->SetIsSelected (true);

        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Down)
      {
        // Play a sound
        yap::AudioManager::Instance ().PlaySound ("SE/Select.wav");

        pokemonInfoBoxes_[index_]->SetIsSelected (false);

        index_ = (index_ + 1) % pokemonInfoBoxes_.Count ();

        if (pokemonInfoWidget_.IsVisible ())
        {
          pokemonInfoWidget_.Close ();
          team_.GetPokemon (index_).PlayCry ();
          pokemonInfoWidget_.SetPokemon (team_.GetPokemon (index_));
          pokemonInfoWidget_.Open ();
        }

        pokemonInfoBoxes_[index_]->SetIsSelected (true);

        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Left)
      {
        // Play a sound
        yap::AudioManager::Instance ().PlaySound ("SE/Select.wav");

        if (index_ != 0)
        {
          pokemonInfoBoxes_[index_]->SetIsSelected (false);
          index_ = 0;
          pokemonInfoBoxes_[index_]->SetIsSelected (true);
        }

        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Right)
      {
        // Play a sound
        yap::AudioManager::Instance ().PlaySound ("SE/Select.wav");

        if (index_ == 0)
        {
          pokemonInfoBoxes_[index_]->SetIsSelected (false);
          index_++;
          pokemonInfoBoxes_[index_]->SetIsSelected (true);
        }

        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Return)
      {
        // Play a sound
        yap::AudioManager::Instance ().PlaySound ("SE/Choose.wav");
        team_.GetPokemon (index_).PlayCry ();
        pokemonInfoWidget_.SetPokemon (team_.GetPokemon (index_));
        pokemonInfoWidget_.Open ();

        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Escape)
      {
        Close ();

        return true;
      }
    }

    return false;
  }

  yap::Vector2 PokemonTeamWidget::HandleGetSize () const
  {
    return yap::Vector2 (800, 600);
  }

 void PokemonTeamWidget::HandleOpen ()
  {
    RefreshWidget ();
  }

  void PokemonTeamWidget::RefreshWidget ()
  {
    // Refresh Pokemon info boxes
    for (yap::uint i = 0; i < pokemonInfoBoxes_.Count (); i++)
      pokemonInfoBoxes_[i]->RefreshWidget ();
  }

} // namespace ycl
