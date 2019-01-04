#include "tty.h"
#include <string>
#include <stdexcept>
#include <cerrno>
#include <cstring>
#include <sys/ioctl.h>
#include <unistd.h>


Tty::Tty()
{
    struct winsize ws;
 
    if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) < 0) {
        throw std::runtime_error(std::string(std::strerror(errno)));
    }

    size_.lines = ws.ws_row;
    size_.cols = ws.ws_col;
}

Tty::~Tty()
{
}
