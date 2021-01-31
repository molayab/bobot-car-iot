#ifndef communication_h
#define communication_h
#ifndef COMMUNICATION_FRAME_FLAG
#define COMMUNICATION_FRAME_FLAG 0xDF
#endif
#include <Arduino.h>
#include <ArduinoSTL.h>
#include <vector>

namespace Communication {
    class BufferDelegate {
        virtual void did_receive_frame(frame_type_t frame) = 0;
    };
    class Buffer {
    public:
        Buffer(Parser* parser, BufferDelegate* delegate);
        void writeByte(uint8_t byte);
    
    private:
        std::vector<uint8_t> buffer;
        bool is_recording;
        uint16_t frame_size;
        uint8_t frame_type;
    };
    class Parser {
        frame_type_t get_frame_from_buffer(Buffer* buffer);
    };
    class Interpreter: public BufferDelegate {
        void execute(frame_type_t frame);
    };
    class FrameBuffer {
    public:
        ~FrameBuffer(); // Destroy all memory used for store the frames.
        void write(frame_type_t frame); // Copy the frame in a private one.
        const frame_type_t* readNext(); // Dequeue a frame.
        bool isEmpty(); // Checks if buffer is empty.

    private:
        std::vector<frame_type_t *> queue;
        void priorize(frame_type_t frame); // Priorizes the frame.
    };

    enum frame_type_t { CONTROL = 0, STREAM };
    struct frame_t {
        frame_type_t type;
        uint16_t data_size;
        void* data;
    };
}

#endif