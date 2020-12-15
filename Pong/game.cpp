static GAMESTATE state;

void Game::game_limit() {
    clear();

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

    if(state == GAMESTATE::START) {
        gotoxy(2, 4);
        for(k = 1; k < SCRN_W - 1; k++) {
            std::cout << "-";
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
    std::cout << "2. Quit game.";
    gotoxy(50, 23);
    std::cout << "> ";
    std::cin >> option;

    if(option == 1) 
        game_start();
    else if(option == 2) {
        close();
        clear();
    }
}

void Game::game_start() {
    state = GAMESTATE::START;

    hide();
    game_limit();

    gotoxy(47, 2);
    std::cout << "SCORES";

    gotoxy(30, 3);
    std::cout << "Player 1:";
    gotoxy(60, 3);
    std::cout << "Player 2:";
}

void Game::game_lose() {
    state = GAMESTATE::LOSE;
    int p1_s = s1.get_score();
    int p2_2 = s2.get_score();

    game_limit();
    
    gotoxy(12, 40);
    if(p1_s == 5)
        std::cout << "Player 1 LOSE!";
    else if(p2_2 == 5)
        std::cout << "Player 2 LOSE!";
}