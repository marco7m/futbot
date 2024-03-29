#ifndef REFEREE_H
#define REFEREE_H

#include "../wrsim/src/WRSim/interface.h"
#include <vector>
#include <string>
#include "src/utils/csv.h"
#include "src/utils/my_ptr.h"
#include "src/utils/geom.h"

class Referee{
public:
    Referee(Interface inter, unsigned long long *t, std::string file_name = "");
    ~Referee();

    void check_game();

    // rules
    bool restart_if_in_points();

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

    int score_a;

    // find a better place for this
    // used in -> void Referee::restart_if_in_points(){
    bool pos_robot = false;
    double points[10][2] = {
        {0.8,0.8},
        {0.8,0.2},
        {0.2,0.2},
        {0.2,0.8},
        {0.5,0.8},
        {0.5,0.2},
        {0.8,0.5},
        {0.2,0.5},
        {0.8,0.8},
        {0.2,0.2}
    };
 
};

#endif
