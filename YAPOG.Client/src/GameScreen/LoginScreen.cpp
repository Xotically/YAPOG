#include "YAPOG/System/IOStream.hpp"
#include "YAPOG/Graphics/Gui/Label.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/LayoutH.hpp"
#include "YAPOG/Graphics/Gui/LayoutV.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/Menu.hpp"
#include "YAPOG/Graphics/Gui/MenuItem.hpp"
#include "YAPOG/Graphics/Gui/WidgetTextBox.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"

#include "GameScreen/LoginScreen.hpp"
#include "Client/Session.hpp"

namespace ycl
{
  const yap::ScreenType LoginScreen::DEFAULT_NAME = "Login";

  LoginScreen::LoginScreen ()
    : BaseScreen (DEFAULT_NAME)
  {
  }

  LoginScreen::~LoginScreen ()
  {
  }

  void LoginScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();

    yap::Menu* menu = new yap::Menu (
      yap::Menu::Type::HORIZONTAL,
      yap::Padding (1, 1, 1, 1),
      yap::Padding (5, 5, 5, 5),
      false);

    menu->SetSize (yap::Vector2 (400, 88));
    yap::MenuItem* item1 = new yap::MenuItem ();
    yap::MenuItem* item2 = new yap::MenuItem ();
    yap::MenuItem* item3 = new yap::MenuItem ();

    item1->SetSize (yap::Vector2 (88, 64));
    item2->SetSize (yap::Vector2 (88, 64));
    item3->SetSize (yap::Vector2 (88, 64));

    item1->SetContent ("Item 1");
    item2->SetContent ("Item 2");
    item3->SetContent ("Item 3");

    item1->ChangeColor (sf::Color (128, 64, 32));
    item2->ChangeColor (sf::Color (128, 64, 32));
    item3->ChangeColor (sf::Color (128, 64, 32));

    menu->AddChild (*item1, yap::LayoutBox::Align::LEFT);
    menu->AddChild (*item2, yap::LayoutBox::Align::LEFT);
    menu->AddChild (*item3, yap::LayoutBox::Align::LEFT);

    yap::LayoutV* layout = new yap::LayoutV (
      yap::Padding (2, 2, 2, 2),
      yap::Padding (9, 9 , 9, 9), false);

    yap::WidgetBackground* bckgrd4 = new yap::WidgetBackground ("bckgrd4.png", true);
    layout->SetBackground (*bckgrd4);

    layout->SetSize (yap::Vector2 (1024, 768));

    yap::WidgetTextBox* label = new yap::WidgetTextBox ();
    label->SetText ("Ceci est un label.");
    label->SetSize (yap::Vector2 (100, 32));
    label->ChangeColor (sf::Color (255, 0, 128));

    yap::PictureBox* pb = new yap::PictureBox ();
    pb->SetPicture (yap::String("jarri_j.png"));
    pb->Scale (yap::Vector2 (1, 1));

    yap::WidgetBorder* border = new yap::WidgetBorder ("heart.gif");
    pb->SetBorder (*border, 16);

    yap::LayoutH* layouth = new yap::LayoutH (
      yap::Padding (20, 20, 20, 20),
      yap::Padding (9, 9 , 9, 9), true);

    yap::WidgetBackground* bckgr5 =
      new yap::WidgetBackground (
        "bckgrd5.png",
        true);

    yap::WidgetTextBox* ts = new yap::WidgetTextBox ("Element1");
    ts->SetSize (yap::Vector2 (100, 32));
    yap::WidgetTextBox* ts3 = new yap::WidgetTextBox ("Element2");
    ts3->SetSize (yap::Vector2 (100, 32));
    yap::WidgetBackground* bckgr = new yap::WidgetBackground (
      "bckgrd3.png",
      false);

    ts->SetBackground (*bckgr);

    layouth->AddChild (*ts, yap::LayoutBox::Align::TOP);
    layouth->AddChild (*ts3, yap::LayoutBox::Align::TOP);

    layouth->SetBackground (*bckgr5);

    yap::WidgetTextBox* ts2 = new yap::WidgetTextBox ("Last Element");
    ts2->SetSize (yap::Vector2 (100, 32));
    layout->AddChild (*label, yap::LayoutBox::Align::CENTER);
    layout->AddChild (*pb, yap::LayoutBox::Align::CENTER);
    layout->AddChild (*layouth, yap::LayoutBox::Align::CENTER);
    layout->AddChild (*ts2, yap::LayoutBox::Align::CENTER);
    layout->AddChild (*menu, yap::LayoutBox::Align::CENTER);

    yap::WidgetTextBox* txtbox = new yap::WidgetTextBox ();
    txtbox->SetSize (yap::Vector2 (256, 64));
    yap::Texture* cursor = new yap::Texture ();
    cursor->LoadFromFile ("cursor.png");
    txtbox->SetCursor (*cursor);
    yap::WidgetBackground* bckgrd = new yap::WidgetBackground (
      "bckgrd.png",
      true);
    txtbox->SetBackground (*bckgrd);

    //yap::widgetbackground* bckgr = new widgetbackground ();
    //bckgr->setbackground ("jarri_j.jpg", 1024, 512, false);


    guiManager_->AddChild (*layout);
    guiManager_->AddChild (*txtbox);

    // guiManager_->AddChild (*bckgr);
  }

  const yap::ScreenType& LoginScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
//    Login ();

    return BaseScreen::HandleRun (dt, context);
  }

  //!\\ tmp
  void LoginScreen::Login ()
  {
    yap::String login;

    std::cout << "Enter a login: ";
    std::cin >> login;

    session_.Login (login);

    nextScreen_ = "Gameplay";
  }
} // namespace ycl