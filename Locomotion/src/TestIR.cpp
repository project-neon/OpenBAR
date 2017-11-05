// #include "mbed.h"
//
// Serial PC(USBTX, USBRX); // tx, rx
//
// AnalogIn IR(p15);
//
// int main()
// {
//     PC.baud(115200);
//     PC.printf("Hello2 \r\n");
//
//     while(1)
//     {
//         //Do something else here
//         PC.printf("IR_ Iv:%.5f \t", (6570.66/(IR.read()*1024.0-16.0)));
//         //PC.printf("IR:%.5f \t", ((1.0-IR.read())*26.0+4.0));
//         //PC.printf("IR_Robocore:%.5f \t", (6752/(IR.read()*1023.0-9)-4.0));
//         PC.printf("%.5f \n", IR.read());
//         wait(1);
//     }
// }
