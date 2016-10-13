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

#include "controle.h"
#include <QTimer>
#include "cte.h"
#include <QDebug>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

Controle::Controle(){

    // inicialização dos ponteiros das vias
    robo = new robovss[robovss::nRobos];
    _bola = new bola();
    _probe = new probe[cte::nProbes];
    
    // atualmente esta instancia está sendo criada sem necessidade
    _interface = new interface(robo, _bola);

    tempo = new unsigned long long;

    // cria fisica
    _fisica = new fisica(robo, tempo, _bola, _probe);

    // inicia módulo gráfico
    _grafico = new grafico(robo, _bola, _probe);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(mostra()));
    timer->start(10);

    // configurações pré inicio de partida

    // posiciona os robôs em um local aleatório do campo
    srand((int)std::time(0));
    for(int i = 0; i < robovss::nRobos; i++){
        robo[i].setX((rand() % (int)(1500 - (2*robo[i].largura))) + 100 + robo[i].largura);
        robo[i].setY((rand() % (int)(1300 - (2*robo[i].largura))) + 25 + robo[i].largura);
    }

    // posiciona a bola em um local aleatório do campo
    _bola->setX((rand() % (int)(1500 - (4*_bola->raio))) + 100 + _bola->raio*2);
    _bola->setY((rand() % (int)(1300 - (4*_bola->raio))) + 25 + _bola->raio*2);

    *tempo = 0;
}

void Controle::mostra(){
    _fisica->roda();
    *tempo = *tempo+10;
    _grafico->roda();
}

