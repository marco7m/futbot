#include "referee.h"
#include <iostream>

Referee::Referee(Interface inter, unsigned long long *t){
    interface = inter;
    tempo = t;
    flag_save_game = false;
}

// TODO
Referee::~Referee(){
    if(flag_save_game){
        Csv::save_data(saved_game, "data/referee/tmp.csv", ',');
    }
}

void Referee::check_game(){
    if(right_goal()) std::cout << "GOOOL DIREITO!" << std::endl;
    if(left_goal()) std::cout << "GOOOL ESQUERDO!" << std::endl;
}

void Referee::check_game_centerAndSave(){
    save_game_frame();
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
    flag_save_game = true;

    saved_frame.push_back(interface.getPosX(0,0));
    saved_frame.push_back(interface.getPosY(0,0));
    saved_frame.push_back(interface.getAng(0,0));

    saved_frame.push_back(interface.getPosX(0,1));
    saved_frame.push_back(interface.getPosY(0,1));
    saved_frame.push_back(interface.getAng(0,1));

    saved_frame.push_back(interface.getPosX(0,2));
    saved_frame.push_back(interface.getPosY(0,2));
    saved_frame.push_back(interface.getAng(0,2));
    
    saved_frame.push_back(interface.getPosX(1,0));
    saved_frame.push_back(interface.getPosY(1,0));
    saved_frame.push_back(interface.getAng(1,0));

    saved_frame.push_back(interface.getPosX(1,1));
    saved_frame.push_back(interface.getPosY(1,1));
    saved_frame.push_back(interface.getAng(1,1));

    saved_frame.push_back(interface.getPosX(1,2));
    saved_frame.push_back(interface.getPosY(1,2));
    saved_frame.push_back(interface.getAng(1,2));

    saved_frame.push_back(interface.getPosBolaX());
    saved_frame.push_back(interface.getPosBolaY());

    saved_game.push_back(saved_frame);
    saved_frame.clear();
}
