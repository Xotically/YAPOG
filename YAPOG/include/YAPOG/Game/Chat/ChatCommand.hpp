#ifndef YAPOG_CHATCOMMAND_HPP
# define YAPOG_CHATCOMMAND_HPP

# include <iostream>
# include <sstream>
# include "YAPOG/Game/Chat/ChatHeader.hpp"
# include "YAPOG/Game/Chat/ChatManager.hpp"
# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/StringHelper.hpp"

# define NBCMDS 3
# define NBCMDSLOC 4
# define NBTOTCMDS (NBCMDS + NBCMDSLOC)

namespace yap
{
  class Chat;
  class ChatDisplayer;
  typedef BufferType         (ChatCommand::*funcloc) (UInt32* channb,
    BufferType* b,
    ChatManager* cm,
    ChatDisplayer* cd);

  class YAPOG_LIB ChatCommand
  {
    DISALLOW_COPY(ChatCommand);
  public:
    typedef struct MyCmd
    {
      String  PtrString;
      func    PtrFunc;
      funcloc PtrFuncloc;
    } MyCmdType;
    ChatCommand ();
    ~ChatCommand ();

    // Commands
    // With request
    DisplayType				 	Trade (BufferType b);
    DisplayType					Echo (BufferType b);
    // Without request
    DisplayType					Help (BufferType b);
    DisplayType         SwitchTab (BufferType b);
    DisplayType         SwitchChan (BufferType b);
    DisplayType         AddChan (BufferType b);
    DisplayType         RmChan (BufferType b);
    DisplayType					Unknown (BufferType b);

    // Set the command
    void								SetCommand (func cmd);
    // Get the command
    func								GetCmd (const char *pString);
    // Execute the command
    ResponseType  			ExecCmd (ChatManagerType* cm);

  private:
    BufferType          SwitchTab (
      UInt32* channb,
      BufferType* b,
      ChatManagerType* cm,
      ChatDisplayer* cd);

    BufferType          SwitchChan 
      (UInt32* channb,
      BufferType* b,
      ChatManagerType* cm,
      ChatDisplayer* cd);

    BufferType          AddChan (
      UInt32* channb,
      BufferType* b,
      ChatManagerType* cm,
      ChatDisplayer* cd);

    BufferType          RmChan (
      UInt32* channb,
      BufferType* b,
      ChatManagerType* cm,
      ChatDisplayer* cd);

    MyCmdType*          tab_;
    func                command_;
  };
} // namespace yap

#endif // YAPOG_CHATCOMMAND_HPP