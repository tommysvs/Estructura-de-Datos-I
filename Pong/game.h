#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <vector>
#include <string>
#include "rlutil.h"
#include "keyboard.h"
#include "score.h"
#include "paddle.h"
#include "ball.h"

#define SCRN_W 100
#define SCRN_H 25

enum class GAMESTATE {
    MENU, START, LOSE
};

struct Records {
    int score_left;
    int score_right;
    std::string n_left;
    std::string n_right;
};

class Game {
    private:
        bool left_won, right_won;
        std::vector<std::string> record;

    public:
        Game () {
            left_won = false;
            right_won = false;
        }

        void game_limit();
        void game_menu();
        void game_start();
        void game_lose();
        void save_scores();
        void read_scores();
        
        void draw_line() {
            int i;

            for(i = 2; i <= 24; i++) {
                gotoxy(50, i);
                rlutil::setColor(3);
                std::cout << '|';
            }
        }

        void gotoxy(int x, int y) {
            printf("%c[%d;%df", 0x1B, y, x);
        }
};

#endif
