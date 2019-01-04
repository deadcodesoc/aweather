#include "aweather.h"
#include "weather/snow.h"

Aweather::Aweather()
{
    weather_ = new Snow();
}

Aweather::~Aweather()
{
}
