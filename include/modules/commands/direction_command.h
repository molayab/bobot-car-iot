#ifndef direction_command_h
#define direction_command_h
#include "command.h"
#include "modules/engine/engine.h"

/**
 * Direction Command :: command id (0x02)
 * It describes the direction to be applied to certain motor.
 * 
 * ABI: (see communication module)
 * [ 0x02 (ID) | 0x01 (motor selector) | 0x00 BWD | 0xFF FWD ]
 * [  1 byte   |          1 byte       |        1 byte       ]
 */
class DirectionCommand: public Command {
public:
    DirectionCommand(
        Engine* engine, 
        Engine::motor_descriptor_r motor, 
        Engine::direction_t direction);
    void execute();

private:
    Engine* engine;
    Engine::direction_t direction;
    Engine::motor_descriptor_r motor;
};

#endif