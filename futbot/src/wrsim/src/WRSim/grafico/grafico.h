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

#ifndef GRAFICO_H
#define GRAFICO_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "graficoentrada.h"
#include "graficorobovss.h"
#include "../objetos/robovss.h"
#include "graficobola.h"
#include "../objetos/bola.h"
#include "graficoprobe.h"
#include "../objetos/probe.h"
#include "graficocampovss.h"
#include "../interface.h"

class grafico: public QGraphicsView{
public:
    grafico(robovss *r, bola *b, probe *p, Interface interface);
    QGraphicsScene *tela;
    graficorobovss *grobo;
    graficobola *gbola;
    graficoprobe *gprobe;
    graficoentrada *gentrada;
    graficocampovss *gcampoVss;
    
    void roda();
private:
    robovss *robo;
    bola *_bola;
    probe *_probe;
    Interface interface;
};

#endif // GRAFICO_H
