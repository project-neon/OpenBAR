/* mbed SHARPIR distance sensor
 * Copyright (c) 2010 Tomas Johansen
 * Released under the MIT License: http://mbed.org/license/mit
 */

#ifndef MBED_SHARPIR_H
#define MBED_SHARPIR_H

#include "mbed.h"

class SHARPIR  {
public:
    SHARPIR(PinName AnalogPort);
    float cm();
    float inch();
    float volt();
    void calibrate(double reg, float exp, double lowerrange, double higherrange);

private:
    AnalogIn _analogin;
    double lowerrange;
    double higherrange;
    double reg;
    float  exp; //trendline excel + datasheet
};

#endif
