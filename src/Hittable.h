/*
*/
#ifndef HITTABLE_H
#define HITTABLE_H

//
#include "Rtweekend.h"

//
class Material;

//
struct HitRecord
{
  Point3 p{};
  Vec3 normal{};
  std::shared_ptr<Material> matPtr{};
  double t{};
  bool frontFace{};

  inline void setFaceNormal(const Ray& r, const Vec3& outwardNormal)
  {
    frontFace = dot(r.direction(), outwardNormal) < 0;
    normal = frontFace ? outwardNormal : -outwardNormal;
  }
};

//
struct HitResult
{
  bool isHit{};
  HitRecord rec{};
};

//
struct ScatterResult
{
  bool isScattered{};
  Ray scattered{};
  Color attentuation{};
};

//
class Hittable
{
public:
  virtual ~Hittable() = default;
  virtual HitResult hit(const Ray& r, double tMin, double tMax) const = 0;
};

#endif
