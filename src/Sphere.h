/*
*/
#ifndef SPHERE_H
#define SPHERE_H

//
#include "Hittable.h"
#include "Vec3.h"

//
class Sphere: public Hittable
{
public:
  Point3 m_center{};
  double m_radius{};

public:
  Sphere();
  Sphere(Point3 cen, double r);

  virtual bool hit(const Ray& r, double tMin, double tMax, HitRecord& rec) const override;

};

#endif
