using namespace std;

static GAMESTATE state;

template<typename T>
void Game<T>::game_limit() {
    int i, j;  

    for (i = 1; i <= SCRN_H; i++) {  
        for (j = 1; j <= SCRN_W; j++) {  
            if (i == 1 || i == SCRN_H || j == 1 || j == SCRN_W)          
                cout << "*";              
            else
                cout << " "; 
        }  

        cout << endl; 
    }  
}

template <typename T>
void Game<T>::game_menu() {
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
        gotoxy(40, i + 11);

        for(j = 0; j < 100; j++) {
            cout << intro[i][j];
        }

        cout << "\n";
    }

    gotoxy(50, 30);
    cout << "1. Start playing.";
    gotoxy(50, 32);
    cout << "2. Quit game.";
    gotoxy(50, 34);
    cin >> option;

    if(option == 1)
        game_start();
    else if(option == 2) {
        close();
        clear();
    }
    else
        cout << "Option not valid." << endl;
}

template<typename T>
void Game<T>::game_start() {
    state = GAMESTATE::START;

    clear();
    game_limit();
}