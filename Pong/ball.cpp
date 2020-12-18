#include "ball.h"

void Ball::draw() {
    Game gb;
    int ball = 64;

    gb.gotoxy(x, y);
    rlutil::setColor(15);
    std::cout << (char)ball;
}

void Ball::del() {
    Game gb;

    gb.gotoxy(x, y);
    std::cout << " ";
}

void Ball::move(Paddle left, Paddle right) {
    del();
    x += dx;
    y += dy;
    draw();

    if(x + dx == 1 || x + dx == 100) {
        del();
        assign_coord(50, 12);
        dx = -dx;
    }

    if(y + dy == 1 || y + dy == 25)
        dy = -dy;        

    if(x + dx == left.get_x() && y >= left.get_y() - 2 && y <= left.get_y() + 2) 
        dx = -dx;

    if(x + dx == right.get_x() && y >= right.get_y() - 2 && y <= right.get_y() + 2) 
        dx = -dx;
}