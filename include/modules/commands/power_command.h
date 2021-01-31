#ifndef power_command_h
#define power_command_h
#include "command.h"
#include "../engine/engine.h"

/**
 * Power Command :: command id (0x01)
 * It describes the power to be applied on a certain motor.
 * 
 * ABI: (see communication module)
 * [ 0x01 (ID) | 0x01 (motor selector) | 0xFF (pwm value)]
 * [  1 byte   |          1 byte       |      1 byte     ]
 */
class PowerCommand: public Command {
    public:
    PowerCommand(Engine* engine, Engine::motor_descriptor_r motor, uint8_t power);

    private:
    Engine* engine;
    uint8_t power;
    Engine::motor_descriptor_r motor;
};

#endif