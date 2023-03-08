/*
*/
#include "Hittable.h"
#include "Metal.h"
#include "Rtweekend.h"

//
Metal::Metal(const Color& a)
  : m_albedo{a}
{}

//
ScatterResult Metal::scatter(
  const Ray& rIn, const HitRecord& rec
) const
{
  ScatterResult res{};
  Vec3 reflected{reflect(unitVector(rIn.direction()), rec.normal)};
  res.scattered =  Ray(rec.p, reflected);
  res.attentuation = m_albedo;
  res.isScattered = dot(res.scattered.direction(), rec.normal) > 0;
  return res;
}
