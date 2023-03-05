/*
*/
#include "Hittable.h"
#include "Lambertian.h"

//
Lambertian::Lambertian(const Color& a)
  : m_albedo{a}
{}

//
bool Lambertian::scatter([[maybe_unused]] const Ray& rIn, 
                         const HitRecord& rec,
                         Color& attenuation, 
                         Ray& scattered
) const 
{
  auto scatterDirection{rec.normal + randomUnitVector()};

  if (scatterDirection.nearZero())
  {
    scatterDirection = rec.normal;
  }

  scattered = Ray{rec.p, scatterDirection};
  attenuation = m_albedo;
  return true;
}

