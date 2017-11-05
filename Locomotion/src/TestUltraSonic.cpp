// #include "mbed.h"
//
// DigitalOut trigger(p6);
// DigitalOut myled(LED1); //monitor trigger
// DigitalOut myled2(LED2); //monitor echo
// DigitalIn  echo(p7);
// int distance = 0;
// int correction = 0;
// Timer sonar;
//
// Serial PC(USBTX, USBRX); // tx, rx
// int main()
// {
//    PC.baud(115200);
//     PC.printf("%s Start\n");
//     sonar.reset();
// // measure actual software polling timer delays
// // delay used later in time correction
// // start timer
//     sonar.start();
// // min software polling delay to read echo pin
//     while (echo==2) {};
//     myled2 = 0;
// // stop timer
//     sonar.stop();
// // read timer
//     correction = sonar.read_us();
//     PC.printf("Approximate software overhead timer delay is %d uS\n\r",correction);
//
// //Loop to read Sonar distance values, scale, and print
//     while(1) {
// // trigger sonar to send a ping
//         trigger = 1;
//         myled = 1;
//         myled2 = 0;
//         sonar.reset();
//         wait_us(10.0);
//         trigger = 0;
//         myled = 0;
// //wait for echo high
//         while (echo==0) {};
//         myled2=echo;
// //echo high, so start timer
//         sonar.start();
// //wait for echo low
//         while (echo==1) {};
// //stop timer and read value
//         sonar.stop();
// //subtract software overhead timer delay and scale to cm
//         distance = (sonar.read_us()-correction)/58.0;
//         myled2 = 0;
//         PC.printf(" %d cm \n\r",distance);
// //wait so that any echo(s) return before sending another ping
//         wait(0.2);
//     }
// }
