#include "YAPOG/Graphics/Gui/GameInput/KeyboardGameInputEntry.hpp"

namespace yap
{
  KeyboardGameInputEntry::KeyboardGameInputEntry (Key key)
    : GameInputEntry ()
    , key_ (key)
  {
  }

  KeyboardGameInputEntry::~KeyboardGameInputEntry ()
  {
  }

  void KeyboardGameInputEntry::Update (const GuiEvent& guiEvent)
  {
    switch (guiEvent.type)
    {
      case GuiEventType::KeyPressed:

        if (key_ != guiEvent.key.code)
          break;

        Activate (true);

        break;

      case GuiEventType::KeyReleased:

        if (key_ != guiEvent.key.code)
          break;

        Activate (false);

        break;

      default:
        break;
    }
  }

  bool KeyboardGameInputEntry::GuiEventIsCompatible (
    const GuiEvent& guiEvent) const
  {
    return
      (guiEvent.type == GuiEventType::KeyPressed ||
       guiEvent.type == GuiEventType::KeyReleased) &&
      guiEvent.key.code == key_;
  }
} // namespace yap
