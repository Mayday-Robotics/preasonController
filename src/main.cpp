/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       nikkasouza                                                */
/*    Created:      6/24/2024, 8:52:19 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include <iostream>

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;

// define your global instances of motors and other devices here

controller Controller = controller(primary);
motor LeftMotor1 = motor(PORT1, ratio36_1); // Red motor uses 36 to 1 ratio
// motor LeftMotor2 = motor(PORT2, ratio36_1);
// motor LeftMotor3 = motor(PORT3, ratio36_1);
// motor LeftMotor4 = motor(PORT4, ratio36_1);

// motor_group LeftMotorGroup = motor_group(LeftMotor1, LeftMotor2, LeftMotor3, LeftMotor4);

// motor RightMotor1 = motor(PORT5, ratio36_1); 
// motor RightMotor2 = motor(PORT6, ratio36_1);
// motor RightMotor3 = motor(PORT7, ratio36_1);
// motor RightMotor4 = motor(PORT8, ratio36_1);

// motor_group RightMotorGroup = motor_group(RightMotor1, RightMotor2, RightMotor3, RightMotor4);

double wheelCircumference = 4.0;
double trackDistance = 10.0; // TODO: Change to actual values
double wheelBase = 10.0; // TODO: Change to actual values
double externalGearRotation = 1; // def not changing, not chaining motors together LOL
// drivetrain DriveTrain = drivetrain(LeftMotorGroup, RightMotorGroup, wheelCircumference, trackDistance, wheelBase, inches, externalGearRotation);


int axisPosition(vex::controller::axis axis) {
    int pos = axis.position();
    if (pos > 15 || pos < 15) { // account for stick drift.
        return pos;
    }
    return 0;
}

int main() {

    Brain.Screen.print("Good morning.");
    std::cout << "Hello World" << "\n";
    
    while(true) {
        Brain.Screen.clearLine();
        Brain.Screen.print(Controller.Axis4.position());

        int axis4Pos = axisPosition(Controller.Axis4);
        
        LeftMotor1.setVelocity(axis4Pos, percent);
        LeftMotor1.spin(forward);
        
        // DriveTrain.setDriveVelocity(axisPosition(Controller.Axis2), percent);
        // DriveTrain.setTurnVelocity(axis4Pos, percent);

        // DriveTrain.drive(forward);

        // if (axis4Pos > 0) {
        //     DriveTrain.turn(left);
        // } else if (axis4Pos < 0) {
        //     DriveTrain.turn(right);
        // }

        // Allow other tasks to run
        wait(10, msec);
    }
}
