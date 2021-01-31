#ifndef kernel_h
#define kernel_h
#include "shell.h"
#include "Arduino.h"

class BobotTask {
    virtual void run() = 0;
};

class Bobot { 
public:
    Bobot();
    ~Bobot();
    void received_byte(uint8_t byte); // Received byte; priorize communication.
    void sync(); // Given CPU time to do important stuff.
    /// Schedules a task in order to be performed each CPU cycle, when available.
    void schedule_task(const BobotTask* const task);
private:
    Communication::BufferDelegate* shell;
    Communication::Parser* parser;
    Communication::Buffer* buffer;
};

#endif