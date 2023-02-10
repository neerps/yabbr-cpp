/*
  Mersenne-twsiter based random generator
  and corresponding methods to get random values
*/
#ifndef RANDOM_DOUBLE_GEN_H
#define RANDOM_DOUBLE_GEN_H

#include <random>

//
class RandomDoubleGen {
private:
  static std::mt19937_64 s_mt64;
  
public:
  
  double getRandom(double lower, double upper)
  {
    std::uniform_real_distribution<double> dicey(lower, upper);
    return dicey(s_mt64);
  }
};

#endif
