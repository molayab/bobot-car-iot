#include "kernel/kernel.h"

Bobot::Bobot() {
    this->handler = new Communication::Handler();
    handler->set_receiver(this);
}

Bobot::~Bobot() {
    delete handler;
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
    // Call to interpretate frame
}