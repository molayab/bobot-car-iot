#ifndef kernel_h
#define kernel_h
#include "shell.h"
#include "Arduino.h"

class Bobot { 
public:
    Bobot();
    ~Bobot();
    void received_byte(uint8_t byte);
    void sync(); // Given CPU time to do important stuff.
private:
    Communication::BufferDelegate* shell;
    Communication::Parser* parser;
    Communication::Buffer* buffer;
};

#endif