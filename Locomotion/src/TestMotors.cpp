//
// #include <mbed.h>
// #include "_config.h"
// #include "QEI.h"
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
// PwmOut pwmM1(PIN_M1_EN);
// PwmOut pwmM2(PIN_M2_EN);
// PwmOut pwmM3(PIN_M3_EN);
// PwmOut pwmM4(PIN_M4_EN);
//
// DigitalOut in1M1(PIN_M1_IN1);
// DigitalOut in2M1(PIN_M1_IN2);
// DigitalOut in1M2(PIN_M2_IN1);
// DigitalOut in2M2(PIN_M2_IN2);
//
// DigitalOut in1M3(PIN_M3_IN1);
// DigitalOut in2M3(PIN_M3_IN2);
// DigitalOut in1M4(PIN_M4_IN1);
// DigitalOut in2M4(PIN_M4_IN2);
//
// AnalogIn sensors_IR[6] = {
//         PIN_IR_S1,
//         PIN_IR_S2,
//         PIN_IR_S3,
//         PIN_IR_S4,
//         PIN_IR_S5,
//         PIN_IR_S6,
//     };
// AnalogIn sensorIR(p15);
//
// Timer tserial;
//
//     //// Set power of both DC motors
// void Motors_setPower(float m1, float m2){
//
//     // Limit Powers
//     //m1 = min(max(m1, -100.0), 100.0);
//     //m2 = min(max(m2, -100.0), 100.0);
//
//     // Map powers
//     float powerOutA = m1 / 100.0;
//     float powerOutB = m2 / 100.0;
//
//     // Set power
//     pwmM1.write(powerOutA);
//     pwmM3.write(powerOutA);
//
//     pwmM2.write(powerOutB);
//     pwmM4.write(powerOutB);
//
//     // Set Directions
//     in1M1 = powerOutA >  0 ? 1 : 0;
//     in2M1 = powerOutA >= 0 ? 0 : 1;
//     in1M2 = powerOutB >  0 ? 1 : 0;
//     in2M2 = powerOutB >= 0 ? 0 : 1;
//
//     in1M3 = in1M1; //Seja Motor 1 e 3 no mesmo lado (esquerda)
//     in2M3 = in2M1;
//
//     in1M4 = in1M2; //Seja Motor 2 e 4 no mesmo lado (direita)
//     in2M4 = in2M2;
// }
//
// void Motors_stop(){
//     // Stop motor 1
//     in1M1 = 1;
//     in2M1 = 1;
//     pwmM1.write(0);
//
//     // Stop motor 2
//     in1M2 = 1;
//     in2M2 = 1;
//     pwmM2.write(0);
//
//     in1M3 = 1;
//     in2M3 = 1;
//     pwmM3.write(0);
//
//     in1M4 = 1;
//     in2M4 = 1;
//     pwmM4.write(0);
// }
//
// //// Initialize pins
// void Motors_init(){
//     pwmM1.period(PWM_PERIOD);
//     pwmM2.period(PWM_PERIOD);
//     pwmM3.period(PWM_PERIOD);
//     pwmM4.period(PWM_PERIOD);
//     Motors_setPower(0, 0);
// }
//
//
//
// int main() {
//
//   // put your setup code here, to run once:
//
//   //  tserial.start();
//     PC.baud(115200);
//
//     Motors_init();
// /*
//   //Motor A Esquerda tras
//     in1M1 = 1;
//     in2M1 = 0;
//     pwmM1.write(1.0);
//     wait(3);
//     Motors_stop();
//
//   //Motor B Esquerda Frente
//     in1M2 = 1;
//     in2M2 = 0;
//     pwmM2.write(1.0);
//     wait(3);
//     Motors_stop();
//
//   //Motor C Direira Tras
//     in1M3 = 1;
//     in2M3 = 0;
//     pwmM3.write(1.0);
//     wait(3);
//     Motors_stop();
//
//   //Motor D Direita Frente
//     in1M4 = 1;
//     in2M4 = 0;
//     pwmM4.write(1.0);
//     wait(3);
//     Motors_stop();
//
// */
//
//   //Encoders
//     encA.reset();
//     encB.reset();
//     encC.reset();
//     encD.reset();
//
//     unsigned int pulsesA = encA.getPulses();
//     unsigned int pulsesB = encB.getPulses();
//     unsigned int pulsesC = encC.getPulses();
//     unsigned int pulsesD = encD.getPulses();
//
//
//
//   in1M1 = 1;
//   in2M1 = 0;
//   in1M3 = 1;
//   in2M3 = 0;
//
//   in1M2 = in1M1; //Seja Motor 1 e 3 no mesmo lado (esquerda)
//   in2M2 = in2M1;
//
//   in1M4 = in1M3; //Seja Motor 2 e 4 no mesmo lado (direita)
//   in2M4 = in2M3;
//
//   pwmM1.write(1.0);
//   pwmM3.write(1.0);
//
//   pwmM2.write(1.0);
//   pwmM4.write(1.0);
//   //
//   // wait(5);
//   //
//   // Motors_stop();
//
//   while(1) {
//     // put your main code here, to run repeatedly:
//
//
//     // pulsesA = encA.getPulses();
//     // pulsesB = encB.getPulses();
//     // pulsesC = encC.getPulses();
//     // pulsesD = encD.getPulses();
//
//     //PC.printf("%.3i %.3i %.3i %.3i\n", pulsesA, pulsesB, pulsesC, pulsesD);
//     //wait(1);
//
//     in1M1 = 1;
//     in2M1 = 0;
//     in1M3 = 1;
//     in2M3 = 0;
//     in1M2 = in1M1; //Seja Motor 1 e 3 no mesmo lado (esquerda)
//     in2M2 = in2M1;
//     in1M4 = in1M3; //Seja Motor 2 e 4 no mesmo lado (direita)
//     in2M4 = in2M3;
//     pwmM1.write(1.0);
//     pwmM3.write(1.0);
//     pwmM2.write(1.0);
//     pwmM4.write(1.0);
//     wait(2);
//     Motors_stop();
//     wait(1);
//
//     in1M1 = 1;
//     in2M1 = 0;
//     in1M3 = 1;
//     in2M3 = 1;
//     in1M2 = in1M1; //Seja Motor 1 e 3 no mesmo lado (esquerda)
//     in2M2 = in2M1;
//     in1M4 = in1M3; //Seja Motor 2 e 4 no mesmo lado (direita)
//     in2M4 = in2M3;
//     pwmM1.write(1.0);
//     pwmM3.write(1.0);
//     pwmM2.write(1.0);
//     pwmM4.write(1.0);
//     wait(2);
//     Motors_stop();
//     wait(1);
//
//      if (tserial.read() >= 35) {
//             tserial.reset();
//             Motors_stop();
//             PC.printf("Done\n");
//         }
//   }
// }
