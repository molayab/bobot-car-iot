#include "modules/commands/power_command.h"

PowerCommand::PowerCommand(Engine* engine,
                        Engine::motor_descriptor_r motor, 
                        uint8_t power) {
    this->engine = engine;
    this->motor = motor;
    this->power = power;
}

void PowerCommand::execute() {
    engine->set_power(motor, power);
}