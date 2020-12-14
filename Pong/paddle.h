#ifndef _PADDLE_H
#define _PADDLE_H

class Paddle {
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

    private:
        Game gp;
        int x, y;
};

#include "paddle.cpp"

#endif