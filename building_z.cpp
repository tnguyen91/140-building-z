// who: Tu Nguyen
// what: Lab exam 3
// why: Building Z
// when: 5/29/2022

// includes go here
#include <iostream>
#include "building.h"

#define MOVES_QTY 6

void clearScreen();
void play(Building&);
char getValidMove();
bool isInvalidMove(char);

int main(int argc, char const *argv[])
{
   
	// your code goes here
    srand(static_cast<unsigned int> (time(0)));
	Building b;
    play(b);
	return 0;
}

void clearScreen()
{
    if(WINDOWS)
        system("CLS");
    else
        system("clear");  
}

void play(Building& b){
    GameStates s = getGameState(b);

    while(s == IN_PLAY){
        clearScreen();
        s = getGameState(b);
        std::cout << b;
        try
        {
            if (s == IN_PLAY) b.move(getValidMove());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            b.move(getValidMove());
        }
    };
    if (s == WIN){
        std::cout << "You have successfully rescued scientist!\n";
        b.~Building();
    }
    else if (s == LOSE){
        std::cout << "You have failed to rescue scientist!\n";
        b.~Building();
    }
}
char getValidMove(){
    char c;
    try
    {
        std::cout << "Your move [N,S,W,E,P,C]: ";
        std::cin >> c;
        if (isInvalidMove(toupper(c)))  throw std::invalid_argument("Invalid move!");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        c = getValidMove();
    }
    return toupper(c);
}

bool isInvalidMove(char c){
    char move[MOVES_QTY] = {'N', 'S', 'W', 'E', 'P', 'C'};
    for (int i = 0; i < MOVES_QTY; ++i){
        if (move[i] == c)
        return false;
    }
    return true;
}