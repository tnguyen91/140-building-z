#include "person.h"
#include "position.h"
#include <stdexcept>

#ifndef UNINFECTED_H
#define UNINFECTED_H



// should inherit from Person
class Uninfected : public Person
{
public:
    /** Uninfected constructor. Calls person constructor  
     * @parameter pos is the initial position. 
     * @parameter type is the type of person. */
    Uninfected(const Position& pos, char type);

    /** Moves the Uninfected based on the pos argument. 
     *  This function overrides the person class' pure virtual function
     * @parameter move determines the updated position to move to. Moves: [N, S, E, W, P, C]
     * throws invalid_argument exception if pos is an invalid move */
    void move(const char move); 

    /** Destructor */
    ~Uninfected();
    
protected:

private:
    enum specOpMoves {NORTH = 'N', SOUTH = 'S', WEST = 'W', EAST = 'E', PAUSE = 'P'};
    void carry();
};

#endif