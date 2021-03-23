#include "kernel/shell.h"
#include "modules/commands/power_command.h"
#include "modules/commands/direction_command.h"

Shell::Shell() { }

void Shell::parse(uint8_t* data, uint16_t size) {
    if (size < 1) {
        return; // error wrong command (at least 1 byte is required for id).
    }
    switch (data[0]) {
    case 0x01: // power_command.h
        if (size == 3) {
            PowerCommand(engine, (Engine::motor_descriptor_r)data[1], data[2]).execute();
        }
        break;
    case 0x02: // direction_command.h
        if (size == 3) {
            DirectionCommand(engine,
                (Engine::motor_descriptor_r)data[1],
                (Engine::direction_t)data[2]).execute();
        }
        break;
    }
}

void Shell::register_module(Engine* engine) {
    this->engine = engine;
}