#ifndef YAPOG_XMLREADER_HPP
# define YAPOG_XMLREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IOStream.hpp"
# include "YAPOG/System/IO/IReader.hpp"
# include "YAPOG/System/IO/Xml/XmlTree.hpp"

namespace yap
{
  class YAPOG_LIB XmlReader : public IReader
  {
      DISALLOW_COPY(XmlReader);

    public:

      XmlReader (IStream& iStream, const String& rootName);
      virtual ~XmlReader ();

      void ChangeRoot (const String& rootName);

      /// @name IReader members.
      /// @{
      virtual void Accept (IReaderVisitor& visitor);
      virtual void Accept (IReaderConstVisitor& visitor) const;

      virtual String ReadString ();
      virtual String ReadString (const String& name);

      virtual bool ReadBool ();
      virtual bool ReadBool (const String& name);

      virtual char ReadChar ();
      virtual char ReadChar (const String& name);

      virtual uchar ReadUChar ();
      virtual uchar ReadUChar (const String& name);

      virtual Int16 ReadInt16 ();
      virtual Int16 ReadInt16 (const String& name);

      virtual UInt16 ReadUInt16 ();
      virtual UInt16 ReadUInt16 (const String& name);

      virtual int ReadInt ();
      virtual int ReadInt (const String& name);

      virtual uint ReadUInt ();
      virtual uint ReadUInt (const String& name);

      virtual Int64 ReadInt64 ();
      virtual Int64 ReadInt64 (const String& name);

      virtual UInt64 ReadUInt64 ();
      virtual UInt64 ReadUInt64 (const String& name);

      virtual float ReadFloat ();
      virtual float ReadFloat (const String& name);

      virtual double ReadDouble ();
      virtual double ReadDouble (const String& name);

      virtual Vector2 ReadVector2 ();
      /// @todo Determine representation of Vector2 in XML.
      virtual Vector2 ReadVector2 (const String& name);
      /// @}

    private:

      XmlTree data_;
  };
} // namespace yap

#endif // YAPOG_XMLREADER_HPP