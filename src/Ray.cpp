/*
*/
#include "Ray.h"
#include "Vec3.h"

//
Ray::Ray() {};

//
Ray::Ray(const Point3& origin, const Vec3& direction)
  : m_orig{origin}, m_dir{direction}
{
}

//
Point3 Ray::origin() const
{
  return m_orig;
}

//
Vec3 Ray::direction() const
{
  return m_dir;
}

//
Point3 Ray::at(double t) const
{
  return m_orig + (t * m_dir);
}
