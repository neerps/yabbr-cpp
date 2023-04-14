/*
*/
#ifndef RAY_H
#define RAY_H

//
#include "Vec3.h"

//
class Ray {
public:
  Point3 m_orig{};
  Vec3 m_dir{};

public:
  Ray();
  Ray(const Point3& origin, const Vec3& direction);

  Point3 origin() const;
  Vec3 direction() const;

  Point3 at(double t) const;
};


#endif
