/*
*/
#ifndef DIELECTRIC_H
#define DIELECTRIC_H

//
#include "Hittable.h"
#include "Material.h"

//
class Dielectric : public Material
{
public:
  double m_ir{};

public:
  Dielectric(double index_of_refraction);

  virtual ScatterResult scatter(const Ray& rIn, const HitRecord& rec) const override;
};

#endif
