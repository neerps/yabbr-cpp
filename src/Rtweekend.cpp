/*
*/
#include "Rtweekend.h"

//
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
