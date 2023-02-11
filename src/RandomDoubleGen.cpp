/*

*/
#include "RandomDoubleGen.h"

#include <random>
#include <chrono>

//
std::mt19937_64 RandomDoubleGen::s_mt64{static_cast<std::mt19937_64::result_type>(
  std::chrono::steady_clock::now().time_since_epoch().count()
)};

//
double RandomDoubleGen::getRandom(double lower, double upper)
{
  std::uniform_real_distribution<double> dicey(lower, upper);
  return dicey(s_mt64);
}
