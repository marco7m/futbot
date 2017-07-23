#ifndef REFEREE_H
#define REFEREE_H

#include "../wrsim/src/WRSim/interface.h"

class Referee{
public:
    Referee(Interface inter, unsigned long long *t);
    void check_game();

private:
    Interface interface;
    unsigned long long *tempo;
    bool left_goal();
    bool right_goal();


};

#endif
