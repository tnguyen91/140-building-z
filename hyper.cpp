#include "hyper.h"

Hyper::Hyper(const Position& pos) : Infected(pos, HYPER) {}

void Hyper::move(const char move){
    Position oldPos = *pos;
    do {
        switch (randomRange(1, 4)){
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
    } while (oldPos.x == pos->x && oldPos.y == pos->y);
}

Hyper::~Hyper(){}

int Hyper::randomRange(int start, int end){
    return rand() % (end - start + 1) + start;
}