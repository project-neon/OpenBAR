/* mbed SHARPIR distance sensor
 * Copyright (c) 2010 Tomas Johansen
 * Released under the MIT License: http://mbed.org/license/mit
 */

#ifndef MBED_SHARPIRMED_H
#define MBED_SHARPIRMED_H

#include "mbed.h"

class SHARPIRMED  {
public:
    SHARPIRMED(PinName AnalogPort);
    float cm();
    float volt();

private:
    AnalogIn _analogin;
    double lowerrange;
    double higherrange;
    double a;
    float  b; //trendline excel + datasheet
    double c;
};

#endif
