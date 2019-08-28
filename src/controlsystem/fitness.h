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
    double get_fit_points();
private:
    // fit functions
    void target_point(double x, double y);
    void count_time();

    // variables
    Interface interface;
    double fit_points;

    // auxiliar functions
    double dist(double x1,double y1,double x2,double y2);
};
#endif
