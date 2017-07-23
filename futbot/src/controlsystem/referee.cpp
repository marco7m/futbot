#include "referee.h"
#include <iostream>

Referee::Referee(Interface inter, unsigned long long *t){
    interface = inter;
    tempo = t;
}

bool Referee::left_goal(){
    if(interface.get_denormalized_pos_bola_x() < 100) return true;
    else return false;
}

bool Referee::right_goal(){
    if(interface.get_denormalized_pos_bola_x() > 1600) return true;
    else return false;
}

void Referee::check_game(){
    if(right_goal()) std::cout << "GOOOL DIREITO!" << std::endl;
    if(left_goal()) std::cout << "GOOOL ESQUERDO!" << std::endl;
}
