#ifndef AWEATHER_WEATHER_SNOW_H_
#define AWEATHER_WEATHER_SNOW_H_

#include <vector>
#include "weather/weather.h"
#include "terminal/terminal.h"
#include "frame.h"


class Snowflake {
    char shape_;
    float column_;
    float row_;
    bool falling_;
    float speed_;   // falling speed
    float phase_;   // wobble phase
    float freq_;    // wobble frequency
    float wobble_;  // wobble amount

    bool blocked(Frame&);
public:
    Snowflake() {}
    void fall(Frame&);
    void reset(Frame&);
    int row();
    int column();
    bool falling() { return falling_; }
};

class Snow : public Weather {
    int intensity;
    int temperature;
    std::vector<Snowflake> flakes;
public:
    Snow(Terminal&);
    ~Snow();
    void update() override;
    void fall();
    void reset();
};

#endif  // AWEATHER_WEATHER_SNOW_H_
