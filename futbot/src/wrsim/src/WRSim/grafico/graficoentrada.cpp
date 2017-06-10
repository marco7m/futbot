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

#include "graficoentrada.h"
#include <QKeyEvent>
#include <QDebug>

graficoentrada::graficoentrada(bola *b, robovss *r, QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    robo = r;
    _bola = b;
    selectRobot = new int;
    *selectRobot = 0;
}

void graficoentrada::keyPressEvent(QKeyEvent *event){
    // controla o robo
    if(event->key() == Qt::Key_Up){
        robo[*selectRobot].setVel(-0.5); // [mm/ms]
    }
    if(event->key() == Qt::Key_Down){
        robo[*selectRobot].setVel(0.5);
    }

    if(event->key() == Qt::Key_Left){
        robo[*selectRobot].setVelAng(-0.5);
    }
    if(event->key() == Qt::Key_Right){
        robo[*selectRobot].setVelAng(0.5);
    }


    if(config::in2Bola){
        // controla a bola
        if(event->key() == Qt::Key_W){
            _bola->setVelY(-0.6); // [mm/ms]
        }
        if(event->key() == Qt::Key_S){
            _bola->setVelY(0.6);
        }

        if(event->key() == Qt::Key_A){
            _bola->setVelX(-0.6);
        }
        if(event->key() == Qt::Key_D){
            _bola->setVelX(0.6);
        }
    }

    //controla robô[1] com wasd
    if(config::in2Jogador1){
        if(event->key() == Qt::Key_W){
            robo[1].setVel(0.5); // [mm/ms]
        }
        if(event->key() == Qt::Key_S){
            robo[1].setVel(-0.5);
        }

        if(event->key() == Qt::Key_A){
            robo[1].setVelAng(-0.5);
        }
        if(event->key() == Qt::Key_D){
            robo[1].setVelAng(0.5);
        }
    }

    // coloca todos os robôs em posições aleatórias no campo
    if(event->key() == Qt::Key_R){
        for(int i = 0; i < robovss::nRobos; i++){
            robo[i].setX((rand() % (int)(1500 - (2*robo[i].largura))) + 100 + robo[i].largura);
            robo[i].setY((rand() % (int)(1300 - (2*robo[i].largura))) + 25 + robo[i].largura);
        }
    }
    
    // coloca o robo[0] nessa posição
    if(event->key() == Qt::Key_P){
        robo[0].setX(1300);
        robo[0].setY(650);
        robo[0].setAng(0);
    }

    // seleção
    if(event->key() == Qt::Key_0){
        *selectRobot = 0;
    }
    if((event->key() == Qt::Key_1) && (robovss::nRobos > 1)){
        *selectRobot = 1;
    }
    if((event->key() == Qt::Key_2) && (robovss::nRobos > 2)){
        *selectRobot = 2;
    }
    if((event->key() == Qt::Key_3) && (robovss::nRobos > 3)){
        *selectRobot = 3;
    }
    if((event->key() == Qt::Key_4) && (robovss::nRobos > 4)){
        *selectRobot = 4;
    }
    if((event->key() == Qt::Key_5) && (robovss::nRobos > 5)){
        *selectRobot = 5;
    }
}

void graficoentrada::keyReleaseEvent(QKeyEvent *event){
    if((event->key() == Qt::Key_Up) || (event->key() == Qt::Key_Down)){
        robo[*selectRobot].setVel(0);
    }
    else if((event->key() == Qt::Key_Left) || (event->key() == Qt::Key_Right)){
        robo[*selectRobot].setVelAng(0);
    }

    if(config::in2Jogador1){
        if((event->key() == Qt::Key_W) || (event->key() == Qt::Key_S)){
            robo[1].setVel(0);
        }
        else if((event->key() == Qt::Key_A) || (event->key() == Qt::Key_D)){
            robo[1].setVelAng(0);
        }
    }
}
