#ifndef PACMAN_H
#define PACMAN_H
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int uint;

const char CELL = '+';
const char FOOD = 'o';
const char PACMAN = '<';

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
    struct Player* player;
    struct Coord traps[];
};
enum DIRECTION {
    LEFT = 4,
    BACK = 5,
    RIGHT = 6,
    FORWARD = 8,
};
enum SYMBOL_COLOR {
    DEFAULT,
    BLUE,
    RED,
    GREEN
};
uint readUint ();
uint readInstruction ();

void draw (struct World* );
void start ();
void move (struct World* , enum DIRECTION );
void game ();
struct World* generateWorld ();
void destroyWorld (struct World*);
void printColoredSymbol (char ch, enum SYMBOL_COLOR color);

bool isGameOver (struct World* );
void gameOver (struct World* );
#endif
