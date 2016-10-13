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

#include "bola.h"

bola::bola(){
    x = 180;
    y = 180;
    velX = 0;
    velY = 0;
}

double bola::getVelY() const{
    return velY;
}

void bola::setVelY(double value)
{
    velY = value;
}

double bola::getVelX() const{
    return velX;
}

void bola::setVelX(double value){
    velX = value;
}

double bola::getX() const{
    return x;
}

void bola::setX(double value){
    x = value;
}

double bola::getY() const{
    return y;
}

void bola::setY(double value){
    y = value;
}
