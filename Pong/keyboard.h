#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#define Q 113
#define A 97
#define O 111
#define L 108
#define R 114
#define ENTER 13

#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

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

        int kbhit(void) {
            struct termios oldt, newt;
            int ch;
            int oldf;
            
            tcgetattr(STDIN_FILENO, &oldt);
            newt = oldt;
            newt.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
            oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
            fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
            
            ch = getchar();
            
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            fcntl(STDIN_FILENO, F_SETFL, oldf);
            
            if(ch != EOF) {
                ungetc(ch, stdin);
                return 1;
            }
            
            return 0;
        }
};

#endif