#include "modules/engine/engine.h"

Engine::Engine(configuration_t config): config(config) {
    pinMode(config.m1_ctr1_pin, OUTPUT);
    pinMode(config.m1_ctr2_pin, OUTPUT);
    pinMode(config.m2_ctr1_pin, OUTPUT);
    pinMode(config.m2_ctr2_pin, OUTPUT);
    pinMode(config.m1_pwm_pin, OUTPUT);
    pinMode(config.m2_pwm_pin, OUTPUT);
    stop();
}

void Engine::set_direction(motor_descriptor_r motor, direction_t direction) {

}

void Engine::set_power(motor_descriptor_r motor, int power) {
    switch (motor) {
        case LEFT:
            set_pwm_value(config.m1_ctr1_pin, power);
            break;
        case RIGHT:
            set_pwm_value(config.m2_ctr1_pin, power);
            break;
    }
}

void Engine::set_pwm_value(uint8_t pin, int value) {
    analogWrite(pin, value);
}

void Engine::stop() {
    digitalWrite(config.m1_ctr1_pin, LOW);
    digitalWrite(config.m1_ctr2_pin, LOW);
    digitalWrite(config.m2_ctr1_pin, LOW);
    digitalWrite(config.m2_ctr2_pin, LOW);

    // also stop motors using pwm signal.

    analogWrite(config.m1_pwm_pin, 0);
    analogWrite(config.m2_pwm_pin, 0);
}