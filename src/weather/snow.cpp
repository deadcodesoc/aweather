#include "snow.h"
#include <cmath>
#include "frame.h"


Snow::Snow(Terminal& term) : Weather(term)
{
}

Snow::~Snow()
{
}

void Snow::update()
{
    Frame fg(term_.lines(), term_.cols());
    Frame scr(term_.lines(), term_.cols());

    for (auto s : flakes) {
        int column = (int)floorf(s.column + s.wobble * sinf(s.phase));

        if (s.falling) {
            fg.put(column, (int)floorf(s.row), s.shape);
            s.row += s.speed;
            s.phase += s.freq;
        } else {
            s.reset();
        }
    }

    scr.copy(fg);
    scr.draw(term_);
}
