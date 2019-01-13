#ifndef AWEATHER_WEATHER_WEATHER_H_
#define AWEATHER_WEATHER_WEATHER_H_

#include "frame.h"


class Weather {
protected:
    Frame& scr_;
public:
    Weather(Frame& scr) : scr_(scr) {}
    virtual ~Weather() {}
    virtual void update() = 0;
};


#endif  // AWEATHER_WEATHER_WEATHER_H_
