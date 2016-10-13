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
#ifndef CONTROLE_H
#define CONTROLE_H

#include <QObject>
#include "grafico/grafico.h"
#include "fisica.h"
#include "objetos/bola.h"
#include "objetos/robovss.h"
#include "interface.h"


class Controle: public QObject{
Q_OBJECT
public:
    Controle();

public slots:
    void mostra();

private:
    grafico *_grafico;
    fisica *_fisica;
    interface *_interface;

    // VIAS
    robovss *robo;
    bola *_bola;
    probe *_probe;
    unsigned long long *tempo; // dois tempos de 10 minutos ou dois tempo de 600000000 microsegundos
};

#endif // CONTROLE_H
