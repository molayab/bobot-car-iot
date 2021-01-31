#include "kernel/kernel.h"

Bobot::Bobot() {
    this->shell = new Interpreter();
    this->parser = new Communication::Parser();
    this->buffer = new Communication::Buffer(parser, shell);
}

Bobot::~Bobot() {
    // delete shell;
    delete parser;
    delete buffer;
}

void Bobot::received_byte(uint8_t byte) {
    // buffer->writeByte(byte);
}