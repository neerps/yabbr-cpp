/*
*/

#include "Camera.h"
#include "Rtweekend.h"

//
Camera::Camera(
  Point3 lookFrom,
  Point3 lookAt,
  Vec3 vUp,
  double vFov, 
  double aspectRatio
) 
{
  auto theta{degreesToRadians(vFov)};
  auto h{tan(theta/2)};
  auto viewportHeight{2.0 * h};
  auto viewportWidth{aspectRatio * viewportHeight};

  auto w{unitVector(lookFrom - lookAt)};
  auto u{unitVector(cross(vUp, w))};
  auto v{cross(w, u)};

  m_origin = lookFrom;
  m_horizontal = viewportWidth * u;
  m_vertical = viewportHeight * v;
  m_lowerLeftCorner = m_origin - m_horizontal / 2 - m_vertical / 2 - w;
}

//
Ray Camera::getRay(double s, double t) const 
{
  return Ray{m_origin, m_lowerLeftCorner + s * m_horizontal + t * m_vertical - m_origin};
}
