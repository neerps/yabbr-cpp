/*
*/
#ifndef CAMERA_H
#define CAMERA_H

#include "Rtweekend.h"

//
class Camera {
private:
  Point3 m_origin{};
  Point3 m_lowerLeftCorner{};
  Vec3 m_horizontal{};
  Vec3 m_vertical{};
  Vec3 m_u{};
  Vec3 m_v{};
  Vec3 m_w{};
  double m_lensRadius{};

public:
  // vfov - vertical field of view in degrees
  Camera(
    Point3 lookFrom,
    Point3 lookAt,
    Vec3 vUp,
    double vFov, 
    double aspectRatio,
    double aperture,
    double focusDist
  );

  Ray getRay(double s, double t) const;

};

#endif
