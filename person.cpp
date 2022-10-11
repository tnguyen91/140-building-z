#include "person.h"

Person::Person(const Position& pos, char type) : pos {new Position(pos.x, pos.y)}, type {type}
{
    
}

Position Person::getPosition() const {
    return *pos;
}

char Person::getType() const {
    return type;
}

bool Person::operator==(const Person& other) const {
    return pos->x == other.getPosition().x && pos->y == other.getPosition().y;
}

bool Person::operator!=(const Person& other) const {
    return pos->x != other.getPosition().x || pos->y != other.getPosition().y;
}

Person::~Person(){
    delete pos;
}