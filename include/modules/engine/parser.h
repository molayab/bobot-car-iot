#ifndef parser_h
#define parser_h

namespace Communication {
    class Buffer;
    class ParserDelegate {
        // virtual void did_receive_frame(frame_t frame) = 0;
    };
    class Parser {
    public:
        Parser(ParserDelegate* delegate);
        void parse(Buffer* buffer);
    protected:
        ParserDelegate* delegate;
    };
}

#endif