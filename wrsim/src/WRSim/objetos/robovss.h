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

#ifndef ROBOVSS_H
#define ROBOVSS_H

#include "WRSim/cte.h"
#include <cmath>
#include <QtGlobal>

class robovss{
public:
    robovss();

    // dimensões do robo
    static constexpr double largura = 80; // [mm]
    static constexpr int nRobos = 2;

    double getVel() const;
    void setVel(double value);

    double getVelX(); //em função de getVel e getAng

    double getVelY(); //em função de getVel e getAng

    double getX() const;
    void setX(double value);

    double getY() const;
    void setY(double value);

    double getAng() const;
    void setAng(double value);

    double getVelAng() const;
    void setVelAng(double value);

    quint8 getTime() const;
    void setTime(const quint8 &value);

    quint8 getIdRobo() const;
    void setIdRobo(const quint8 &value);

private:
    double vel;
    double x;
    double y;
    double ang; // graus
    double velAng; // graus por milisegundo
    quint8 time; // 0-1 usado para diferenciar o time
    quint8 idRobo; // 0-2 usado para diferenciar o robô dentro de um time (é aceitável de 0-11)
};

#endif // ROBOVSS_H
