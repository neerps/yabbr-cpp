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
  virtual ScatterResult scatter(const Ray& rIn, const HitRecord& rec) const = 0;
};

#endif
