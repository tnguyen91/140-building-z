#include "aggressor.h"

Aggressor::Aggressor(const Position& pos, const Uninfected& hero) : Infected(pos, AGGRESSOR), hero {new Uninfected(hero)}
{
}

void Aggressor::move(const char move){
    if (sense()) 
        chase();
    else *pos = getRandMove();
}

Position Aggressor::getRandMove(){
    Position newPos = *pos;
    do{
        switch(randomRange(1, 4)){
            case NORTH:
                newPos = {newPos.x - ((newPos.x > 0) ? 1 : 0), newPos.y};
                break;
            case SOUTH:
                newPos = {newPos.x + ((newPos.x < ROW_QTY - 1) ? 1 : 0), newPos.y};
                break;
            case WEST:
                newPos = {newPos.x, newPos.y - ((newPos.y > 0) ? 1 : 0)};
                break;
            case EAST:
                newPos = {newPos.x, newPos.y + ((newPos.y < COL_QTY - 1) ? 1 : 0)};
                break;
        }
    } while(newPos.x == pos->x && newPos.y == pos->y);
    return newPos;
}

bool Aggressor::sense(){
    if (pos->x == hero->getPosition().x && (pos->y + (COL_QTY - 1 - pos->y > 2 ? 2 : (COL_QTY - 1 - pos->y))) - hero->getPosition().y <= 4){
        return true;
    }
    if (pos->y == hero->getPosition().y && (pos->x + (ROW_QTY - 1 - pos->x > 2 ? 2 : (ROW_QTY - 1 - pos->x))) - hero->getPosition().x <= 4){
        return true;
    }
    if (pos->x + 1 == hero->getPosition().x && pos->y + 1 == hero->getPosition().y || pos->x - 1 == hero->getPosition().x && pos->y - 1 == hero->getPosition().y){
        return true;
    }
    if (pos->x - 1 == hero->getPosition().x && pos->y + 1 == hero->getPosition().y || pos->x + 1 == hero->getPosition().x && pos->y - 1 == hero->getPosition().y){
        return true;
    }
    return false;
}

void Aggressor::chase(){
    Position newPos = *pos;
    do{
        newPos = *pos;
        newPos = getRandMove();
    } while(!closer(newPos));
    *pos = newPos;
}

bool Aggressor::closer(const Position& newPos){
    if (newPos.x == hero->getPosition().x && abs(static_cast<int>(newPos.y - hero->getPosition().y)) <= 2)
        return true;
    if (newPos.y == hero->getPosition().y && abs(static_cast<int>(newPos.x - hero->getPosition().x)) <= 2)
        return true;
    
    return false;
}

int Aggressor::randomRange(int start, int end){
    return rand() % (end - start + 1) + start;
}

Aggressor::~Aggressor(){
    delete hero;
}