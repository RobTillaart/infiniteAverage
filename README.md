
[![Arduino CI](https://github.com/RobTillaart/infiniteAverage/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/infiniteAverage/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/infiniteAverage.svg?maxAge=3600)](https://github.com/RobTillaart/infiniteAverage/releases)


# infinteAverage

Arduino Library to calculate an average of many samples


## Description

This library is an experimental library that cascades a float and a uint32_t type.
It was created from an idea when an overflow was encountered in my Statistic Class
due to many samples. 

Taking the average is taking the sum and divide that by the count of the numbers.
Only if the count is fixed one could divide the samples first and then sum them.
This library supports the first scenario.

The float is used for the decimal part and the uint32_t for the whole part.
In theory this should give about 15 significant digits for the average in a 9.6 format.
but this precision is only internal to do some math. WHen the average() is calculated
the value returned is "just" a float.

The library allows two things
1. take the average of many many samples wher normally a summing float would overflow
2. take the average of numbers that differ in order of magnitude

This library also has its limits which needs to be investigated.

Ultimately one could upgrade the idea to a combination of a 8 byte double and a uint64_t
to get around 28 significant digits => 18.10 format 

**Note** the practical meaning of the average of millions or billions of numbers 
is a discussion worth taking. Normally the outliers are the most interesting. 

**Note** the library is not tested, so use (with care) at your own risk.


## Interface

- **IAVG()** constructor, resets the internal counters to 0
- **void reset()** resets the internal counters to 0
- **void add(float value)** adds value to the internal float uint32_t pair.
- **float decimals()** returns the internal float = decimals part.
- **uint32_t whole()** returns the internal whole part.
- **uint32_t count()** returns the number of values added.
- **float average()** returns the average in float format


### Future

- investigate limits of the library
- investigate "adaptive" scaling, now there is a virtual border at 1, 
  but that could be at value (and might be user definable)
  This would allow to adjust to known order of size of the numbers.
  (e.g. if numbers are all in the billions the uint32_t would overflow fast)
- investigate other math with this datatype, starting with + - / * 
- play if time permits.


## Operation

See examples

