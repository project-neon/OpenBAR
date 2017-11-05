#ifndef CONFIG_H
#define CONFIG_H
#include "mbed.h"

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
// Bluetooth Configs (Type here)
//
#define BT_SPEED	9600
#define BTRX	p9
#define BTTX	p10

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


// Encoder config (Quadrature)
//
#define PULSES_PER_REV 180
#define PIN_ENCA_1	p7
#define PIN_ENCA_2	p8
#define PIN_ENCB_1	p6
#define PIN_ENCB_2	p5
#define PIN_ENCC_1  p25
#define PIN_ENCC_2  p26
#define PIN_ENCD_1  p30
#define PIN_ENCD_2  p29
#define WHEEL_RADIUS	37	//mm
#define WHEEL_PERIMETER	0.1162389f	// WHEEL_RADIUS * PI = 0.11623892818282234982311780518134


#endif
