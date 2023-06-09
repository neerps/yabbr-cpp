/*
*/
#ifndef SPHERE_H
#define SPHERE_H

//
#include "Hittable.h"
#include "Material.h"
#include "Vec3.h"

//
class Sphere: public Hittable
{
public:
  Point3 m_center{};
  double m_radius{};
  std::shared_ptr<Material> m_matPtr{};

public:
  Sphere();
  Sphere(Point3 cen, double r, std::shared_ptr<Material> m);

  virtual HitResult hit(const Ray& r, double tMin, double tMax) const override;

};

#endif
