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

public:
  // vfov - vertical field of view in degrees
  Camera(double vFov, double aspectRatio);

  Ray getRay(double u, double v) const;

};

#endif
