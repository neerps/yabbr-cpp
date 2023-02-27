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
bool Metal::scatter(
  const Ray& rIn, const HitRecord& rec,  [[maybe_unused]] const RandomGen& rng, Color& attenuation, Ray& scattered
) const
{
  Vec3 reflected{reflect(unitVector(rIn.direction()), rec.normal)};
  scattered = Ray(rec.p, reflected);
  attenuation = m_albedo;
  return dot(scattered.direction(), rec.normal) > 0;
}
