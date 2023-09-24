#include "pacman.h"

const char* COLOR_DEFAULT = "\x1b[0m";
const char* COLOR_RED = "\x1b[1;31m";
const char* COLOR_GREEN = "\x1b[1;32m";
const char* COLOR_BLUE = "\x1b[1;34m";

uint FIELD_SIZE;
uint FOOD_X;
uint FOOD_Y;
uint read_uint () {
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
void print_colored_symbol (char ch, enum SYMBOL_COLOR color) {
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
void draw (struct Player* player) {
    assert(player->coords.x < FIELD_SIZE && player->coords.y < FIELD_SIZE);
    system("clear");
    printf("\n");
    for (size_t x = 0; x < FIELD_SIZE; x++) {
        for (size_t y = 0; y < FIELD_SIZE; y++) {
            if (x == FIELD_SIZE - player->coords.y - 1 && y == player->coords.x) { 
                print_colored_symbol(PACMAN, GREEN);
            } else if (x == 0 && y == FIELD_SIZE-1) {
                print_colored_symbol(FOOD, BLUE);
            } else {
                print_colored_symbol(CELL, DEFAULT);
            }
        }
        printf("\n");
    }
    printf("\n");
}
uint read_instruction () {
    printf("%s", COLOR_DEFAULT);
    puts("Enter the instruction:");
    uint ins = read_uint();
    if (ins != LEFT && ins != BACK && ins!=RIGHT && ins!=FORWARD) {
        puts("Invalid instruction, exit");
        exit(0);
    }
    return ins;
}
void start () {
    puts("Enter the size of field:");
    FIELD_SIZE = read_uint();
    if (FIELD_SIZE  < 2) {
        puts("N should be at least 2\n");
        exit(0);
    }
    FOOD_X = FIELD_SIZE - 1;
    FOOD_Y = FIELD_SIZE - 1;
}
void move (struct Player* player, enum DIRECTION dir) {
    assert(player->coords.x < FIELD_SIZE && player->coords.y < FIELD_SIZE);
    switch (dir) {
        case LEFT:
            if (player->coords.x != 0) {
                player->coords.x--;
            } break;
        case BACK:
            if (player->coords.y != 0) {
                player->coords.y--;
            } break;
        case RIGHT:
            if (player->coords.x != FIELD_SIZE - 1) {
                player->coords.x++;
            } break;
        case FORWARD:
            if (player->coords.y != FIELD_SIZE - 1) {
                player->coords.y++;
            } break;
    }
    player->score++;
}

bool is_game_over (struct Player* player) {
    return player->coords.x == FOOD_X && player->coords.y == FOOD_Y;
}

void game_over (struct Player* player) {
    printf("GAME OVER!\nYour score: %u\n", player->score);
}

void game () {
    struct Player player = {.coords = {.x = 0, .y = 0}, .score = 0};
    start();
    draw(&player);
    while (!is_game_over(&player)) {
        uint ins = read_instruction();
        move(&player, ins);
        draw(&player);
    }
    game_over(&player);
}

int main (int argc, char** argv) {
    game();
    return EXIT_SUCCESS;
}
