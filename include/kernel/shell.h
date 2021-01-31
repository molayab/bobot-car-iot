#ifndef shell_h
#define shell_h
#include "kernel.h"

class Interpreter: public Communication::BufferDelegate {
    void execute(Communication::frame_t frame);
    void did_receive_frame(Communication::frame_t frame);
};

#endif