#include "auton.hpp"
#include "odom.hpp"
#include "config.hpp"

extern Odom odom;   // use the same global odom here

void runMatchAuton() {
    // Example: start at origin, face +X (0 degrees)
    //odom.reset(-141.134, 33.835, 19.9);
    
    // odom.curveTo(
    // -124.962,84.078,  // Mid control point
    // -105.46, 146.096,   // End of curve
    // 1.2                 // More time for a smoother curve
    // );   
    // intakeBottom.move(-1000);
    // odom.driveTo(-74.659, 56.111,19.9, 1.445);
    // pros::delay(500);
    // intakeBottom.move(0);
    // pros::delay(700);
    // intakeBottom.move(-1000);
    // odom.driveTo(-74.659, 56.111,19.9, 0.7);
    odom.reset(0,0,0);
    odom.pointTurn(90,2.5);
    
    
    
    
    
} 

void runSkillsAuton() {
    odom.reset(0.0, 0.0, 0.0);
    // add longer skills path here
}

void opcontrol() {
    while (true) {
        pros::delay(20);
    }
}
