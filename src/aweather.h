#ifndef AWEATHER_H_
#define AWEATHER_H_

#include "weather/weather.h"
#include "terminal/terminal.h"


class Aweather {
    Weather *weather_;
    Terminal& term_;
    Frame scr_;
public:
    Aweather(Terminal&);
    ~Aweather();
    void update() { weather_->update(); }
    void draw() { scr_.draw(term_); }
};

#endif  // AWEATHER_H_
