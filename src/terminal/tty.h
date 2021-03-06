#ifndef AWEATHER_TERMINAL_TTY_H_
#define AWEATHER_TERMINAL_TTY_H_

#include "terminal/terminal.h"


class Tty : public Terminal {
public:
    Tty();
    ~Tty();
    void putchar(const char) override;
    void clear() override {};
    void flush() override;
};

#endif  // AWEATHER_TERMINAL_TTY_H_
