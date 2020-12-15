#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include "keyboard.h"
#include "score.h"

#define SCRN_W 100
#define SCRN_H 25

enum class GAMESTATE {
    MENU, START, LOSE
};

class Game {
    private:
        Score s1, s2;

    public:
        void game_limit();
        void game_menu();
        void game_start();
        void game_lose();

        void clear() { system("clear"); }
        void close() { system("exit"); }
        void hide() { system("setterm -cursor off"); }

        void gotoxy(int x, int y) {
            printf("%c[%d;%df", 0x1B, y, x);
        }
};

#include "game.cpp"

#endif
