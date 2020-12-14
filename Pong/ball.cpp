void Ball::draw() {
    int ball = 64;

    gb.gotoxy(x, y);
    std::cout << (char)ball;
}

void Ball::del() {
    gb.gotoxy(x, y);
    std::cout << " ";
}

void Ball::move(Paddle p1, Paddle p2) {
    del();
    x += dx;
    y += dy;
    draw();

    if(x + dx == 1 || x + dx == 99) {
        del();
        assign_coord(50, 12);
        dx = -dx;
    }

    if(y + dy == 4 || y + dy == 23)
        dy = -dy;        

    if(x + dx == p1.get_x() && y >= p1.get_y() -2 && y <= p1.get_y() + 2) 
        dx = -dx;

    if(x + dx == p2.get_x() && y >= p2.get_y() -2 && y <= p2.get_y() + 2) 
        dx = -dx;
}