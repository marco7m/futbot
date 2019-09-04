#ifndef REFEREE_H
#define REFEREE_H

#include "../wrsim/src/WRSim/interface.h"
#include <vector>
#include <string>
#include "src/utils/csv.h"
#include "src/utils/my_ptr.h"

class Referee{
public:
    Referee(Interface inter, unsigned long long *t, std::string file_name = "");
    ~Referee();

    void check_game();

    // rules
//    void go_to_points(int* points

private:
    Interface interface;
    unsigned long long *tempo;
    bool left_goal();
    bool right_goal();
    void save_game_frame();

    // saving game related
    std::vector<std::vector<double> > saved_game;
    std::vector<double> saved_frame; //posx,poxy,ang
    bool save_game;
    std::string save_file_name;

    int score_a = 0;

};

#endif
