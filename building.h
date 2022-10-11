// iostream is only used for the operator<< function.
// Do not print anything directly to cout from this or any other class
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <sstream>

#include "uninfected.h"
#include "lounger.h"
#include "hyper.h"
#include "aggressor.h"

#ifndef BUILDING_H
#define BUILDING_H

#define WINDOWS true
#define INFECTED_QTY 12
#define LOUNGER_QTY 6
#define HYPER_QTY 4
#define AGGRESSOR_QTY 2

#define INIT_POS {0, 0}

enum GameStates {IN_PLAY, WIN, LOSE};

// this class does not provide UI nor does it contain main. 
class Building
{
    /** stream insertion operator overload */
    friend std::ostream& operator<<(std::ostream&, const Building&); 
     
    friend GameStates getGameState(const Building&);

public:
    /** Building constructor. Initializes the Building */ 
    Building();

    /** move the position of the spec-op
     @ parameter move the direction in which the spec-op must move: must be a valid move
     @ throws invalid_argument exception if move is invalid */ 
    void move(char move);

    /** Building destructor. Deletes all heap based objects (including guards) */
    ~Building();
    
    
private:
    std::vector<Infected*> guards;
    Uninfected* specOp;
    Uninfected* scientist;

    std::vector<Position*> randPositions;
    std::vector<std::vector<std::string>> locations;
    bool carrying;
    GameStates gameState;
    std::string getDivider() const;
    size_t randomRange(int, int);
    void initBuilding();
    void initInfected();
    void initRandomPosition();
    void initLocations();
    void updateLocations();
    void updateGameState();
    Position initScientistPos();
};

#endif