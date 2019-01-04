#ifndef AWEATHER_WEATHER_SNOW_H_
#define AWEATHER_WEATHER_SNOW_H_

#include "weather/weather.h"


class Snow : public Weather {
    int intensity;
    int temperature;
public:
    Snow();
    ~Snow();
    void update() override;
};

#endif  // AWEATHER_WEATHER_SNOW_H_
