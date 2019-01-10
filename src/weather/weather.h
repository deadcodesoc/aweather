#ifndef AWEATHER_WEATHER_WEATHER_H_
#define AWEATHER_WEATHER_WEATHER_H_

#include "frame.h"


class Weather {
public:
    Weather() {}
    virtual ~Weather() {}
    virtual void update(Frame&) = 0;
};


#endif  // AWEATHER_WEATHER_WEATHER_H_
