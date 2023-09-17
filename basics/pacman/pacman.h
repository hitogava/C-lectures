#ifndef PACMAN_H
#define PACMAN_H
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int uint;

struct Player {
    uint xpos;
    uint ypos;
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
const char FOOD = '*';
const char PACMAN = '<';
const char* COLOR_DEFAULT = "\x1b[0m";
const char* COLOR_RED = "\x1b[1;31m";
uint read_uint ();
uint read_instruction ();

void draw (struct Player* );
void start ();
void move (struct Player* , enum DIRECTION );
void game ();

bool is_game_over (struct Player* );
void game_over (struct Player* );
#endif
