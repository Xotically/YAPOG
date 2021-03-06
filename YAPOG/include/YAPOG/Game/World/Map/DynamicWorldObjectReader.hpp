#ifndef YAPOG_DYNAMICWORLDOBJECTREADER_HPP
# define YAPOG_DYNAMICWORLDOBJECTREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/WorldObjectReader.hpp"

namespace yap
{
  class DynamicWorldObject;

  class YAPOG_LIB DynamicWorldObjectReader : public WorldObjectReader
  {
      DISALLOW_COPY(DynamicWorldObjectReader);

    public:

      virtual ~DynamicWorldObjectReader ();

      virtual void Visit (XmlReader& visitable);

    protected:

      DynamicWorldObjectReader (
        DynamicWorldObject& dynamicWorldObject,
        const String& xmlRootNodeName);

    private:

      static const String DEFAULT_XML_MAX_VELOCITY_NODE_NAME;

      DynamicWorldObject& dynamicWorldObject_;
  };
} // namespace yap

#endif // YAPOG_DYNAMICWORLDOBJECTREADER_HPP
