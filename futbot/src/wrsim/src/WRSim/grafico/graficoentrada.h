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

#ifndef GRAFICOENTRADA_H
#define GRAFICOENTRADA_H

#include <QGraphicsPixmapItem>
#include "../objetos/robovss.h"
#include "../objetos/bola.h"
#include "../config.h"
#include "../interface.h"

class graficoentrada: public QGraphicsPixmapItem{
public:
    graficoentrada(Interface interface);
//    graficoentrada(bola *b, robovss *r, QGraphicsItem *parent = 0); 
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

private:
    robovss *robo;
    bola *_bola;
    Interface interface;
    int *selectRobot;
};
#endif // GRAFICOENTRADA_H
