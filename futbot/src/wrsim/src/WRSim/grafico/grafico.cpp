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

#include "grafico.h"
#include "../cte.h"
#include <iostream>

// escala: 0.5
grafico::grafico(robovss *r, bola *b, probe *p, Interface inter){
    _probe = p;
    robo = r;
    _bola = b;
    interface = inter;

    // cria janela
    tela = new QGraphicsScene();
    tela->setSceneRect(0,0,1700, 1348);
    setScene(tela);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    resize(1700, 1348);
    scale(0.5,0.5);

    // cria item que recebe entrada
//    gentrada = new graficoentrada(_bola, robo);

    gentrada = new graficoentrada(interface);
    gentrada->setFlag(QGraphicsItem::ItemIsFocusable);
    gentrada->setFocus();
    gentrada->setPos(0,0);
    tela->addItem(gentrada);

    // cria robos
    grobo = new graficorobovss[robovss::nRobos];
    for(int i = 0; i < robovss::nRobos; ++i){
        grobo[i].setTransformOriginPoint(QPoint(robovss::largura/2,robovss::largura/2));

        if((int)robo[i].getTime() == 0 && (int)robo[i].getIdRobo() == 0){
            grobo[i].setPixmap(QPixmap(":/img/robovss00.png"));
        }
        else if((int)robo[i].getTime() == 0 && (int)robo[i].getIdRobo() == 1){
            grobo[i].setPixmap(QPixmap(":/img/robovss01.png"));
        }      
        else if((int)robo[i].getTime() == 0 && (int)robo[i].getIdRobo() == 2){
            grobo[i].setPixmap(QPixmap(":/img/robovss02.png"));
        }      
        else if((int)robo[i].getTime() == 1 && (int)robo[i].getIdRobo() == 0){
            grobo[i].setPixmap(QPixmap(":/img/robovss10.png"));
        }      
        else if((int)robo[i].getTime() == 1 && (int)robo[i].getIdRobo() == 1){
            grobo[i].setPixmap(QPixmap(":/img/robovss11.png"));
        }      
        else if((int)robo[i].getTime() == 1 && (int)robo[i].getIdRobo() == 2){
            grobo[i].setPixmap(QPixmap(":/img/robovss12.png"));
        }      
        else{
            grobo[i].setPixmap(QPixmap(":/img/robovss.png"));
        }
        grobo[i].setPos(robo[i].getX(),robo[i].getY());
//        grobo[i].setScale(0.5);
    }

    // cria bola
    gbola = new graficobola();
    gbola->setTransformOriginPoint(QPoint(bola::raio, bola::raio));
    gbola->setPixmap(QPixmap(":/img/bola.png"));
    gbola->setPos(_bola->getX(), _bola->getY());
//    gbola->setScale(0.5);

    // cria campo
    gcampoVss = new graficocampovss();
    gcampoVss->setPixmap(QPixmap(":/img/campoVss.png"));
    gcampoVss->setPos(0, 0);
//    gcampoVss->setScale(0.5);
    tela->addItem(gcampoVss);

    // cria probes
    gprobe = new graficoprobe[cte::nProbes];
    if(cte::nProbes == 4){
        gprobe[0].setPixmap(QPixmap(":/img/probei.png"));
        gprobe[1].setPixmap(QPixmap(":/img/probe.png"));
        gprobe[2].setPixmap(QPixmap(":/img/probei2.png"));
        gprobe[3].setPixmap(QPixmap(":/img/probe2.png"));
        for(int i = 0; i < cte::nProbes; ++i){
            gprobe[i].setPos(_probe->getX(), _probe->getY());
        }
    }
    else{
        for(int i = 0; i < cte::nProbes; ++i){
            gprobe[i].setPixmap(QPixmap(":/img/probe.png"));
            gprobe[i].setPos(_probe->getX(), _probe->getY());
        }
    }

    // coloca todos os grobo em campo
    for(int i = 0; i < robovss::nRobos; ++i){
        tela->addItem(grobo + i);
    }

    // coloca bola em campo
    tela->addItem(gbola);


    // coloca todos os probes em campo
    for(int i = 0; i < cte::nProbes; ++i){
        tela->addItem(gprobe + i);
    }

    show();
}

void grafico::roda(){
    for(int i = 0; i < robovss::nRobos; i++){
        grobo[i].setPos(robo[i].getX() - (robo[i].largura/2), robo[i].getY() - (robo[i].largura/2));
        grobo[i].setRotation(robo[i].getAng());
    }
    for(int i = 0; i < cte::nProbes; i++){
        gprobe[i].setPos(_probe[i].getX() - _probe[i].raio, _probe[i].getY() - _probe[i].raio);
    }
    gbola->setPos(_bola->getX() - _bola->raio, _bola->getY() - _bola->raio);

    gcampoVss->setPos(0,0);
}



