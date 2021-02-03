#include "modules/commands/direction_command.h"

DirectionCommand::DirectionCommand(
        Engine* engine, 
        Engine::motor_descriptor_r motor, 
        Engine::direction_t direction) {
    this->engine = engine;
    this->motor = motor;
    this->direction = direction;
}

void DirectionCommand::execute() {
    engine->set_direction(motor, direction);
}