#ifndef CONFIG_H
#define CONFIG_H
#include "mbed.h"
#include "Motor.h"
#include "QEI.h"

//
// Project
//
#define PROJECT_NAME            "Bezerro Autonomo Firmware"
#define PROJECT_VERSION         "v1.0"


//
// Serial DEBUG
//
#define LOG	PC
#define PC_SPEED	115200

//
// Settings
//
#define WHITE_LINE	1
#define NUM_SENSORS             6  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  1  // average 4 analog samples per sensor reading
#define EMITTER_PIN	p14            // emitter is controlled by digital pin 2
#define PIN_LR_S0	p15
#define PIN_LR_S1	p16
#define PIN_LR_S2	p17
#define PIN_LR_S3	p18
#define PIN_LR_S4	p19
#define PIN_LR_S5	p20


//
// Motors config (H-Bridge)
//
//#define SPEED_BASE	0.5
#define PWM_PERIOD              0.001
#define MOTOR_RPM               100 //at 12V
#define WHEEL_RADIO             5 //cm
#define PIN_M4_EN               p21
#define PIN_M4_IN1              p17
#define PIN_M4_IN2              p18

#define PIN_M3_EN               p22
#define PIN_M3_IN1              p19
#define PIN_M3_IN2              p20

#define PIN_M2_EN               p23
#define PIN_M2_IN1              p15
#define PIN_M2_IN2              p16

#define PIN_M1_EN               p24
#define PIN_M1_IN1              p13
#define PIN_M1_IN2              p14


//
// Infra Red sensor
//
#define PIN_IR_S1 p15
#define PIN_IR_S2 p16
#define PIN_IR_S3 p17
#define PIN_IR_S4 p18
#define PIN_IR_S5 p19
#define PIN_IR_S6 p20

//
// Infra US
//
#define PIN_US_S1_ECHO p30
#define PIN_US_S1_TRIG p29
#define PIN_US_S2_ECHO p28
#define PIN_US_S2_TRIG p27
#define PIN_US_S3_ECHO p26
#define PIN_US_S3_TRIG p25
#define PIN_US_S4_ECHO p24
#define PIN_US_S4_TRIG p23

//
// Cow sensor
//
#define cow_sensor_pin p9

// Encoder config (Quadrature)
//
#define COUNTS_PER_REV 3591.84
#define PIN_ENCA_1	p7
#define PIN_ENCA_2	p8
#define PIN_ENCB_1	p6
#define PIN_ENCB_2	p5
#define PIN_ENCC_1  p25
#define PIN_ENCC_2  p26
#define PIN_ENCD_1  p30
#define PIN_ENCD_2  p29

//
// Field info
//
#define LARGURA_CAMPO 300
#define ALTURA_CAMPO  200

//
//constant
//
#define MATH_PI 3.14


Motor m1(PIN_M1_EN, PIN_M1_IN1, PIN_M1_IN2); //trás esquerda
Motor m2(PIN_M2_EN, PIN_M2_IN1, PIN_M2_IN2); //frente esquerda
Motor m3(PIN_M3_EN, PIN_M3_IN1, PIN_M3_IN2); //trás direita
Motor m4(PIN_M4_EN, PIN_M4_IN1, PIN_M4_IN2); //frente direita

//QEI(PinName channelA, PinName channelB, PinName index, int pulsesPerRev, Encoding encoding = X2_ENCODING);
QEI encA (PIN_ENCA_1, PIN_ENCA_2, NC, COUNTS_PER_REV);
QEI encB (PIN_ENCB_1, PIN_ENCB_2, NC, COUNTS_PER_REV);
QEI encC (PIN_ENCC_1, PIN_ENCC_2, NC, COUNTS_PER_REV);
QEI encD (PIN_ENCD_1, PIN_ENCD_2, NC, COUNTS_PER_REV);

#endif
