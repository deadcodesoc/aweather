#ifndef AWEATHER_H_
#define AWEATHER_H_

#include "weather/weather.h"
#include "terminal/terminal.h"


class Aweather {
    Weather *weather_;
public:
    Aweather(Terminal);
    ~Aweather();
    void update() { weather_->update(); }
};

#endif  // AWEATHER_H_
