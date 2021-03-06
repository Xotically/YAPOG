#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Audio/AudioManager.hpp"

#include "Gui/GameMainMenu.hpp"

namespace ycl
{
  const yap::Menu::Type GameMainMenu::DEFAULT_ALIGNMENT =
    yap::Menu::Type::VERTICAL;
  const yap::Padding GameMainMenu::DEFAULT_PADDING = yap::Padding (5, 5, 5, 5);

  const sf::Color GameMainMenu::DEFAULT_ITEM_COLOR = sf::Color (127, 127, 127);
  const yap::LayoutBox::Align GameMainMenu::DEFAULT_ITEM_ALIGNMENT =
    yap::LayoutBox::Align::LEFT;

  GameMainMenu::GameMainMenu ()
    : GameMenu (
    DEFAULT_ALIGNMENT,
    DEFAULT_PADDING,
    DEFAULT_PADDING,
    false)
  {
  }

  void GameMainMenu::Init (const yap::String& playerName)
  {
    yap::WidgetBackground* menuBck =
      new yap::WidgetBackground ("Test/white.png", true);

    yap::Texture* ti = new yap::Texture ();
    yap::Texture* tri = new yap::Texture ();
    yap::Texture* ri = new yap::Texture ();
    yap::Texture* bri = new yap::Texture ();
    yap::Texture* bi = new yap::Texture ();
    yap::Texture* bli = new yap::Texture ();
    yap::Texture* li = new yap::Texture ();
    li->LoadFromFile ("WindowSkins/BasicSkin/Global/Cursor.png");
    yap::Texture* tli = new yap::Texture ();
    yap::WidgetBorder* menuItemBrd =
      new yap::WidgetBorder (
      *ti, *tri, *ri, *bri, *bi, *bli, *li, *tli, false);

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

    yap::WidgetBorder* menuBorder =
      new yap::WidgetBorder (*t, *tr, *r, *br, *b, *bl, *l, *tl, true);

    SetSelectedBorder (*menuItemBrd);

    yap::MenuItem& pokedexItem = AddItem ("POK�DEX");
    pokedexItem.OnActivated += [this] (
      yap::MenuItem& sender,
      const yap::EmptyEventArgs& args)
    {
      OnPokedexItemActivated (*this, yap::EmptyEventArgs ());
    };

    yap::MenuItem& pokemonItem = AddItem ("POK�MON");
    pokemonItem.OnActivated += [this] (
      yap::MenuItem& sender,
      const yap::EmptyEventArgs& args)
    {
      OnPokemonItemActivated (*this, yap::EmptyEventArgs ());
    };
    
    /// @todo Add a Bag entry in the main menu
    //yap::MenuItem& bagItem = AddItem ("SAC");

    yap::MenuItem& playerItem = AddItem (playerName);
    playerItem.OnActivated += [this] (
      yap::MenuItem& sender,
      const yap::EmptyEventArgs& args)
    {
      OnTrainerCardItemActivated (*this, yap::EmptyEventArgs ());
    };

    yap::MenuItem& optionItem = AddItem ("OPTIONS");
    optionItem.OnActivated += [this] (
      yap::MenuItem& sender,
      const yap::EmptyEventArgs& args)
    {
      OnOptionItemActivated (*this, yap::EmptyEventArgs ());
    };

    yap::MenuItem& exitItem = AddItem ("RETOUR");
    exitItem.OnActivated += [this] (
      yap::MenuItem& sender,
      const yap::EmptyEventArgs& args)
    {
      Close ();
      yap::AudioManager::Instance ().ResumePreviousMusic ();
    };

    SetBackground (*menuBck);
    SetBorder (*menuBorder);
  }

  GameMainMenu::~GameMainMenu ()
  {
  }

  yap::MenuItem& GameMainMenu::AddItem (const yap::String& itemName)
  {
    yap::MenuItem* item = new yap::MenuItem (true);
    item->SetContent (itemName);

    item->ChangeColor (DEFAULT_ITEM_COLOR);

    AddChild (*item, DEFAULT_ITEM_ALIGNMENT);

    return *item;
  }
} // namespace ycl
