/*
*/
#include "Hittable.h"
#include "Lambertian.h"

//
Lambertian::Lambertian(const Color& a)
  : m_albedo{a}
{}

//
ScatterResult Lambertian::scatter([[maybe_unused]] const Ray& rIn, 
                         const HitRecord& rec
) const 
{
  ScatterResult res{};
  auto scatterDirection{rec.normal + randomUnitVector()};

  if (scatterDirection.nearZero())
  {
    scatterDirection = rec.normal;
  }

  res.isScattered = true;
  res.scattered = Ray{rec.p, scatterDirection};
  res.attentuation = m_albedo;

  return res;
}

