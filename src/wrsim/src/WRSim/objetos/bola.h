/***
 * Warthog Robotics
 * University of Sao Paulo (USP) at Sao Carlos
 * http://www.warthog.sc.usp.br/
 *
 * This file is part of xxxxxx project.
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

#ifndef BOLA_H
#define BOLA_H


class bola{
public:
    bola();
    static constexpr double raio = 15; //[mm]
    static constexpr double perda = 0.0063; // 0.0063 pareceu good para passo de tempo = 10ms
    double velX; // mm / ms
    double velY; // mm / ms
    double x;
    double y;

    double getY() const;
    void setY(double value);
    double getX() const;
    void setX(double value);
    double getVelX() const;
    void setVelX(double value);
    double getVelY() const;
    void setVelY(double value);
};

#endif // BOLA_H
