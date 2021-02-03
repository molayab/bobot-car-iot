#include "modules/communication/communication.h"
using namespace Communication;

Handler::Handler() {
    buffer = new Buffer();
    frame_size = 0;
    frame_type = 0;
    is_recording = false;
}

Handler::~Handler() {
    delete this->buffer;
}

void Handler::set_receiver(ReceiverProvider* receiver_provider) {
    this->receiver_provider = receiver_provider;
}

void Handler::receive(uint8_t byte) {
    if (COMMUNICATION_FRAME_FLAG == byte && !is_recording) {
        is_recording = true;
        return;
    } else if (is_recording) {
        buffer->writeByte(byte);
        if (buffer->count() == 3 && 0 == frame_type && 0 == frame_size) {
            // We got all frame descriptors, now fill those.
            frame_type = buffer->readByte();
            // MSB FIRST
            uint16_t size = (uint16_t)(buffer->readByte() << 8) | buffer->readByte();
            frame_size = size;
            return;
        } else if ((uint16_t)buffer->count() >= frame_size && frame_size > 0) {
            frame_t frame;
            frame.type = (frame_type_t) frame_type;
            frame.data_size = frame_size;
            frame.data = buffer->unsafe_readAll();
            receiver_provider->receive(frame);
            // TODO: send back an ack or nack.
            reset();
        }
    }
}

void Handler::reset() {
    buffer->clear();
    is_recording = false;
    frame_size = 0;
    frame_type = 0;
}