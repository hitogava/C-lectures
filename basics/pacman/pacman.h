#ifndef PACMAN_H
#define PACMAN_H
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int uint;

struct Coord {
    uint x;
    uint y;
};
struct Player {
    struct Coord coords;
    uint score;
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
const char CELL = '+';
const char FOOD = 'o';
const char PACMAN = '<';
const uint N_TRAPS = 2;
uint read_uint ();
uint read_instruction ();

void draw (struct Player* );
void start ();
void move (struct Player* , enum DIRECTION );
void game ();
void print_colored_symbol (char ch, enum SYMBOL_COLOR color);

bool is_game_over (struct Player* );
void game_over (struct Player* );
#endif
