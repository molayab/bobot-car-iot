#include "kernel/kernel.h"

Bobot::Bobot() {
    this->handler = new Communication::Handler();
    handler->set_receiver(this);
    engine = nullptr;
}

Bobot::~Bobot() {
    delete handler;
    delete shell;
    delete engine;
}

void Bobot::received_byte(uint8_t byte) {
    handler->receive(byte);
}

void Bobot::schedule_task(BobotTask* task) {
    this->task = task;
}

void Bobot::sync() {
    task->run();
}

void Bobot::receive(Communication::frame_t frame) {
    switch (frame.type) {
    case Communication::CONTROL:
        shell->parse(frame.data, frame.data_size);
        break;
    case Communication::STREAM:
        break;
    }
}

void Bobot::set_shell(ShellParser* shell) {
    if (nullptr == engine) {
        return; // please first setup the modules.
    }
    shell->register_module(engine);
    this->shell = shell;
}

void Bobot::register_engine(Engine::configuration_t config) {
    engine = new Engine(config);
}