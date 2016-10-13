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

#ifndef INTERFACE_H
#define INTERFACE_H

#include "objetos/robovss.h"
#include "objetos/bola.h"

class interface{
public:
    interface(robovss *r, bola *b);

    double getPosX(quint8 time, quint8 idRobo);

    void setPosX(quint8 time, quint8 idRobo, double vel);

    double getPosY(quint8 time, quint8 idRobo);

    double getAng(quint8 time, quint8 idRobo);
    
    double getVel(quint8 time, quint8 idRobo);
    void setVel(quint8 time, quint8 idRobo, double vel);
    
    double getVelX(quint8 time, quint8 idRobo);

    double getVelY(quint8 time, quint8 idRobo);

    double getVelAng(quint8 time, quint8 idRobo);
    void setVelAng(quint8 time, quint8 idRobo, double velAng);

    double getPosBolaX();

    double getPosBolaY();


private:
    robovss *_robo;
    bola *_bola;
    int encontraRobo(quint8 time, quint8 idRobo);
};

#endif
