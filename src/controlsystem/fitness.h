#ifndef FITNESS_H
#define FITNESS_H

#include <iostream>
#include "../wrsim/src/WRSim/interface.h"
#include <cmath>

class Fitness{
public:
    Fitness(Interface inter);
    ~Fitness();
    void update_fitness_frame();

    // fit functions
    void target_point(double x, double y);
    void avoid_point(double x, double y);
    void target_ball();
    void vel_ang_is_bad(double sensitivity);
    
    double get_fit_points();
private:
    void count_time();

    // variables
    Interface interface;
    double fit_points;

    // auxiliar functions
    double dist(double x1,double y1,double x2,double y2);
};
#endif
