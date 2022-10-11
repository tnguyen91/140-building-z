#include "building.h"

std::ostream& operator<<(std::ostream& os, const Building& b){
    std::stringstream ss;
    ss << (b.gameState == IN_PLAY ? "Rescue mission in progress\n" : "");
    for (size_t row = 0; row < ROW_QTY; ++row){
        ss << b.getDivider();
        for (size_t col = 0; col < COL_QTY; ++col){
            ss << '|' << b.locations[row][col];
        }
        ss << "|\n";

        for (size_t col = 0; col < COL_QTY; ++col){
            ss << ((b.specOp->getPosition().x == row && b.specOp->getPosition().y == col) ? "| O " : (!b.carrying && b.scientist->getPosition().x == row && b.scientist->getPosition().y == col ? "| S " : "|   "));
        }
        ss << "|\n";
    }

    ss << b.getDivider();
    
    ss << (b.carrying ? "You are carrying scientist.\n" : "");
    std::cout << ss.str();
    return os;
}

std::string Building::getDivider() const{
    std::stringstream ss;
    for (size_t i = 0; i < COL_QTY; ++i){
            ss << "----";
        }
        ss << "-\n";
    return ss.str();
}

Building::Building() : guards{std::vector<Infected*>(INFECTED_QTY)}, specOp {new Uninfected(INIT_POS, SPEC_OP)}, scientist {new Uninfected(initScientistPos(), SCIENTIST)}
{
    initBuilding();
    updateLocations();
    updateGameState();
}

GameStates getGameState(const Building& b){
    return b.gameState;
}

size_t Building::randomRange(int start, int end){
    return rand() % (end - start + 1) + start;
}

void Building::initBuilding(){
    randPositions = {std::vector<Position*>(INFECTED_QTY)};
    locations = {ROW_QTY, std::vector<std::string>(COL_QTY, "")};
    carrying = false;
    gameState = IN_PLAY;
    initRandomPosition();
    initInfected();
}

void Building::initInfected(){
    for (int i = 0; i < INFECTED_QTY; ++i){
        if (i < LOUNGER_QTY) guards[i] = new Lounger(*randPositions[i]);
        else if (i >= INFECTED_QTY - AGGRESSOR_QTY) guards[i] = new Aggressor(*randPositions[i], *specOp);
        else guards[i] = new Hyper(*randPositions[i]);
    }
}

Position Building::initScientistPos(){
    return {randomRange(ROW_QTY / 2 - 1, ROW_QTY / 2), randomRange(COL_QTY / 2 - 1, COL_QTY / 2)};
}

void Building::initRandomPosition(){
    for (size_t i = 0; i < INFECTED_QTY; ++i){
        size_t px; 
        size_t py;
        do{
            px = randomRange(0, ROW_QTY - 1);
            py = randomRange(0, COL_QTY - 1);
        } while (px + py < 2);
        randPositions[i] = new Position(px, py);
        for (size_t j = 0; j < i; ++j){
            if (randPositions[i]->x == randPositions[j]->x && randPositions[i]->y == randPositions[j]->y)
                --i;
        }
    }
}

void Building::initLocations(){
    for (size_t row = 0; row < ROW_QTY; ++row){
        for (size_t col = 0; col < COL_QTY; ++col){
            locations[row][col] = "   ";
        }   
    }
}

void Building::updateLocations(){
    initLocations();
    for (size_t i = 0; i < INFECTED_QTY; ++i){
        if (guards[i]->getType() == LOUNGER) locations[guards[i]->getPosition().x][guards[i]->getPosition().y][0] = LOUNGER;
        if (guards[i]->getType() == HYPER) locations[guards[i]->getPosition().x][guards[i]->getPosition().y][1] = HYPER;
        if (guards[i]->getType() == AGGRESSOR) locations[guards[i]->getPosition().x][guards[i]->getPosition().y][2] = AGGRESSOR;
    }
}

void Building::updateGameState(){
    if (carrying && specOp->getPosition().x == 0 && specOp->getPosition().y == 0)
        gameState = WIN;
    else if (gameState == IN_PLAY){
        for (Infected* i : guards){
            if (*i == *specOp) {
                gameState = LOSE;
                break;
            }
        }
    }
}

void Building::move(char move){
    if (move == 'C'){
        carrying = (*specOp == *scientist ? true : carrying);
    }
    else {
        specOp->move(move);
    }
    for (int i = 0; i < INFECTED_QTY; ++i){
        guards[i]->move();
    }
    updateGameState();
    updateLocations();
}

Building::~Building(){
    specOp->~Uninfected();
    delete specOp;
    scientist->~Uninfected();
    delete scientist;
    for (size_t i = 0; i < INFECTED_QTY; ++i){
        if (guards[i]->getType() == AGGRESSOR){
            guards[i]->~Infected();
        }
        delete guards[i];
    }

}

