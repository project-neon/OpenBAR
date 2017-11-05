// #include "mbed.h"
// #include "SHARPIR.h"
//
// Serial PC(USBTX, USBRX); // tx, rx
//
// //AnalogIn IR(p15);
// SHARPIR sensor(p15);
//
// int main()
// {
//     PC.baud(115200);
//     PC.printf("Hello \r\n");
//
//
//     //sensor.calibrate(57.373, 1.3166, 0.45, 2.5);
//
//     while(1)
//     {
//         //Do something else here
//         // PC.printf("IR_ Iv:%.5f \t", (6570.66/(IR.read()*1023.0-16.0)));
//         // PC.printf("IR:%.5f \t", ((1.0-IR.read())*26.0+4.0));
//         // PC.printf("%.5f \n", IR.read());
//         PC.printf("cm: %f \n", sensor.cm());
//         wait(1);
//
//     }
// }
