#include "pid.hpp"

PID::PID(double p, double i, double d,
double output_limit,
double integral_limit)
: kP(p),
kI(i),
kD(d),
integral(0.0),
prevError(0.0),
outputLimit(output_limit),
integralLimit(integral_limit) { }

void PID::reset() {
integral = 0.0;
prevError = 0.0;
}

double PID::step(double error, double dt_seconds) {
if (dt_seconds <= 0.0) {
return 0.0;
}

integral += error * dt_seconds;

if (integralLimit > 0.0) {
    if (integral > integralLimit) {
        integral = integralLimit;
    }
    if (integral < -integralLimit) {
        integral = -integralLimit;
    }
}

double derivative = (error - prevError) / dt_seconds;

double output = kP * error + kI * integral + kD * derivative;

if (outputLimit > 0.0) {
    if (output > outputLimit) {
        output = outputLimit;
    }
    if (output < -outputLimit) {
        output = -outputLimit;
    }
}

prevError = error;

return output;
}
