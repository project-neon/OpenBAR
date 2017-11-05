/* mbed SHARPIR distance sensor
 * Copyright (c) 2010 Tomas Johansen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#include "mbed.h"
#include "SHARPIR.h"


/* This function is currently only working for the Sharp GP2Y0A02YK0F sensor
 * which measures from around 20cm to 150cm. To adapt this to other Sharp IR
 * sensors, you have to calculate the variables reg and exp.
 *
 * To quickly calculate reg and exp, use microsoft excel to plot the graph
 * provided in the datasheet. You should create a scatterplot (except that
 * the y-axis is [cm], and x-axis is [V]).
 *
 * When you get the values, right click the line in the graph and select
 * "Add Trendline". Select "power". Also, in the trendline options, check
 * that you want to see the function. It will then be printed in your
 * scatterplot.
 *
 * This is the function: Reg*x^exp.
 *
 *
 * Example:
 *
 * SHARPIR sensor(p20);
 * sensor.calibrate(57.373, 1.3166, 0.45, 2.5);
 * while(1){
 *     serial.printf("cm: %f ", sensor.cm());
 *     wait_ms(50);
 * }
 *
 * You can also use this method to manually plot values you've measured with
 * the "volt" function, which in the end should give a result similar to the
 * values provided below.
 *
 * Feel free to contact me with improvements for the source code, and
 * especially for values that would work for other sensors.
 */


SHARPIR::SHARPIR(PinName AnalogPort)
        : _analogin(AnalogPort) {
    higherrange=2.5;
    lowerrange=0.45;
    reg=57.373; //60.495
    exp=-1.3166; //-1.1904
}

void calibrate(double reg, float exp, double lowerrange, double higherrange) { //sets new reg and exp value
}

float SHARPIR::volt() {
    return(_analogin.read()*3.3); //analogin function returns a percentage which describes how much of 3.3v it's reading, therefor multiply it by 3,3 to get the correct analogin voltage.
}

float SHARPIR::cm() {
    float v;
    v=volt();
    if (v>higherrange) //sensor is out of higher range
        return(0);
    else if (v<lowerrange)
        return(-1.0); //sensor is out of lower range
    else
        return(reg*pow(v, exp));
}

float SHARPIR::inch() {
    float v;
    v=volt();
    if (v>higherrange) //sensor is out of higher range
        return(0);
    else if (v<lowerrange)
        return(-1.0); //sensor is out of range
    else
        return(0.393700787*reg*pow(v, exp));
}
