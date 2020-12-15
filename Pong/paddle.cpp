void Paddle::draw() {
    int pad = 35;

    gp.gotoxy(x, y - 1);
    std::cout << (char)pad;

    gp.gotoxy(x, y);
    std::cout << (char)pad;

    gp.gotoxy(x, y + 1);
    std::cout << (char)pad;
}

void Paddle::del() {
    gp.gotoxy(x, y - 1);
    std::cout << " ";

    gp.gotoxy(x, y);
    std::cout << " ";

    gp.gotoxy(x, y + 1);
    std::cout << " ";
}

void Paddle::cpu(int _x, int _y, int _dx) {
    if(_x > 70 && _dx > 0) {
        del();

        if(_y > y && y + 1 < 23) 
            y++;
        
        if(_y < y && y - 1 < 5)
            y--;

        draw();
    }
}