//
// #include <mbed.h>
// #include "_config.h"
// #include "QEI.h"
// #include "Motor.h"
// //#include "SHARPIR.h"
//
// Serial PC(USBTX, USBRX); // tx, rx
//
// QEI encA (PIN_ENCA_1, PIN_ENCA_2, NC, PULSES_PER_REV);
// QEI encB (PIN_ENCB_1, PIN_ENCB_2, NC, PULSES_PER_REV);
// QEI encC (PIN_ENCC_1, PIN_ENCC_2, NC, PULSES_PER_REV);
// QEI encD (PIN_ENCD_1, PIN_ENCD_2, NC, PULSES_PER_REV);
//
//
// // PwmOut pwmM1(PIN_M1_EN);
// // PwmOut pwmM2(PIN_M2_EN);
// // PwmOut pwmM3(PIN_M3_EN);
// // PwmOut pwmM4(PIN_M4_EN);
// //
// // DigitalOut in1M1(PIN_M1_IN1);
// // DigitalOut in2M1(PIN_M1_IN2);
// // DigitalOut in1M2(PIN_M2_IN1);
// // DigitalOut in2M2(PIN_M2_IN2);
// //
// // DigitalOut in1M3(PIN_M3_IN1);
// // DigitalOut in2M3(PIN_M3_IN2);
// // DigitalOut in1M4(PIN_M4_IN1);
// // DigitalOut in2M4(PIN_M4_IN2);
//
// Motor m1(PIN_M1_EN, PIN_M1_IN1, PIN_M1_IN2);
// Motor m2(PIN_M2_EN, PIN_M2_IN1, PIN_M2_IN2);
// Motor m3(PIN_M3_EN, PIN_M3_IN1, PIN_M3_IN2);
// Motor m4(PIN_M4_EN, PIN_M4_IN1, PIN_M4_IN2);
//
//
//
// Timer tserial;
//
//
// int main() {
//
//   // put your setup code here, to run once:
//
//   //  tserial.start();
//     PC.baud(115200);
//     PC.printf("Hello \r\n");
//
//     m1.brake();
//     m2.brake();
//     m3.brake();
//     m4.brake();
//
//
//
//   while(1) {
//     // put your main code here, to run repeatedly:
//
//     // m1.speed(1);
//     // m2.speed(1);
//     // m3.speed(1);
//     // m4.speed(1);
//     // wait(2);
//     // m1.brake();
//     // m2.brake();
//     // m3.brake();
//     // m4.brake();
//     // wait(1);
//     m1.speed(-1);
//     m2.speed(-1);
//     m3.speed(1);
//     m4.speed(1);
//     wait(2);
//
//      if (tserial.read() >= 10) {
//             tserial.reset();
//             m1.brake();
//             m2.brake();
//             m3.brake();
//             m4.brake();
//             PC.printf("Done\n");
//         }
//   }
// }
