#include <iostream>
#include "game.h"
#include "paddle.h"
#include "ball.h"

int main() {
    Game g;
    g.game_menu();

    Score s1, s2;
    int p1_s = s1.get_score();
    int p2_s = s2.get_score();

    Paddle p1(5, 12);
    p1.draw();
    Paddle p2(95, 12);
    p2.draw();
    Ball b(50, 12, 1, 1);

    Keyboard k;
    int key;
    int c = 0;

    while(p1_s != 5 || p2_s != 5) {
        if(k.kbhit()) {
            p1.del();
            p2.del();

            key = k.key();

            if(key == Q && p1.get_y() > 6)
                p1.move_y(-1);
            else if(key == A && p1.get_y() < 23)
                p1.move_y(1);

            // if(key == O && p2.get_y() > 6)
            //     p2.move_y(-1);
            // else if(key == L && p2.get_y() < 23)
            //     p2.move_y(1);

            p1.draw();
            // p2.draw();
        }

        if(!c)
            p2.cpu(b.get_x(), b.get_y(), b.get_dx());

        if(!c++)
            b.move(p1, p2);
        
        if(c > 13000)
            c = 0;
    }
}