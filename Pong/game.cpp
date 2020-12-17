#include "game.h"

static GAMESTATE state;

Score s1, s2, scpu;
int p1_s = s1.get_sp1();
int p2_s = s2.get_sp2();
int cpu_s = scpu.get_scpu();

void Game::game_limit() {
    rlutil::cls();

    int i, j, k, l; 

    for (i = 1; i <= SCRN_H; i++) {  
        for (j = 1; j <= SCRN_W; j++) {  
            if (i == 1 || i == SCRN_H || j == 1 || j == SCRN_W)          
                std::cout << "*";              
            else
                std::cout << " "; 
        }  

        std::cout << std::endl; 
    }

    if(state == GAMESTATE::PLAYER || state == GAMESTATE::CPU) {
        gotoxy(47, 2);
        std::cout << "SCORES";

        gotoxy(2, 4);
        for(k = 1; k < SCRN_W - 1; k++) {
            std::cout << "-";
        }

        if(state == GAMESTATE::PLAYER) {
            gotoxy(30, 3);
            std::cout << "Player 1: " << p1_s;
            gotoxy(60, 3);
            std::cout << "Player 2: " << p2_s;
        }else if(state == GAMESTATE::CPU) {
            gotoxy(30, 3);
            std::cout << "Player: " << p1_s;
            gotoxy(60, 3);
            std::cout << "CPU: " << cpu_s;
        }
    }
}

void Game::game_menu() {
    state = GAMESTATE::MENU;
    game_limit();

    int i, j, option;
    
    char intro[15][100] = {
        "     █████████                              ",
        "   █████████████                            ",
        "   ██       ████                            ",
        "   ██       ████                            ",
        "   ██       ████                            ",
        "   ████████████                             ",
        "   ██████████                               ",
        "   ████                                     ",
        "   ████    █████    ████   ███   ██████     ",
        "   ████  ██    ███  █████  ███  ██    ██    ",
        "   ████  ██    ███  ███ ██ ███  ██          ",
        "   ████  ██    ███  ███  █████  ██  ████    ",
        "   ████  ██    ███  ███   ████  ██    ███   ",
        "   ████  ██    ███  ███    ███  █████████   ",
        "   ████    █████    ███    ███   █████ █    "
    };

    for(i = 0; i < 15; i++) {
        gotoxy(30, i + 4);

        for(j = 0; j < 100; j++) {
            std::cout << intro[i][j];
        }

        std::cout << "\n";
    }

    gotoxy(32, 21);
    std::cout << "1. Start playing.";
    gotoxy(56, 21);
    std::cout << "2. Play with CPU.";
    
    while(option != 1 && option != 2) {
        gotoxy(50, 23);
        std::cout << "> ";
        std::cin >> option;
    }

    if(option == 1) 
        state = GAMESTATE::PLAYER;
    else if(option == 2)
        state = GAMESTATE::CPU;

    game_start();
}

void Game::game_start() {
    rlutil::hidecursor();
    game_limit();

    Paddle p1(5, 12);
    p1.draw();
    Paddle p2(95, 12);
    p2.draw();
    Ball b(50, 12, 1, 1);

    Keyboard k;
    int key;
    int c = 0;

    while(p1_s != 3 || p2_s != 3 || cpu_s != 3) {
        if(k.kbhit()) {
            p1.del();
            p2.del();

            key = k.key();

            if(key == Q && p1.get_y() > 6)
                p1.move_y(-1);
            else if(key == A && p1.get_y() < 23)
                p1.move_y(1);

            p1.draw();

            if(state == GAMESTATE::PLAYER) {
                if(key == O && p2.get_y() > 6)
                    p2.move_y(-1);
                else if(key == L && p2.get_y() < 23)
                    p2.move_y(1);

                p2.draw();
            }
        }

        if(state == GAMESTATE::CPU) {
            if(!c)
                p2.cpu(b.get_x(), b.get_y(), b.get_dx());
        }
      
        if(!c++)
            b.move(p1, p2);
        
        if(c > 13000)
            c = 0;
    }

    if(p1_s == 3 || p2_s == 3 || cpu_s == 3)
        game_lose();
}

void Game::game_lose() {
    state == GAMESTATE::LOSE;
    

}