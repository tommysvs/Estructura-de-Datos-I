#ifndef _BALL_H
#define _BALL_H

class Ball {
    public:
        Ball(int _x, int _y, int _dx, int _dy) : x(_x), y(_y), dx(_dx), dy(_dy) { }

        void draw();
        void del();
        void move(Paddle p1, Paddle p2);

        void assign_coord(int _x, int _y) {
            x = _x;
            y = _y;
        }

    private:
        Game gb;
        int x, y, dx, dy;
};

#include "ball.cpp"

#endif