#ifndef communication_h
#define communication_h
#ifndef COMMUNICATION_FRAME_FLAG
#define COMMUNICATION_FRAME_FLAG 0xDF
#endif
#include <Arduino.h>
#include <ArduinoSTL.h>

namespace Communication {
    enum frame_type_t { CONTROL = 0, STREAM };
    struct frame_t {
        frame_type_t type;
        uint16_t data_size;
        void* data;
    };
}

#endif