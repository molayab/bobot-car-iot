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
    /*class FrameBuffer {
    public:
        ~FrameBuffer(); // Destroy all memory used for store the frames.
        void write(frame_type_t frame); // Copy the frame in a private one.
        const frame_type_t* readNext(); // Dequeue a frame.
        bool isEmpty(); // Checks if buffer is empty.

    private:
        std::vector<frame_type_t *> queue;
        void priorize(frame_type_t frame); // Priorizes the frame.
    };*/
}

#endif