#ifndef _SCORE_H
#define _SCORE_H

#include "game.h"
#include "ball.h"

class Ball;
class Score {
    private:
        int left, right;
        int x, y;

    public:
        Score() {}

        Score(int _x, int _y) : x(_x), y(_y) { 
            left = 0;
            right = 0;
        }
    
        int get_left() {
            return left;
        }

        int get_right() {
            return right;
        }

        void del();
        void draw_left();
        void draw_right();
        void update_left(int bx, int bdx);
        void update_right(int bx, int bdx);
};

#endif
