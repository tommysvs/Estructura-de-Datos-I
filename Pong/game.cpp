#include "game.h"

static GAMESTATE state;

void Game::game_limit() {
    rlutil::cls();
    rlutil::setColor(3);
    rlutil::hidecursor();

    int i, j, k;

    for (i = 1; i <= SCRN_H; i++) {  
        for (j = 1; j <= SCRN_W; j++) {  
            if (i == 1 || i == SCRN_H || j == 1 || j == SCRN_W)          
                std::cout << "*";    
            else
                std::cout << " "; 
        }  

        std::cout << std::endl; 
    }
}

void Game::game_menu() {
    state = GAMESTATE::MENU;
    game_limit();

    int i, j, option;
    
    rlutil::setColor(3);
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

        for(j = 0; j < 100; j++)
            std::cout << intro[i][j];

        std::cout << "\n";
    }

    rlutil::setColor(15);
    gotoxy(39, 21);
    std::cout << "Press 1 to start playing.";
    
    while(option != 1) {
        gotoxy(49, 23);
        std::cout << "> ";
        std::cin >> option;
    }

    game_start();
}

void Game::game_start() {
    state = GAMESTATE::START;
    game_limit();

    Paddle left(4, 12);
    left.draw();
    Paddle right(97, 12);
    right.draw();
    Ball b(50, 12, 1, 1);
    Score s1(25, 3);
    s1.draw_left();
    Score s2(75, 3);
    s2.draw_right();

    Keyboard k;
    int key;
    int c = 0;

    while(s1.get_left() != 3 && s2.get_right() != 3) {
        if(k.kbhit()) {
            left.del();
            right.del();

            key = k.key();

            if(key == Q && left.get_y() > 3)
                left.move_y(-1);
            else if(key == A && left.get_y() < 23)
                left.move_y(1);

            left.draw();

            if(key == O && right.get_y() > 3)
                right.move_y(-1);
            else if(key == L && right.get_y() < 23)
                right.move_y(1);

            right.draw();
        }

        if(!c) {
            s1.update_left(b.get_x(), b.get_dx());
            s2.update_right(b.get_x(), b.get_dx());
        }

        if(!c++) {
            draw_line();
            b.move(left, right);
        }
        
        if(c > 14000)
            c = 0;

        if(s1.get_left() == 3)
            left_won = true;
        
        if(s2.get_right() == 3)
            right_won = true;
    }

    Records rec;
    rec.score_left = s1.get_left();
    rec.score_right = s2.get_right();
    rec.n_left = "LEFT";
    rec.n_right = "RIGHT";

    std::string record_s = rec.n_left + " " + std::to_string(rec.score_left) + " - " + std::to_string(rec.score_right) + " " + rec.n_right + " | " + get_date();
    if(record.empty()) {
        record.push_back(record_s);
    }

    save_scores();
    game_lose();
}

void Game::game_lose() {
    state == GAMESTATE::LOSE;
    game_limit();

    Score s;
    Keyboard k;

    gotoxy(44, 4); 
    rlutil::setColor(12);
    if(left_won)
        std::cout << "RIGHT LOSE!";
    else if(right_won)
        std::cout << "LEFT LOSE!";

    gotoxy(44, 11);
    rlutil::setColor(15);
    std::cout << "HIGH SCORES";

    read_scores();

    gotoxy(37, 23);
    rlutil::setColor(15);
    std::cout << "Press any key to continue";

    k.getch();
    game_menu();
}

void Game::save_scores() {
    std::ofstream scoresSave("scores.dat", std::ios::app);

    if(!scoresSave) {
        gotoxy(43, 13);
        rlutil::setColor(15);
        std::cout << "Cannot open file.";
        return;
    }

    for(int i = 0; i < record.size(); i++) {
        scoresSave << record[i] << std::endl;
    }

    scoresSave.close();
}

void Game::read_scores() {
    std::ifstream scoresRead("scores.dat", std::ios::in);

    if(!scoresRead) {
        gotoxy(43, 13);
        rlutil::setColor(15);
        std::cout << "Cannot open file.";
        return;
    }

    std::string get_scores;

    if(scoresRead.is_open()) {
        while(std::getline(scoresRead, get_scores)) {
            backwards.push_back(get_scores);
        }
    }

    std::reverse(backwards.begin(), backwards.end());

    std::vector<std::string>::iterator it;
    int i = 0;
    for(it = backwards.begin(); it != backwards.end(); ++it) {
        gotoxy(31, 13 + i);
        std::cout << backwards.at(i);;
        i++;
    }

    scoresRead.close();
}

std::string Game::get_date() {
    time_t tt;
    time(&tt);
    tm TM = *localtime( &tt );

    std::vector<std::string> months = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int year = TM.tm_year + 1900;
    int month = TM.tm_mon;
    int day = TM.tm_mday;

    std::string date;
    date = months[month] + " " + std::to_string(day) + " " + std::to_string(year);

    return date;
}