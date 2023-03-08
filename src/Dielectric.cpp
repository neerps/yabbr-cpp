/*
*/
#include "Dielectric.h"

//
Dielectric::Dielectric(double index_of_refraction)
  : m_ir{index_of_refraction}
{}

//
ScatterResult Dielectric::scatter(const Ray& rIn, const HitRecord& rec) const
{
  ScatterResult res{};
  res.attentuation = Color{1.0, 1.0, 1.0};
  double refractionRatio{rec.frontFace ? (1.0 / m_ir) : m_ir};

  Vec3 unitDirection{unitVector(rIn.direction())};
  Vec3 refracted{refract(unitDirection, rec.normal, refractionRatio)};

  res.scattered = Ray{rec.p, refracted};
  res.isScattered = true;

  return res;
}
