#include "aweather.h"
#include "weather/snow.h"


Aweather::Aweather(Terminal& term)
{
    weather_ = new Snow(term);
}

Aweather::~Aweather()
{
}
