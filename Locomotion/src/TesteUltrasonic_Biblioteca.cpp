// #include "mbed.h"
// #include "Ultrasonic.h"
//
// Serial PC(USBTX, USBRX); // tx, rx
//  void dist(int distance)
// {
//     //put code here to execute when the distance has changed
//     PC.printf("Distance %d cm\r\n", distance);
// }
//
// ultrasonic mu(p24, p23, .1, 1, &dist);    //Set the trigger pin to p6 and the echo pin to p7
//                                         //have updates every .1 seconds and a timeout after 1
//                                         //second, and call dist when the distance changes
//
//
//
// int main()
// {
//     PC.baud(115200);
//     PC.printf("Hello \r\n");
//     mu.startUpdates();//start measuring the distance
//     while(1)
//     {
//         //Do something else here
//         mu.checkDistance();     //call checkDistance() as much as possible, as this is where
//                                 //the class checks if dist needs to be called.
//     }
// }
