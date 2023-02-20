/*
*/
#ifndef MATERIAL_H
#define MATERIAL_H

#include "Rtweekend.h"

//
struct HitRecord;

//
class Material
{
public:
  virtual ~Material() = default;
  virtual bool scatter(
    const Ray& rIn, const HitRecord& rec, Color& attenuation, Ray& scattered
  ) const = 0;
};

#endif
