#ifndef FITNESS_H
#define FITNESS_H

#include <iostream>
#include <cmath>
#include "../wrsim/src/WRSim/interface.h"
#include "src/utils/geom.h"

class Fitness{
public:
    Fitness(Interface inter);
    ~Fitness();
    void update_fitness_frame();

    // fit functions
    void target_point(double x, double y);
    void avoid_point(double x, double y);
    void target_ball();
    void move_or_rotate();
    void vel_ang_is_bad(double sensitivity);
    
    double get_fit_points();
private:
    void count_time();

    // variables
    Interface interface;
    double fit_points;
};
#endif
