#ifndef AWEATHER_FRAME_H_
#define AWEATHER_FRAME_H_

#include <cstring>
#include <vector>
#include <terminal/terminal.h>


constexpr char Blank = ' ';

class Frame {
    std::vector<char> buffer_;
    int rows_;
    int columns_;
public:
    Frame(const int rows, const int columns) :
        rows_(rows),
        columns_(columns),
        buffer_(size())
    {
    }
    ~Frame() {
    }
    std::vector<char> buffer() { return buffer_; } const
    int rows() { return rows_; } const
    int columns() { return columns_; } const
    int size() { return columns_ * rows_; } const
    void put(const int row, const int col, const char c) {
        buffer_[row * columns_ + col] = c;
    }
    char get(const int row, const int col) {
        return buffer_[row * columns_ + col];
    }
    void clear() {
        std::fill(buffer_.begin(), buffer_.end(), ' ');
    }
    void copy(Frame& f) {
        if (rows_ == f.rows() && columns_ == f.columns_) {
            buffer_ = f.buffer();
        }
    }
    void draw(Terminal& term) {
        for (auto c : buffer_) {
            term.putchar(c);
        }
        term.putchar('\r');
        term.flush();
    }
};


#endif  // AWEATHER_FRAME_H_
