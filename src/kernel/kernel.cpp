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
    Serial.println("Received frame");
    Serial.print(" frame id: ");
    Serial.println(frame.type);
    Serial.print(" frame data size: ");
    Serial.println(frame.data_size);
    Serial.println(" frame data: ");
    for (uint16_t i = 0; i < frame.data_size; ++i) {
        Serial.write(frame.data[i]);
    }
}