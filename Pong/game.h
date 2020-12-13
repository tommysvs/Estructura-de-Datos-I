#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include "ball.h"
#include "paddle.h"
#include "keyboard.h"

#define SCRN_W 120
#define SCRN_H 40

enum class GAMESTATE {
    MENU, START, LOSE
};

template <typename T>
class Game {
    public:
        void game_limit();
        void game_menu();
        void game_start();

        void clear() { system("clear"); }
        void close() { system("exit"); }

        void gotoxy(int x, int y) {
            printf("%c[%d;%df", 0x1B, y, x);
        }

    private:
        char up1, down1, up2, down2;
        bool quit;
        Ball *ball;
        Paddle *player1;
        Paddle *player2;
};

#include "game.cpp"

#endif
