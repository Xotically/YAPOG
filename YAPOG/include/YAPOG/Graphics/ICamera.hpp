#ifndef YAPOG_ICAMERA_HPP
# define YAPOG_ICAMERA_HPP

# include <SFML/Graphics/View.hpp>
# include <SFML/Graphics/Rect.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Graphics/ISpatial.hpp"

namespace yap
{
  /// SFML View.
  typedef sf::View View;

  /// @brief Source area for a rendering entity.
  struct YAPOG_LIB ICamera : public ISpatial
  {
      virtual ~ICamera () {}

      virtual bool IsInView (const Vector2& point) const = 0;
      virtual bool IsInView (const Vector2& point,
                             const Vector2& size) const = 0;

      virtual Vector2 ToLocal (const Vector2& globalPoint) const = 0;
      virtual Vector2 ToGlobal (const Vector2& localPoint) const = 0;

      virtual const View& GetInnerView () const = 0;
  };
} // namespace yap

#endif // YAPOG_ICAMERA_HPP
