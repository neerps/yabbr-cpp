/*
*/
#include "RandomGen.h"
#include "Vec3.h"

//
Vec3::Vec3()
  : m_e{0, 0, 0}
{}

//
Vec3::Vec3(double e0, double e1, double e2)
  : m_e{e0, e1, e2}
{}

//
double Vec3::x() const
{
  return m_e[0];
}

//
double Vec3::y() const
{
  return m_e[1];
}

//
double Vec3::z() const
{
  return m_e[2];
}

//
Vec3 Vec3::operator-() const
{
  return {-m_e[0], -m_e[1], -m_e[2]};
}

//
double Vec3::operator[](int i) const
{
  return(m_e[i]);
}

//
double& Vec3::operator[](int i)
{
  return(m_e[i]);
}

Vec3& Vec3::operator+=(const Vec3& v)
{
  m_e[0] += v.m_e[0];
  m_e[1] += v.m_e[1];
  m_e[2] += v.m_e[2];
  return *this;
}

//
Vec3& Vec3::operator*=(const double t)
{
  m_e[0] *= t;
  m_e[1] *= t;
  m_e[2] *= t;
  return *this;
}

//
Vec3& Vec3::operator/=(const double t)
{
  return *this *= 1 / t;
}

//
double Vec3::length() const
{
  return std::sqrt(lengthSquared());
}

//
double Vec3::lengthSquared() const
{
  return m_e[0] * m_e[0] + m_e[1] * m_e[1] + m_e[2] * m_e[2];
}

//
bool Vec3::nearZero() const
{
  constexpr auto s{1e-8};
  return (fabs(m_e[0]) < s) && (fabs(m_e[1]) < s) && (fabs(m_e[2]) < s);
}

// Class utility functions
std::ostream& operator<<(std::ostream& out, const Vec3& v)
{
  return out << v.m_e[0] << ' ' << v.m_e[1] << ' ' << v.m_e[2];
}

//
Vec3 operator+(const Vec3& u, const Vec3& v)
{
  return {u.m_e[0] + v.m_e[0], u.m_e[1] + v.m_e[1], u.m_e[2] + v.m_e[2]};
}

//
Vec3 operator-(const Vec3& u, const Vec3& v)
{
  return {u.m_e[0] - v.m_e[0], u.m_e[1] - v.m_e[1], u.m_e[2] - v.m_e[2]};
}

//
Vec3 operator*(const Vec3& u, const Vec3& v)
{
  return {u.m_e[0] * v.m_e[0], u.m_e[1] * v.m_e[1], u.m_e[2] * v.m_e[2]};
}

//
Vec3 operator*(double t, const Vec3& v)
{
  return {t * v.m_e[0], t * v.m_e[1], t * v.m_e[2]};
}

//
Vec3 operator*(const Vec3& v, double t)
{
  return t * v;
}

//
Vec3 operator/(const Vec3& v, double t)
{
  return (1 / t) * v;
}

//
double dot(const Vec3& u, const Vec3& v)
{
  return u.m_e[0] * v.m_e[0] + u.m_e[1] * v.m_e[1] + u.m_e[2] * v.m_e[2];
}

//
Vec3 cross(const Vec3& u, const Vec3& v)
{
  return {u.m_e[1] * v.m_e[2] - u.m_e[2] * v.m_e[1],
          u.m_e[2] * v.m_e[0] - u.m_e[0] * v.m_e[2],
          u.m_e[0] * v.m_e[1] - u.m_e[1] * v.m_e[0]};
}

//
Vec3 unitVector(const Vec3& v)
{
  return v / v.length();
}

//
Vec3 rndVec3()
{
  return Vec3{RandomGen::getRandomDouble(0, 1), RandomGen::getRandomDouble(0, 1), RandomGen::getRandomDouble(0, 1)};
}

//
Vec3 rndVec3(double min, double max)
{
  return Vec3{RandomGen::getRandomDouble(min, max), RandomGen::getRandomDouble(min, max), RandomGen::getRandomDouble(min, max)};
}

//
Vec3 randomInUnitSphere()
{
  while (true)
  {
    auto p{rndVec3(-1, 1)};
    if (p.lengthSquared() < 1)
    {
      return p;
    }
  }
}

//
Vec3 randomInHemisphere(const Vec3& normal)
{
  Vec3 inUnitSphere{randomInUnitSphere()};
  if (dot(inUnitSphere, normal) > 0.0)
  {
    return inUnitSphere;
  }
  else
  {
    return -inUnitSphere;
  }
}

//
Vec3 randomInUnitDisk()
{
  while (true)
  {
    auto p{Vec3{RandomGen::getRandomDouble(-1, 1), RandomGen::getRandomDouble(-1, 1), 0}};
    if (p.lengthSquared() < 1)
      return p;
  }
}

//
Vec3 randomUnitVector()
{
  return unitVector(randomInUnitSphere());
}

//
Vec3 reflect(const Vec3& v, const Vec3& n)
{
  return v - 2 * dot(v, n) * n;
}

//
Vec3 refract(const Vec3& uv, const Vec3& n, double etai_over_etat)
{
  auto cosTheta{fmin(dot(-uv, n), 1.0)};
  Vec3 rOutPerp{etai_over_etat * (uv + cosTheta * n)};
  Vec3 rOutParallel{-std::sqrt(fabs(1.0 - rOutPerp.lengthSquared())) * n};
  return rOutPerp + rOutParallel;
}
