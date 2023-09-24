#include "pacman.h"
#include <stdlib.h>

const char* COLOR_DEFAULT = "\x1b[0m";
const char* COLOR_RED = "\x1b[1;31m";
const char* COLOR_GREEN = "\x1b[1;32m";
const char* COLOR_BLUE = "\x1b[1;34m";

uint FIELD_SIZE;
uint FOOD_X;
uint FOOD_Y;
uint readUint () {
    int value;
    int argc = scanf("%d", &value);
    if (argc != 1 || value < 0) {
        puts("Wrong unsigned int value");
        exit(0);
    } else {
        value = (uint) value;
    }
    assert(value >= 0);
    return value;
}
void printColoredSymbol (char ch, enum SYMBOL_COLOR color) {
    switch(color) {
        case DEFAULT:
            printf("%s%c ", COLOR_DEFAULT, ch);
            break;
        case RED:
            printf("%s%c%s ", COLOR_RED, ch, COLOR_DEFAULT);
            break;
        case BLUE:
            printf("%s%c%s ", COLOR_BLUE, ch, COLOR_DEFAULT);
            break;
        case GREEN:
            printf("%s%c%s ", COLOR_GREEN, ch, COLOR_DEFAULT);
            break;
    }
}
void draw (struct World* world) {
    assert(world->player->coords.x < FIELD_SIZE && world->player->coords.y < FIELD_SIZE);
    system("clear");
    printf("\n");
    for (size_t x = 0; x < FIELD_SIZE; x++) {
        for (size_t y = 0; y < FIELD_SIZE; y++) {
            if (x == FIELD_SIZE - world->player->coords.y - 1 && y == world->player->coords.x) { 
                printColoredSymbol(PACMAN, GREEN);
            } else if (x == 0 && y == FIELD_SIZE-1) {
                printColoredSymbol(FOOD, BLUE);
            } else {
                printColoredSymbol(CELL, DEFAULT);
            }
        }
        printf("\n");
    }
    printf("\n");
}
uint readInstruction () {
    printf("%s", COLOR_DEFAULT);
    puts("Enter the instruction:");
    uint ins = readUint();
    if (ins != LEFT && ins != BACK && ins!=RIGHT && ins!=FORWARD) {
        puts("Invalid instruction, exit");
        exit(0);
    }
    return ins;
}
void start () {
    puts("Enter the size of field:");
    FIELD_SIZE = readUint();
    if (FIELD_SIZE  < 2) {
        puts("N should be at least 2\n");
        exit(0);
    }
    FOOD_X = FIELD_SIZE - 1;
    FOOD_Y = FIELD_SIZE - 1;
}
void move (struct World* world, enum DIRECTION dir) {
    assert(world->player->coords.x < FIELD_SIZE && world->player->coords.y < FIELD_SIZE);
    switch (dir) {
        case LEFT:
            if (world->player->coords.x != 0) {
                world->player->coords.x--;
            } break;
        case BACK:
            if (world->player->coords.y != 0) {
                world->player->coords.y--;
            } break;
        case RIGHT:
            if (world->player->coords.x != FIELD_SIZE - 1) {
                world->player->coords.x++;
            } break;
        case FORWARD:
            if (world->player->coords.y != FIELD_SIZE - 1) {
                world->player->coords.y++;
            } break;
    }
    world->player->score++;
}

bool isGameOver (struct World* world) {
    return world->player->coords.x == FOOD_X && world->player->coords.y == FOOD_Y;
}

void gameOver (struct World* world) {
    printf("GAME OVER!\nYour score: %u\n", world->player->score);
    destroyWorld(world);
}
struct World* generateWorld () {
    struct Player* player = (struct Player*) malloc(sizeof(struct Player));
    if (!player) {
        puts ("Memory allocation error");
        exit(0);
    }
    *player = (struct Player) {.coords = {.x = 0, .y = 0}, .score = 0};
    struct World* world = (struct World*) malloc (sizeof(struct World));
    if (!world) {
        puts ("Memory allocation error");
        exit(0);
    }
    *world = (struct World) { .player = player, .nTraps = 2};
    return world;
}
void destroyWorld(struct World* world) {
    if (world) {
        if (world->player) {
            free(world->player);
            world->player = NULL;
        }
        free(world);
        world = NULL;
    }
}
void game () {
    struct World* world = generateWorld();
    start();
    draw(world);
    while (!isGameOver(world)) {
        uint ins = readInstruction();
        move(world, ins);
        draw(world);
    }
    gameOver(world);
}

int main (int argc, char** argv) {
    game();
    return EXIT_SUCCESS;
}
