/*
*/
#ifndef RTWEEKEND_H
#define RTWEEKEND_H

// Common headers
#include "Ray.h"
#include "Vec3.h"

#include <cmath>
#include <limits>
#include <memory>

// Aliases

// Constants
inline constexpr double infinity{std::numeric_limits<double>::infinity()};
inline constexpr double pi{3.1415926535897932385};

// Utility Functions
inline double degreesToRadians(double degrees)
{
  return degrees * pi / 180.0;
}

inline double clamp(double x, double min, double max)
{
  if (x < min)
    return min;
  if (x > max)
    return max;
  return x;
}

#endif
