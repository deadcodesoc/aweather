#ifndef AWEATHER_WEATHER_SNOW_H_
#define AWEATHER_WEATHER_SNOW_H_

#include <vector>
#include "weather/weather.h"
#include "terminal/terminal.h"


class SnowFlake {
    char shape;
    float column;
    float row;
    int falling;
    float speed;   // falling speed
    float phase;   // wobble phase
    float freq;    // wobble frequency
    float wobble;  // wobble amount

    friend class Snow;
public:
    SnowFlake() {}
    void reset() {}
};

class Snow : public Weather {
    int intensity;
    int temperature;
    std::vector<SnowFlake> flakes;
public:
    Snow(Terminal&);
    ~Snow();
    void update() override;
};

#endif  // AWEATHER_WEATHER_SNOW_H_
