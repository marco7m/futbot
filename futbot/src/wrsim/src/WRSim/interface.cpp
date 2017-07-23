
#include "interface.h"
#include <iostream>

Interface::Interface(robovss *r, bola *b){
_robo = r;
_bola = b;
} 

Interface::Interface(){

}

int Interface::encontraRobo(quint8 time, quint8 idRobo){
    for(int i = 0; robovss::nRobos; i++){
        if((_robo[i].getIdRobo() == idRobo) && (_robo[i].getTime() == time)){
        return i;
        }
    }
    //caso o robô expecificado não existe, envia -1 para o método saber o que fazer
    std::cout << "Wrong team or idRobo in encontraRobo" << std::endl;
    return -1; 
}

double Interface::normaliza(double max, double min, double atual){
    return (atual-min)/(max-min);
}

double Interface::desnormaliza(double max, double min, double val_normalizado){
    return val_normalizado*(max-min) + min;
}


double Interface::getPosX(quint8 time, quint8 idRobo){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return normaliza(MAX_POS_X, MIN_POS_X, _robo[encontraRobo(time, idRobo)].getX());
    }
}

void Interface::setPosX(quint8 time, quint8 idRobo, double posx){
    int robo_encontrado = encontraRobo(time, idRobo);
    if(robo_encontrado == -1){
        return;
    }
    else{
        _robo[robo_encontrado].setX(desnormaliza(MAX_POS_X, MIN_POS_X, posx));
    }
}

double Interface::getPosY(quint8 time, quint8 idRobo){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return normaliza(MAX_POS_Y, MIN_POS_Y, _robo[encontraRobo(time, idRobo)].getY());
    }
}

void Interface::setPosY(quint8 time, quint8 idRobo, double posy){
    int robo_encontrado = encontraRobo(time, idRobo);
    if(robo_encontrado == -1){
        return;
    }
    else{
        _robo[robo_encontrado].setY(desnormaliza(MAX_POS_Y, MIN_POS_Y, posy));
    }
}

double Interface::getAng(quint8 time, quint8 idRobo){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        double ang = _robo[encontraRobo(time, idRobo)].getAng();
         if(ang > 360){
            ang = ang - 360 * ((int)ang/360);
        }
        else if(ang < 0){
            ang = ang + 360 * (1 + ((int)ang/-360));
        }
       
        return normaliza(MAX_ANG, MIN_ANG, ang);
    }
}

void Interface::setAng(quint8 time, quint8 idRobo, double ang){
    int robo_encontrado = encontraRobo(time, idRobo);
    if(robo_encontrado == -1){
        return;
    }
    else{
        ang = desnormaliza(MAX_ANG, MIN_ANG, ang);
        if(ang > 360){
            ang = ang - 360 * ((int)ang/360);
        }
        else if(ang < 0){
            ang = ang + 360 * (1 + ((int)ang/-360));
        }
        _robo[robo_encontrado].setAng(ang);
    }
}

double Interface::getVel(quint8 time, quint8 idRobo){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return normaliza(MAX_VEL_ROBO, MIN_VEL_ROBO, -_robo[encontraRobo(time, idRobo)].getVel());
    }
} 

// vel abaixo de 0.5 é negativa, e 0.5 = zero
void Interface::setVel(quint8 time, quint8 idRobo, double vel){
    if(encontraRobo(time, idRobo) == -1){
        return;
    }
    else{
        _robo[encontraRobo(time, idRobo)].setVel(-desnormaliza(MAX_VEL_ROBO, MIN_VEL_ROBO, vel));
    }
}
    
double Interface::getVelX(quint8 time, quint8 idRobo){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return normaliza(MAX_VEL_ROBO, MIN_VEL_ROBO, _robo[encontraRobo(time, idRobo)].getVelX());
    }
}

double Interface::getVelY(quint8 time, quint8 idRobo){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return normaliza(MAX_VEL_ROBO, MIN_VEL_ROBO, _robo[encontraRobo(time, idRobo)].getVelY());
    }
}

double Interface::getVelAng(quint8 time, quint8 idRobo){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return normaliza(MAX_VEL_ANG_ROBO, MIN_VEL_ANG_ROBO, _robo[encontraRobo(time, idRobo)].getVelAng());
    }
}

void Interface::setVelAng(quint8 time, quint8 idRobo, double velAng){
    if(encontraRobo(time, idRobo) == -1){
        return;
    }   
    else{
        _robo[encontraRobo(time, idRobo)].setVelAng(desnormaliza(MAX_VEL_ANG_ROBO, MIN_VEL_ANG_ROBO, velAng));
    }
}

double Interface::getPosBolaX(){
    return normaliza(MAX_POS_X, MIN_POS_X, _bola->getX());
}

void Interface::setPosBolaX(double posbx){
    _bola->setX(desnormaliza(MAX_POS_X, MIN_POS_X, posbx));
}

double Interface::getPosBolaY(){
    return normaliza(MAX_POS_Y, MIN_POS_Y, _bola->getY());
}

void Interface::setPosBolaY(double posby){
    _bola->setY(desnormaliza(MAX_POS_Y, MIN_POS_Y, posby));
}

double Interface::getVelBolaX(){
    return normaliza(MAX_VEL_BOLA, MIN_VEL_BOLA, _bola->getVelX());
}

void Interface::setVelBolaX(double velbx){
    _bola->setVelX(desnormaliza(MAX_VEL_BOLA, MIN_VEL_BOLA, velbx));
}

double Interface::getVelBolaY(){
    return normaliza(MAX_VEL_BOLA, MIN_VEL_BOLA, _bola->getVelY());
}

void Interface::setVelBolaY(double velby){
    _bola->setVelY(desnormaliza(MAX_VEL_BOLA, MIN_VEL_BOLA, velby));
}

double Interface::getPosXQuina(quint8 time, quint8 idRobo, int quina){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return normaliza(MAX_POS_X, MIN_POS_X, getQuinaX(_robo[encontraRobo(time, idRobo)], quina));
    }

}

double Interface::getPosYQuina(quint8 time, quint8 idRobo, int quina){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return normaliza(MAX_POS_Y, MIN_POS_Y, getQuinaY(_robo[encontraRobo(time, idRobo)], quina));
    }

}

double Interface::getQuinaX(robovss rob, int l){ // 0 - top dir; 1 - bai dir; 2 - bai esq; 3 - top esq
    if(l == 0){
        return rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() + 45)));
    }
    else if(l == 1){
        return rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() + 135)));
    }
    else if(l == 2){
        return rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() + 225)));
    }
    else if(l == 3){
        return rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() - 45)));
    }
    else{
        return 0;
    }
}

double Interface::getQuinaY(robovss rob, int l){ // 0 - top dir; 1 - bai dir; 2 - bai esq; 3 - top esq
    if(l == 0){
        return rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() + 45)));
    }
    if(l == 1){
        return rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() + 135)));
    }
    if(l == 2){
        return rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() + 225)));
    }
    if(l == 3){
        return rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() - 45)));
    }
}


double Interface::get_denormalized_pos_bola_x(){
    return _bola->getX();
}
