#include "aweather.h"
#include "weather/snow.h"
#include "frame.h"


Aweather::Aweather(Terminal& term) :
    term_(term),
    scr_(term.lines(), term.cols())
{
    scr_.clear();
    scr_.draw(term_);
    weather_ = new Snow(scr_);
}

Aweather::~Aweather()
{
}
