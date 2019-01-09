#include "aweather.h"
#include <unistd.h>
#include "terminal/tty.h"


int main(int argc, char **argv)
{
    Tty tty;

    Aweather aw(tty);

    while (true) {
        aw.update();
        usleep(100000);
    }

}
