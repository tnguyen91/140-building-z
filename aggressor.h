#include "position.h"
#include "infected.h"
#include "uninfected.h"

#ifndef AGGRESSOR_H
#define AGGRESSOR_H
// should inherit from Infected
class Aggressor : public Infected
{
public:
    /** Aggressor constructor. Calls Infected constructor with type 'H'
     * @parameter pos is the initial position.
     * @parameter hero is a pointer to the hero object in the castle */
    Aggressor(const Position& pos, const Uninfected& hero);

    /** Moves the Infected. This function overrides in the Infected's pure virtual function
     *  moves this Infected towards the spec-op either in the x or y direction.
     * @parameter move determines the  position to move to. 
     *            Defaults to 'A' for auto */
    void move(const char move = 'A'); 

    /** Destructor */
    ~Aggressor();
    
protected:

private:
    const Uninfected* hero;
    int randomRange(int, int);
    Position getRandMove();
    bool sense();
    bool closer(const Position&);
    void chase();
};

#endif