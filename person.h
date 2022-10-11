#include "position.h"

#ifndef PERSON_H
#define PERSON_H

#define ROW_QTY 10
#define COL_QTY 8

enum types {LOUNGER = 'L', HYPER = 'H', AGGRESSOR = 'A', SCIENTIST = 'S', SPEC_OP = 'O'};

// The base class of Infecteds and Uninfecteds and is abstract
class Person
{
public:
    /** Person object. the base class for infecteds and uninfecteds
     * @parameter pos. the initial position
     * @parameter type. the type of person
     */
    Person(const Position& pos, char type);
    
    /** Gets the current position of the Person
     * @return position. */
    Position getPosition() const;

    /** Gets the type of the person [L, H, A, O, S]
     * @return the type of the Person
     */
    char getType() const; 

    /** Equality operator
     * @parameter other the other person object
     * @return true if this object has the same position as the other and false otherwise */
    bool operator==(const Person& other) const;

    /** Inequality operator
     * @parameter other the other person object
     * @return false if this object has the same position as the other and true otherwise */
    bool operator!=(const Person& other) const;

    /** Moves the Person from the current position to pos. This is a pure virtual function
     * @parameter move determines the direction to move. The default value is 'A' for auto  */
    virtual void move(char move = 'A') = 0; 

    /** Virtual Destructor */
    virtual ~Person();
    
protected:
    Position* pos;
    char type;

private:
    
};

#endif