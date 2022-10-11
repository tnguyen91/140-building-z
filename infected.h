#include "person.h"
#include "position.h"
#include <stdlib.h>

#ifndef INFECTED_H
#define INFECTED_H

enum moves {NORTH = 1, SOUTH = 2, WEST = 3, EAST = 4};

// should inherit from Person but be an abstract class
class Infected : public Person
{
public:
    /** Infected constructor. Calls person constructor  
     * @parameter pos is the initial position. 
     * @parameter type is the type of person. */
    Infected(const Position& pos, char type);

    /** Moves the Infected. This is a pure virtual function which is overrriden in the derived Infecteds
     * @parameter move determines the  position to move to. Should be a pure virtual function, 
     *            Defaults to 'A' for auto */
    virtual void move(char move = 'A') = 0;
    
    /** Virtual Destructor */
    virtual ~Infected(); 

protected:
    
private:
};

#endif