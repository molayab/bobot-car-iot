#ifndef engine_h
#define engine_h

#include <Arduino.h>

class Engine 
{
    public:
    /**
     * Configures H-Bridge hardware connections for Engine class 
     * usage. It requires 2 PWM pins for speed and 4 (2 each motor)
     * for control. When control pin is set LOW - HIGH motor rotates
     * on one direction, inverting the logic (HIGH - LOW) motor will
     * rotate otherwise. For H-H and L-L motor stops.
     */
    struct configuration_t
    {
        uint8_t m1_pwm_pin;
        uint8_t m2_pwm_pin;
        uint8_t m1_ctr1_pin;
        uint8_t m1_ctr2_pin;
        uint8_t m2_ctr1_pin;
        uint8_t m2_ctr2_pin;
    };
    /**
     * Describes the motor to interact
     */
    enum motor_descriptor_r { LEFT = 0, RIGHT };
    enum direction_t { FORWARD = 0, BACKWARD };
    

    Engine(configuration_t config);
    void set_direction(motor_descriptor_r motor, direction_t direction);
    void set_power(motor_descriptor_r motor, int power);
    void stop();
    
    private:
    configuration_t config;
};

#endif