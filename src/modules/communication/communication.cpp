#include "modules/communication/communication.h"
using namespace Communication;

Handler::Handler() {
    this->buffer = new Buffer();
    this->frame_size = 0;
    this->frame_type = 0;
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
            this->frame_type = buffer->readByte();
            uint8_t size = (buffer->readByte() << 8) | buffer->readByte(); // MSB ??
            this->frame_size = size;
            return;
        }
        if ((uint16_t)buffer->count() - 3 >= this->frame_size) {
            is_recording = false;
            frame_t frame;
            frame.type = (frame_type_t) this->frame_type;
            frame.data_size = this->frame_size;
            frame.data = buffer->unsafe_readAll();
            receiver_provider->receive(frame);
        }
    }
}