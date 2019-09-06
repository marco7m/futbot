#include "referee.h"
#include <iostream>

Referee::Referee(Interface inter, unsigned long long *t, std::string file_name){
    interface = inter;
    tempo = t;
    save_file_name = file_name;
    if(file_name == ""){
        save_game = false;
    }
    else{
        save_game = true;
    }
    score_a = 0;
}

// TODO
Referee::~Referee(){
    if(save_game){
        Csv::save_data(saved_game, save_file_name, ',');
    }
}

void Referee::check_game(){
//    if(right_goal()) std::cout << "GOOOL DIREITO!" << std::endl;
//    if(left_goal()) std::cout << "GOOOL ESQUERDO!" << std::endl;
    if(save_game) save_game_frame();
}

void Referee::restart_if_in_points(){
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
    
    interface.setPosBolaX(points[score_a][0]);
    interface.setPosBolaY(points[score_a][1]);
    if(Geom::dist(points[score_a][0],points[score_a][1], interface.getPosX(0,0), interface.getPosY(0,0)) < 0.05){
        if(score_a < 9) score_a++;
        else score_a = 0;
        std::cout << "foi" << std::endl;        
    }
}

bool Referee::left_goal(){
    if(interface.get_denormalized_pos_bola_x() < 100) return true;
    else return false;
}

bool Referee::right_goal(){
    if(interface.get_denormalized_pos_bola_x() > 1600) return true;
    else return false;
}

void Referee::save_game_frame(){
    for(int team = 0; team <= 1; team++){
        for(int id = 0; id <= 2; id++){
            saved_frame.push_back(interface.getPosX(team,id));
            saved_frame.push_back(interface.getPosY(team,id));
            saved_frame.push_back(interface.getAng(team,id));
        }
    }

    saved_frame.push_back(interface.getPosBolaX());
    saved_frame.push_back(interface.getPosBolaY());

    saved_game.push_back(saved_frame);
    saved_frame.clear();
}
