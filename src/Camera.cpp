/*
*/

#include "Camera.h"
#include "Rtweekend.h"

//
Camera::Camera(double vFov, double aspectRatio) 
{
  auto theta{degreesToRadians(vFov)};
  auto h{tan(theta/2)};
  auto viewportHeight{2.0 * h};
  auto viewportWidth{aspectRatio * viewportHeight};

  constexpr auto focalLength{1.0};

  m_origin = Point3{0, 0, 0};
  m_horizontal = Vec3{viewportWidth, 0.0, 0.0};
  m_vertical = Vec3{0.0, viewportHeight, 0.0};
  m_lowerLeftCorner = m_origin - m_horizontal / 2 - m_vertical / 2 - Vec3{0, 0, focalLength};
}

//
Ray Camera::getRay(double u, double v) const 
{
  return Ray{m_origin, m_lowerLeftCorner + u * m_horizontal + v * m_vertical - m_origin};
}
