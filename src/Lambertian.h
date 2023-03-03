/*
*/
#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

//
#include "Hittable.h"
#include "Material.h"
#include "Rtweekend.h"

//
class Lambertian : public Material
{
public:
  Color m_albedo{};

public:
  Lambertian(const Color& a);

  virtual bool scatter(
    const Ray& rIn, const HitRecord& rec, const RandomGen& rng, Color& attenuation, Ray& scattered
  ) const override;

};

#endif
