#ifndef _PADDLE_H
#define _PADDLE_H

#include "game.h"

class Paddle {
    private:
        int x, y;

    public:
        Paddle(int _x, int _y) : x(_x), y(_y) { }

        void move_y(int _y){
            y += _y;
        }

        int get_y() {
            return y;
        }

        int get_x() {
            return x;
        }

        void draw();
        void del(); 
};

#endif