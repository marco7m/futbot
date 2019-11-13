#include "src/controlsystem/fitness.h"

Fitness::Fitness(Interface inter){
    interface = inter;
    fit_points = 0;
}

Fitness::~Fitness(){

}

// punishes when is far from certain point
void Fitness::target_point(double x, double y){
    fit_points -= Geom::dist(interface.getPosX(0,0), interface.getPosY(0,0), x, y);
}

// punishes when is far from the ball
void Fitness::target_ball(){
    fit_points -= Geom::dist(interface.getPosX(0,0), interface.getPosY(0,0), interface.getPosBolaX(), interface.getPosBolaY());
}

void Fitness::move_or_rotate(){
    fit_points -= abs(interface.getVel(0,0)) * abs(interface.getVelAng(0,0));
}
void Fitness::avoid_point(double x, double y){
    fit_points += 0.3*Geom::dist(interface.getPosX(0,0), interface.getPosY(0,0), x, y);
}

void Fitness::vel_ang_is_bad(double sensitivity){
    fit_points -= sensitivity * abs(interface.getVelAng(0,0));
}

void Fitness::manual_fit(double points){
    fit_points += points;
}

void Fitness::count_time(){
    fit_points -= 1;
}

// nao utilizada, apagar?
void Fitness::update_fitness_frame(){
    target_point(0.8,0.5);
}
    
double Fitness::get_fit_points(){
    return fit_points;
}
