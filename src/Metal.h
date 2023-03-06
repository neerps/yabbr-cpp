/*
*/
#ifndef METAL_H
#define METAL_H

#include "Hittable.h"
#include "Material.h"
#include "Rtweekend.h"

//
class Metal : public Material
{
public:
  Color m_albedo{};

public:
  Metal(const Color& a);

  virtual bool scatter(
    const Ray& rIn, const HitRecord& rec, Color& attenuation, Ray& scattered
  ) const override;
};

#endif
