#ifndef YAPOG_BASEMAPEVENTACTION_HPP
# define YAPOG_BASEMAPEVENTACTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/IMapEventAction.hpp"
# include "YAPOG/Game/World/Map/MapEventActionType.hpp"

namespace yap
{
  class YAPOG_LIB BaseMapEventAction : public IMapEventAction
  {
      DISALLOW_ASSIGN(BaseMapEventAction);

    public:

      virtual ~BaseMapEventAction ();

      /// @name IMapEventAction members.
      /// @{
      virtual bool Execute (DynamicWorldObject& trigger, MapEventArgs& args);

      virtual const MapEventActionType& GetType () const;
      /// @}

      /// @name IDynamicWorldObjectVisitor
      /// @{
      virtual void VisitCharacter (Character& visitable);
      virtual void VisitPlayer (IPlayer& visitable);
      /// @}

    protected:

      explicit BaseMapEventAction (MapEventActionType type);

      BaseMapEventAction (const BaseMapEventAction& copy);

    private:

      virtual bool HandleExecute (MapEventArgs& args);

      MapEventActionType type_;
  };
} // namespace yap

#endif // YAPOG_BASEMAPEVENTACTION_HPP