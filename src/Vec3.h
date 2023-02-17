/*
*/
#ifndef VEC3_H
#define VEC3_H

//
#include "RandomGen.h"
#include <cmath>
#include <iostream>

//
class Vec3 {
public:
  double m_e[3]{};

public:
  Vec3();
  Vec3(double e0, double e1, double e2);

  double x() const;
  double y() const;
  double z() const;

  Vec3 operator-() const;
  double operator[](int i) const;
  double& operator[](int i);

  Vec3& operator+=(const Vec3& v);
  Vec3& operator*=(const double t);
  Vec3& operator/=(const double t);

  double length() const;
  double lengthSquared() const;
};

//
using Point3 = Vec3;
using Color = Vec3;

// Class utility functions
std::ostream& operator<<(std::ostream& out, const Vec3& v);

Vec3 operator+(const Vec3& u, const Vec3& v);

//
Vec3 operator-(const Vec3& u, const Vec3& v);
//
Vec3 operator*(const Vec3& u, const Vec3& v);

//
Vec3 operator*(double t, const Vec3& v);

//
Vec3 operator*(const Vec3& v, double t);

//
Vec3 operator/(const Vec3& v, double t);

//
double dot(const Vec3& u, const Vec3& v);

//
Vec3 cross(const Vec3& u, const Vec3& v);

//
Vec3 unitVector(const Vec3& v);

//
Vec3 rndVec3(const RandomGen& rng);

//
Vec3 rndVec3(const RandomGen& rng, double min, double max);

//
Vec3 randomInUnitSphere(const RandomGen& rng);

//
Vec3 randomUnitVector(const RandomGen& rng);

#endif
