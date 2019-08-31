#ifndef REFEREE_H
#define REFEREE_H

#include "../wrsim/src/WRSim/interface.h"
#include <vector>
#include <string>
#include "src/utils/csv.h"

class Referee{
public:
    Referee(Interface inter, unsigned long long *t, bool f_save_game = false, std::string file_name = "default.csv");
    ~Referee();

    // arbitros
    void check_game();
    void check_game_centerAndSave();

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

};

#endif
