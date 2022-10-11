#include "uninfected.h"

Uninfected::Uninfected(const Position& pos, char type) : Person(pos, type)
{}

void Uninfected::move(const char move){
    if (move == PAUSE){}
    else {
        Position oldPos = *pos;
        switch(move){
            case NORTH:
                *pos = {pos->x - ((pos->x > 0) ? 1 : 0), pos->y};
                break;
            case SOUTH:
                *pos = {pos->x + ((pos->x <  ROW_QTY - 1) ? 1 : 0), pos->y};
                break;
            case WEST:
                *pos = {pos->x, pos->y - ((pos->y > 0) ? 1 : 0)};
                break;
            case EAST:
                *pos = {pos->x, pos->y + ((pos->y < COL_QTY - 1) ? 1 : 0)};
                break;
        }
        if (oldPos.x == pos->x && oldPos.y == pos->y) {
            throw std::runtime_error("Invalid move!");
        }
    }
}

Uninfected::~Uninfected(){
    
}

void Uninfected::carry(){
    
}