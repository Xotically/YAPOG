#ifndef YAPOG_CAMERACONTROLLER_HPP
# define YAPOG_CAMERACONTROLLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  struct ICamera;
  struct ISpatial;

  class CameraController : public IUpdateable
  {
      DISALLOW_COPY(CameraController);

    public:

      virtual ~CameraController ();

      void SetTarget (ISpatial& target);

      void SetBounds (const FloatRect& bounds);

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

    protected:

      CameraController (ICamera& camera);

      virtual void HandleUpdate (const Time& dt) = 0;

      ICamera& camera_;
      ISpatial* target_;

      FloatRect bounds_;
  };
} // namespace yap

#endif // YAPOG_CAMERACONTROLLER_HPP