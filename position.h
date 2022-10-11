#include <stddef.h>

#ifndef POSITION_H
#define POSITION_H

struct Position
{
    size_t x;
    size_t y;
    
    Position(size_t x, size_t y) :x{x}, y{y} {}
    Position(Position& other) :x{other.x}, y{other.y} {}
};

#endif