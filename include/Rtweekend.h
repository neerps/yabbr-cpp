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

// Types


// Aliases

// Constants
inline constexpr double infinity{std::numeric_limits<double>::infinity()};
inline constexpr double pi{3.1415926535897932385};

// Utility Functions
double degreesToRadians(double degrees);

double clamp(double x, double min, double max);

#endif
