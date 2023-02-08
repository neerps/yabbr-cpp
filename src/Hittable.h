/*
*/
#ifndef HITTABLE_H
#define HITTABLE_H

//
#include "Ray.h"

//
struct HitRecord
{
  Point3 p{};
  Vec3 normal{};
  double t{};
};

//
class Hittable
{
public:
  virtual bool hit(const Ray& r, double tMin, double tMax, HitRecord& rec) const = 0;
};

#endif
