#ifndef YAPOG_IREADERVISITOR_HPP
# define YAPOG_IREADERVISITOR_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class XmlReader;

  struct YAPOG_LIB IReaderVisitor
  {
      virtual ~IReaderVisitor () {}

      virtual void Visit (XmlReader& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_IREADERVISITOR_HPP