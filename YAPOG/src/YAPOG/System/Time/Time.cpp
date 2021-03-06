#include "YAPOG/System/Time/Time.hpp"

namespace yap
{
  Time::Time ()
    : value_ ()
  {
  }

  Time::Time (float seconds)
    : value_ (sf::seconds (seconds))
  {
  }

  Time::Time (const sf::Time& copy)
    : value_ (copy)
  {
  }

  Time::Time (const Time& copy)
    : value_ (copy.value_)
  {
  }

  Time& Time::operator= (const Time& copy)
  {
    if (this == &copy)
      return *this;

    value_ = copy.value_;

    return *this;
  }

  Time Time::operator+ (const Time& rhs)
  {
    return Time (value_ + rhs.value_);
  }

  Time Time::operator+ (float rhs)
  {
    return operator+ (Time (rhs));
  }

  Time Time::operator- (const Time& rhs)
  {
    return Time (value_ - rhs.value_);
  }

  Time Time::operator- (float rhs)
  {
    return operator- (Time (rhs));
  }

  Time& Time::operator+= (const Time& rhs)
  {
    value_ += rhs.value_;

    return *this;
  }

  Time& Time::operator+= (float rhs)
  {
    return operator+= (Time (rhs));
  }

  Time& Time::operator-= (const Time& rhs)
  {
    value_ -= rhs.value_;

    return *this;
  }

  Time& Time::operator-= (float rhs)
  {
    return operator-= (Time (rhs));
  }

  float Time::GetValue () const
  {
    return value_.asSeconds ();
  }
} // namespace yap
