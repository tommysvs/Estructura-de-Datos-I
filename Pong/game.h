#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include "rlutil.h"
#include "keyboard.h"
#include "score.h"
#include "paddle.h"
#include "ball.h"

#define SCRN_W 100
#define SCRN_H 25

enum class GAMESTATE {
    MENU, PLAYER, CPU, LOSE
};

class Game {
    private:
        Score s1, s2, scpu;

    public:
        void game_limit();
        void game_menu();
        void game_start();
        void game_lose();

        void gotoxy(int x, int y) {
            printf("%c[%d;%df", 0x1B, y, x);
        }
};

#endif
