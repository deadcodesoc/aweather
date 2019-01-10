#ifndef AWEATHER_TERMINAL_TERMINAL_H_
#define AWEATHER_TERMINAL_TERMINAL_H_

struct TerminalSize {
    int lines;
    int cols;
};


class Terminal {
protected:
    TerminalSize size_;

public:
    Terminal();
    virtual ~Terminal();
    int lines() { return size_.lines; }
    int cols() { return size_.cols; }
    virtual void putchar(const char) = 0;
    virtual void flush() = 0;
};

#endif  // AWEATHER_TERMINAL_TERMINAL_H_

