#include "snow.h"
#include <cmath>
#include <cstdlib>
#include "frame.h"


namespace {

char SnowShape[5] = { '.', '+', '*', 'x', 'X' };

float randf(const float x)
{
    return static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / x));
}

template<size_t SIZE, class T>
inline size_t array_size(T(&arr)[SIZE]) {
    return SIZE;
}

}  // namespace


Snow::Snow(Frame& scr) :
    Weather(scr),
    fg_(scr.rows(), scr.columns())
{
    intensity_ = scr.columns() / 10;
    flakes_.resize(MaxIntensity);
    for (int i = 0; i < intensity_; i++) {
        flakes_[i].reset(scr.columns());
    }
}

Snow::~Snow()
{
}

void Snow::update()
{
    fg_.clear();

    for (int i = 0; i < intensity_; i++) {
        flakes_[i].fall(fg_);
    }

    scr_.copy(fg_);
}

// ------------------------------------------------------------------

Snowflake::Snowflake()
{
}

Snowflake::~Snowflake()
{
}

void Snowflake::fall(Frame& fr)
{
    if (blocked(fr)) {
        falling_ = false;
        if (row() != 0) {
            fr.put(row(), column(), shape_);
        }
    } else if (falling_) {
        fr.put(row(), column(), shape_);
        row_ += speed_;
        phase_ += freq_;
    } else {
        reset(fr.columns());
    }
}

void Snowflake::reset(const int columns)
{
    shape_ = SnowShape[rand() % array_size(SnowShape)];
    column_ = randf(columns);
    row_ = 0.0f;
    falling_ = true;
    speed_ = 0.3f + randf(1.2f);
    phase_ = randf(2.0f * M_PI);
    freq_ = randf(0.2f);
    wobble_ = 0.5f + randf(3.5f);
}

bool Snowflake::blocked(Frame& fr)
{
    const int row = (int)floorf(row_);
    const int speed = (int)ceilf(speed_);

    // Block if we're at the bottom of the frame
    if (row >= fr.rows() - 1) {
        row_ = fr.rows() - 1;
        return true;
    }

    for (int i = 1; i <= speed; i++) {
        // Block if we have an obstacle directly below us
        if (fr.get(column(), row + i) != Blank) {
            row_ += i - 1;
            return true;
        }
    }

    return false;
}
