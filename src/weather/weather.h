#ifndef AWEATHER_WEATHER_WEATHER_H_
#define AWEATHER_WEATHER_WEATHER_H_

#include "terminal/terminal.h"


class Weather {
protected:
    Terminal term_;
public:
    Weather(const Terminal term): term_(term) {}
    virtual ~Weather() {}
    virtual void update() = 0;
};


#endif  // AWEATHER_WEATHER_WEATHER_H_
