#ifndef YAPOG_STRINGHELPER_HPP
# define YAPOG_STRINGHELPER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/Array.hpp"

namespace yap
{
  class YAPOG_LIB StringHelper
  {
    DISALLOW_COPY(StringHelper);

  public:

    template <typename T>
    static String ToString (const T& value);

    template <typename T>
    static T Parse (const String& str);

    static void Split (
      const String& str,
      const String& delimiters,
      collection::Array<String>& result);

    template <typename T>
    static int CompareString (const T& s1, const T& s2);
    template <typename T>
    static String& Ltrim(T& s);
    template <typename T>
    static String& Rtrim(T& s);
    template <typename T>
    static String& Trim(T& s);
    template <typename T>
    static String Trim(const T& s);
    template <typename T>
    static String Rtrim(const T& s);
    template <typename T>
    static String Ltrim(const T& s);

  private:

    StringHelper ();
    ~StringHelper ();
  };
} // namespace yap

# include "YAPOG/System/StringHelper.hxx"

#endif // YAPOG_STRINGHELPER_HPP
