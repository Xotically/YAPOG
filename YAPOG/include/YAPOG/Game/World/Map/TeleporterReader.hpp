#ifndef YAPOG_TELEPORTERREADER_HPP
# define YAPOG_TELEPORTERREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/DynamicWorldObjectReader.hpp"

namespace yap
{
  class Teleporter;

  class YAPOG_LIB TeleporterReader : public DynamicWorldObjectReader
  {
      DISALLOW_COPY(TeleporterReader);

    public:

      virtual ~TeleporterReader ();

    protected:

      TeleporterReader (
        Teleporter& worldObject,
        const String& xmlRootNodeName);

    private:

      Teleporter& teleporter_;
  };
} // namespace yap

#endif // YAPOG_TELEPORTERREADER_HPP
