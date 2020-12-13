#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#define ENTER 13
#define WMINUS 119
#define WMAYUS 87
#define SMINUS 115
#define SMAYUS 83
#define OMINUS 111
#define OMAYUS 79
#define LMINUS 108
#define LMAYUS 76

#include <termios.h>
#include <stdio.h>

static struct termios old, neww;

class Keyboard {
    public:
        void initTermios(int echo) {
            tcgetattr(0, &old); 
            neww = old;
            neww.c_lflag &= ~ICANON;
            neww.c_lflag &= echo ? ECHO : ~ECHO;
            tcsetattr(0, TCSANOW, &neww); 
        }

        void resetTermios(void) {
            tcsetattr(0, TCSANOW, &old);
        }
        
        char getch_(int echo) {
            char ch;
            initTermios(echo);
            ch = getchar();
            resetTermios();
            return ch;
        }
        
        char getch(void) {
            return getch_(0);
        }
        
        char getche(void) {
            return getch_(1);
        }

        int key() {
            int t;
            
            t = getch();
            
            if(t == 0)
                t = 1000 + getch();
            
            return t;
        }
};

#endif