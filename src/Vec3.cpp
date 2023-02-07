/*
*/
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
  return {u.m_e[0] * v.m_e[0], u.m_e[1] * v.m_e[1], v.m_e[2] * v.m_e[2]};
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
