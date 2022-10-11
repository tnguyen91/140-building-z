#include "lounger.h"
#include <iostream>

Lounger::Lounger(const Position& pos) : Infected(pos, LOUNGER) {}

void Lounger::move(const char move){
    if (randomRange(1, 5) == 1){
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
}

Lounger::~Lounger(){

}

int Lounger::randomRange(int start, int end){
    return rand() % (end - start + 1) + start;
}