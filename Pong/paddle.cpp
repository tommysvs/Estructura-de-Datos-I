#include "paddle.h"
#include "rlutil.h"

void Paddle::draw() {
    Game gp;
    int pad = 35;

    rlutil::setColor(15);

    gp.gotoxy(x, y - 1);
    std::cout << (char)pad;

    gp.gotoxy(x, y);
    std::cout << (char)pad;

    gp.gotoxy(x, y + 1);
    std::cout << (char)pad;
}

void Paddle::del() {
    Game gp;
    gp.gotoxy(x, y - 1);
    std::cout << " ";

    gp.gotoxy(x, y);
    std::cout << " ";

    gp.gotoxy(x, y + 1);
    std::cout << " ";
}