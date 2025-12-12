#ifndef PID_HPP
#define PID_HPP

class PID {
public:
    PID(double p, double i, double d,
        double output_limit,
        double integral_limit);

    void reset();

    // Run one PID update step
    //  - error: current error
    //  - dt_seconds: time since last update in seconds
    double step(double error, double dt_seconds);

private:
    double kP;
    double kI;
    double kD;

    double integral;
    double prevError;

    double outputLimit;
    double integralLimit;
};

#endif // PID_HPP
