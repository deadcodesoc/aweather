#ifndef AWEATHER_FRAME_H_
#define AWEATHER_FRAME_H_

#include <cstring>
#include <terminal/terminal.h>


class Frame {
    char *buffer_;
    int rows_;
    int columns_;
public:
    Frame(const int rows, const int columns) :
        rows_(rows),
        columns_(columns)
    {
        buffer_ = new char[size()];
    }
    ~Frame() {
        delete [] buffer_;
    }
    char *buffer() { return buffer_; } const
    int rows() { return rows_; } const
    int columns() { return columns_; } const
    int size() { return columns_ * rows_; } const
    void put(const int row, const int col, const char c) {
    }
    void copy(Frame& f) {
        if (rows_ == f.rows() && columns_ == f.columns_) {
            memcpy(buffer_, f.buffer(), size());
        }
    }
    void draw(const Terminal& term) {
    }
};


#endif  // AWEATHER_FRAME_H_
