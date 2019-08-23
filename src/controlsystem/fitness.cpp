#include "src/controlsystem/fitness.h"

Fitness::Fitness(Interface inter){
    interface = inter;
    fit_points = 0;
}

Fitness::~Fitness(){

}

// punishes when is far from certain point
void Fitness::target_point(double x, double y){
    fit_points -= dist(interface.getPosX(0,0), interface.getPosY(0,0), x, y);
}

void Fitness::update_fitness_frame(){
    target_point(0.8,0.5);
}

// return the distance of two points
double Fitness::dist(double x1,double y1,double x2,double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
    
double Fitness::get_fit_points(){
    return fit_points;
}
