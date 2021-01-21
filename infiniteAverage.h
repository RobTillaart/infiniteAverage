#pragma once
//
//    FILE: infiniteAverage.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: Calculate the average of a very large number of values.
//     URL: https://github.com/RobTillaart/I2C_24FC1025


#include "Arduino.h"

#define IAVG_LIB_VERSION     (F("0.1.0"))


class IAVG
{
public:
   IAVG()
   {
     reset();
   };

  void reset()
  {
    _sum = 0;
    _overflow = 0;
    _count = 0;
  };

  void add(float value)
  {
    _count++;
    long ov = value;
    _overflow += ov;
    value -= ov;
    _sum += value;
    if (_sum > 1)
    {
      _overflow++;
      _sum -= 1;
    }
  };

  float average()
  {
    return _sum / _count + (1.0 * _overflow) / _count;
  };

  uint32_t count()
  {
    return _count;
  };

  uint32_t whole()
  {
    return _overflow;
  };

  float decimals()
  {
    return _sum;
  };


private:
  float    _sum = 0;
  uint32_t _overflow = 0;
  uint32_t _count = 0;

};

// -- END OF FILE --