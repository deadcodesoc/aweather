#ifndef AWEATHER_WEATHER_SNOW_H_
#define AWEATHER_WEATHER_SNOW_H_

#include <vector>
#include <cmath>
#include "weather/weather.h"
#include "frame.h"


constexpr int MaxIntensity = 100;

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
    Snowflake();
    ~Snowflake();
    void fall(Frame&);
    void reset(const int);
    int row() { return (int)floorf(row_); }
    int column() { return (int)floorf(column_ + wobble_ * sinf(phase_)); }
    bool falling() { return falling_; }
};

class Snow : public Weather {
    int intensity_;
    int temperature_;
    std::vector<Snowflake> flakes_;
    Frame fg_;
public:
    Snow(Frame&);
    ~Snow();
    void update() override;
    void fall();
    void reset();
    void set_intensity(const int val) { intensity_ = val; }
};

#endif  // AWEATHER_WEATHER_SNOW_H_
