#include "score.h"
#include "rlutil.h"

void Score::del() {
    Game gs;

    gs.gotoxy(x, y);
    std::cout << " ";
}

void Score::draw_left() {
    Game gs;

    gs.gotoxy(x, y);
    rlutil::setColor(15);
    std::cout << get_left();
}

void Score::draw_right() {
    Game gs;

    gs.gotoxy(x, y);
    rlutil::setColor(15);
    std::cout << get_right();
}

void Score::update_left(int bx, int bdx) {
    if(bx + bdx == 99) {
        del();
        left++;
        draw_left();
    }
}

void Score::update_right(int bx, int bdx) {
    if(bx + bdx == 2) {
        del();
        right++;
        draw_right();
    }
}