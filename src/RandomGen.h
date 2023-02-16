/*
  Mersenne-twsiter based random generator
  and corresponding methods to get random values
*/
#ifndef RANDOM_DOUBLE_GEN_H
#define RANDOM_DOUBLE_GEN_H

#include <random>

//
class RandomGen {
private:
  static std::mt19937_64 s_mt64;
  
public:
  double getRandomDouble(double lower, double upper);
  double getRandomDouble(double lower, double upper) const;
};

#endif
