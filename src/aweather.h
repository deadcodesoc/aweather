#ifndef AWEATHER_H_
#define AWEATHER_H_

#include "weather/weather.h"


class Aweather {
    Weather *weather_;
public:
    Aweather();
    ~Aweather();
    void update() { weather_->update(); }
};

#endif  // AWEATHER_H_
