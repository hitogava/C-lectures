#ifndef PACMAN_H
#define PACMAN_H
#define PRINT_DEBUG_INFO
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef unsigned int uint;


struct Coord {
    uint x;
    uint y;
};
struct Player {
    struct Coord coords;
    uint score;
};
struct World {
    uint nTraps;
    uint fieldSize;
    struct Player* player;
    struct Coord* traps;
};
enum DIRECTION {
    LEFT = 4,
    BACK = 5,
    RIGHT = 6,
    FORWARD = 8,
};
enum SYMBOL_COLOR {
    COLOR_DEFAULT,
    COLOR_BLUE,
    COLOR_RED,
    COLOR_GREEN
};
enum SYMBOLS {
    SYMBOL_CELL,
    SYMBOL_FOOD,
    SYMBOL_PACMAN,
    SYMBOL_TRAP
};
uint readUint ();
uint readInstruction ();

void draw (struct World* );
void start (struct World* );
void move (struct World* , enum DIRECTION );
void game ();
struct World* generateWorld ();
void destroyWorld (struct World*);
void generateTraps (struct World*);
bool isTrap (struct Coord, struct World*);
void printColoredSymbol (char ch, enum SYMBOL_COLOR color);
void printDebufInfo (struct World*);

bool isGameOver (struct World* );
void gameOver (struct World* );
#endif
