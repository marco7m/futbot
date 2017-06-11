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

#include "robovss.h"

robovss::robovss(){
    time = 0;
    idRobo = 0;
    vel = 0;
    x = 0;
    y = 0;
    ang = 0;
    velAng = 0;
}

double robovss::getVel() const{
    return vel;
}

void robovss::setVel(double value){
    vel = value;
}

double robovss::getVelX(){
    return (-sin(this->getAng()*cte::PI/180)*this->getVel());
}

double robovss::getVelY(){
    return (cos(this->getAng()*cte::PI/180)*this->getVel());
}

double robovss::getX() const{
    return x;
}

void robovss::setX(double value){
    x = value;
}

double robovss::getY() const{
    return y;
}

void robovss::setY(double value){
    y = value;
}

double robovss::getAng() const{
    return ang;
}

void robovss::setAng(double value){
    ang = value;
}

double robovss::getVelAng() const{
    return velAng;
}

void robovss::setVelAng(double value){
    velAng = value;
}

quint8 robovss::getTime() const{
    return time;
}

void robovss::setTime(const quint8 &value){
    if(value == 0 || value == 1){
        time = value;
    }
    //substituir esse if por uma exceção futuramente
}

quint8 robovss::getIdRobo() const{
    return idRobo;
}

void robovss::setIdRobo(const quint8 &value){
    if(value >= 0 && value <= 2){
        idRobo = value;
    }
    //substituir esse if por uma exceção futuramente
}


