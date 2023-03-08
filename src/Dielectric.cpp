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
  double cosTheta{fmin(dot(-unitDirection, rec.normal), 1.0)};
  double sinTheta{std::sqrt(1.0 - cosTheta * cosTheta)};

  bool cannotRefract{refractionRatio * sinTheta > 1.0};
  Vec3 direction{};

  if (cannotRefract || reflectance(cosTheta, refractionRatio) > RandomGen::getRandomDouble(0, 1))
    direction = reflect(unitDirection, rec.normal);
  else
    direction = refract(unitDirection, rec.normal, refractionRatio);

  res.scattered = Ray{rec.p, direction};
  res.isScattered = true;

  return res;
}

//
double Dielectric::reflectance(double cosine, double refIdx)
{
  // Shlick's approximation
  auto r0{(1 - refIdx) / (1 + refIdx)};
  r0 = r0 * r0;
  return r0 + (1 - r0) * pow((1 - cosine), 5);
}
