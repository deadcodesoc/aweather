#include "aweather.h"
#include "weather/snow.h"
#include "frame.h"


Aweather::Aweather(Terminal& term) :
    term_(term),
    scr_(term.lines(), term.cols())
{
    weather_ = new Snow();
}

Aweather::~Aweather()
{
}
