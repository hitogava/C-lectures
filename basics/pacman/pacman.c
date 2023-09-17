#include "pacman.h"

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
void draw (struct Player* player) {
    assert(player->xpos < FIELD_SIZE && player->ypos < FIELD_SIZE);
    system("clear");
    printf("\n");
    for (size_t x = 0; x < FIELD_SIZE; x++) {
        for (size_t y = 0; y < FIELD_SIZE; y++) {
            if (x == FIELD_SIZE - player->ypos - 1 && y == player->xpos) { 
                print_colored_symbol(PACMAN, GREEN);
            } else if (x == 0 && y == FIELD_SIZE-1) {
                print_colored_symbol(FOOD, RED);
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
    if (ins != 4 && ins != 5 && ins!=6 && ins!=8) {
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
    assert(player->xpos < FIELD_SIZE && player->ypos < FIELD_SIZE);
    switch (dir) {
        case 4:
            if (player->xpos != 0) {
                player->xpos--;
            } break;
        case 5:
            if (player->ypos != 0) {
                player->ypos--;
            } break;
        case 6:
            if (player->xpos != FIELD_SIZE - 1) {
                player->xpos++;
            } break;
        case 8:
            if (player->ypos != FIELD_SIZE - 1) {
                player->ypos++;
            } break;
    }
    player->score++;
}

bool is_game_over (struct Player* player) {
    return player->xpos == FOOD_X && player->ypos == FOOD_Y;
}

void game_over (struct Player* player) {
    printf("GAME OVER!\nYour score: %u\n", player->score);
}

void game () {
    struct Player player = { 0 };
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
    puts("123");
    return EXIT_SUCCESS;
}
