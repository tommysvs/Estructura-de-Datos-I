#ifndef _SCORE_H
#define _SCORE_H

class Score {
    private:
        int s_p1 = 0;
        int s_p2 = 0; 
        int s_cpu = 0;

    public:
        void set_sp1() {
            s_p1++;
        }

        void set_sp2() {
            s_p2++;
        }

        void set_scpu() {
            s_cpu++;
        }

        int get_sp1() {
            return s_p1;
        }

        int get_sp2() {
            return s_p2;
        }

        int get_scpu() {
            return s_cpu;
        }
};

#endif
