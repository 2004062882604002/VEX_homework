/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       northern_lights                                           */
/*    Created:      2023/10/8 19:39:53                                        */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here


int main() {

    Brain.Screen.printAt( 10, 50, "Hello V5" );
    
    vex::motor motor1(0);
    vex::motor motor2(1);

    motor1.spin(directionType::fwd,0 , velocityUnits::pct);
    motor2.spin(directionType::fwd,100 , velocityUnits::pct);
    vex::task::sleep(3500); 


        motor1.stop();
        motor2.stop();

    motor1.spin(directionType::rev,100 , velocityUnits::pct);
    motor2.spin(directionType::fwd,0 , velocityUnits::pct);
    vex::task::sleep(3500); 


        motor1.stop();
        motor2.stop();
    
}
