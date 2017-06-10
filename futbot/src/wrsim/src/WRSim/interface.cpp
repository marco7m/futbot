/***
 * Warthog Robotics
 * University of Sao Paulo (USP) at Sao Carlos
 * http://www.warthog.sc.usp.br/
 *
 * This file is part of WRSim project.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***/

#include "interface.h"
#include <iostream>

interface::interface(robovss *r, bola *b){
_robo = r;
_bola = b;
} 

int interface::encontraRobo(quint8 time, quint8 idRobo){
    for(int i = 0; robovss::nRobos; i++){
        if((_robo[i].getIdRobo() == idRobo) && (_robo[i].getTime() == time)){
        return i;
        }
    }
    //caso o robô expecificado não existe, envia -1 para o método saber o que fazer
    std::cout << "Wrong team or idRobo in encontraRobo" << std::endl;
    return -1; 
}

double interface::getPosX(quint8 time, quint8 idRobo){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return _robo[encontraRobo(time, idRobo)].getX();
    }
}

void interface::setPosX(quint8 time, quint8 idRobo, double posx){
    int robo_encontrado = encontraRobo(time, idRobo);
    if(robo_encontrado == -1){
        return;
    }
    else{
        _robo[robo_encontrado].setX(posx);
    }
}

double interface::getPosY(quint8 time, quint8 idRobo){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return _robo[encontraRobo(time, idRobo)].getY();
    }
}

void interface::setPosY(quint8 time, quint8 idRobo, double posy){
    int robo_encontrado = encontraRobo(time, idRobo);
    if(robo_encontrado == -1){
        return;
    }
    else{
        _robo[robo_encontrado].setY(posy);
    }
}

double interface::getAng(quint8 time, quint8 idRobo){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return _robo[encontraRobo(time, idRobo)].getAng();
    }
}

void interface::setAng(quint8 time, quint8 idRobo, double ang){
    int robo_encontrado = encontraRobo(time, idRobo);
    if(robo_encontrado == -1){
        return;
    }
    else{
        _robo[robo_encontrado].setAng(ang);
    }
}

double interface::getVel(quint8 time, quint8 idRobo){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return _robo[encontraRobo(time, idRobo)].getVel();
    }
} 

void interface::setVel(quint8 time, quint8 idRobo, double vel){
    if(encontraRobo(time, idRobo) == -1){
        return;
    }
    else{
        _robo[encontraRobo(time, idRobo)].setVel(vel);
    }
}
    
double interface::getVelX(quint8 time, quint8 idRobo){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return _robo[encontraRobo(time, idRobo)].getVelX();
    }
}

double interface::getVelY(quint8 time, quint8 idRobo){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return _robo[encontraRobo(time, idRobo)].getVelY();
    }
}

double interface::getVelAng(quint8 time, quint8 idRobo){
    if(encontraRobo(time, idRobo) == -1){
        return 0;
    }   
    else{
        return _robo[encontraRobo(time, idRobo)].getVelAng();
    }
}

void interface::setVelAng(quint8 time, quint8 idRobo, double velAng){
    if(encontraRobo(time, idRobo) == -1){
        return;
    }   
    else{
        _robo[encontraRobo(time, idRobo)].setVelAng(velAng);
    }
}

double interface::getPosBolaX(){
    return _bola->getX();
}

void interface::setPosBolaX(double posbx){
    _bola->setX(posbx);
}

double interface::getPosBolaY(){
    return _bola->getY();
}

void interface::setPosBolaY(double posby){
    _bola->setY(posby);
}

double interface::getVelBolaX(){
    return _bola->getVelX();
}

void interface::setVelBolaX(double velbx){
    _bola->setVelX(velbx);
}

double interface::getVelBolaY(){
    return _bola->getVelY();
}

void interface::setVelBolaY(double velby){
    _bola->setVelY(velby);
}




