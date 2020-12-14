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