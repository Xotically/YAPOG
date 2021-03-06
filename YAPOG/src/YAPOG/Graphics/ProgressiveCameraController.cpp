#include "YAPOG/Graphics/ProgressiveCameraController.hpp"
#include "YAPOG/Graphics/ICamera.hpp"
#include "YAPOG/Graphics/ISpatial.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  const float ProgressiveCameraController::CAMERA_MOVE_TRIGGER_LIMIT = 50.0f;
  const float ProgressiveCameraController::MOVE_AMORTIZATION_FACTOR = 180.0f;
  const float ProgressiveCameraController::DEFAULT_VELOCITY_FACTOR = 100.0f;

  ProgressiveCameraController::ProgressiveCameraController (ICamera& camera)
    : CameraController (camera)
    , velocityFactor_ (
        Vector2 (
          DEFAULT_VELOCITY_FACTOR,
          DEFAULT_VELOCITY_FACTOR))
  {
  }

  ProgressiveCameraController::~ProgressiveCameraController ()
  {
  }

  void ProgressiveCameraController::SetVelocityFactor (
    const Vector2& velocityFactor)
  {
    velocityFactor_ = velocityFactor;
  }

  void ProgressiveCameraController::HandleFocusTarget ()
  {
    CenterOnTarget ();
  }

  void ProgressiveCameraController::HandleUpdate (const Time& dt)
  {
    if (target_ == nullptr)
      return;

    Vector2 offset;

    const Vector2& targetPoint = target_->GetCenter ();
    Vector2 cameraSizeFactor = Vector2 (
      camera_.GetSize ().x / camera_.GetSize ().y,
      camera_.GetSize ().y / camera_.GetSize ().x);

    if (MathHelper::Abs (targetPoint.x - camera_.GetCenter ().x) >
        CAMERA_MOVE_TRIGGER_LIMIT * cameraSizeFactor.x)
      offset.x =
        velocityFactor_.x *
        (targetPoint.x - camera_.GetCenter ().x) /
        MOVE_AMORTIZATION_FACTOR *
        cameraSizeFactor.y *
        dt.GetValue ();

    if (MathHelper::Abs (targetPoint.y - camera_.GetCenter ().y) >
        CAMERA_MOVE_TRIGGER_LIMIT * cameraSizeFactor.y)
      offset.y =
        velocityFactor_.y *
        (targetPoint.y - camera_.GetCenter ().y) /
        MOVE_AMORTIZATION_FACTOR *
        cameraSizeFactor.x *
        dt.GetValue ();

    CheckBounds (offset);

    camera_.Move (offset);
  }
} // namespace yap
