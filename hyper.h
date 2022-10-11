#include "person.h"
#include "position.h"
#include "infected.h"

#ifndef HYPER_H
#define HYPER_H

// should inherit from Guard
class Hyper : public Infected
{
public:
    /** Hyper constructor. Calls Infected constructor with type 'H'
     * @parameter pos is the initial position.*/
    Hyper(const Position& pos);

    /** Moves the Infected. This function overrides in the Infected's pure virtual function
     *  moves this Infected in a random direction.
     * @parameter move determines the  position to move to. 
     *            Defaults to 'A' for auto */
    void move(const char move = 'A');

    /** Destructor */
    ~Hyper();
    
protected:

private:
    int randomRange(int, int);
};

#endif