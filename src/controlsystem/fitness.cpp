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

// punishes when is far from the ball
void Fitness::target_ball(){
    fit_points -= dist(interface.getPosX(0,0), interface.getPosY(0,0), interface.getPosBolaX(), interface.getPosBolaY());
}

void Fitness::avoid_point(double x, double y){
    fit_points += 0.3*dist(interface.getPosX(0,0), interface.getPosY(0,0), x, y);
}

void Fitness::vel_ang_is_bad(double sensitivity){
    fit_points -= sensitivity * abs(interface.getVelAng(0,0));
}

void Fitness::count_time(){
    fit_points -= 1;
}

// nao utilizada, apagar?
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
