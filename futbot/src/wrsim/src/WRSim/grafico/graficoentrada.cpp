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

#include "graficoentrada.h"
#include <QKeyEvent>
#include <QDebug>

graficoentrada::graficoentrada(Interface inter){
    interface = inter;
    team_control = 0;
    id_control = 0;
}

void graficoentrada::keyPressEvent(QKeyEvent *event){
    // controla o robo
    if(event->key() == Qt::Key_Up){
        interface.setVel(team_control,id_control,0.75); // vel abaixo de 0.5 na interface é vel negativa
    }
    if(event->key() == Qt::Key_Down){
        interface.setVel(team_control,id_control,0.25);
    }

    if(event->key() == Qt::Key_Left){
        interface.setVelAng(team_control,id_control,0.25);
    }
    if(event->key() == Qt::Key_Right){
        interface.setVelAng(team_control,id_control,0.75);
    }
    
    // mostra dados para debug
    if(event->key() == Qt::Key_D){
        qDebug() << "\n";
        qDebug() << "PosX(0,0) = " << interface.getPosX(0,0);
        qDebug() << "PosY(0,0) = " << interface.getPosY(0,0);
        qDebug() << "Vel(0,0) = " << interface.getVel(0,0);
        qDebug() << "VelX(0,0) = " << interface.getVelX(0,0);
        qDebug() << "VelY(0,0) = " << interface.getVelY(0,0);
        qDebug() << "Ang(0,0) = " << interface.getAng(0,0);
        qDebug() << "VelAng(0,0) = " << interface.getVelAng(0,0);
        qDebug() << "PosBolaX() = " << interface.getPosBolaX();
        qDebug() << "PosBolaY() = " << interface.getPosBolaY();
        qDebug() << "VelBolaX() = " << interface.getVelBolaX();
        qDebug() << "VelBolaY() = " << interface.getVelBolaY();
    }
    
    // move para posição tal (debug)
    if(event->key() == Qt::Key_C){
        interface.setPosX(0,0,0.25);
        interface.setPosY(0,0,0.5);
        interface.setAng(0,0,0.25);
        interface.setVel(0,0,0.5);
        interface.setVelAng(0,0,0.5);

        interface.setPosX(0,1,0.25);
        interface.setPosY(0,1,0.25);
        interface.setAng(0,1,0.25);
        interface.setVel(0,1,0.5);
        interface.setVelAng(0,1,0.5);

        interface.setPosX(0,2,0.25);
        interface.setPosY(0,2,0.75);
        interface.setAng(0,2,0.25);
        interface.setVel(0,2,0.5);
        interface.setVelAng(0,2,0.5);

        interface.setPosX(1,0,0.75);
        interface.setPosY(1,0,0.5);
        interface.setAng(1,0,0.75);
        interface.setVel(1,0,0.5);
        interface.setVelAng(1,0,0.5);

        interface.setPosX(1,1,0.75);
        interface.setPosY(1,1,0.25);
        interface.setAng(1,1,0.75);
        interface.setVel(1,1,0.5);
        interface.setVelAng(1,1,0.5);

        interface.setPosX(1,2,0.75);
        interface.setPosY(1,2,0.75);
        interface.setAng(1,2,0.75);
        interface.setVel(1,2,0.5);
        interface.setVelAng(1,2,0.5);

        interface.setPosBolaX(0.5);
        interface.setPosBolaY(0.5);
        interface.setVelBolaX(0.5);
        interface.setVelBolaY(0.5);
    }

    // escolhe qual robo controlar
    if(event->key() == Qt::Key_1){
        team_control = 0;        
        id_control = 0;
    }
    if(event->key() == Qt::Key_2){
        team_control = 0;        
        id_control = 1;
    }
    if(event->key() == Qt::Key_3){
        team_control = 0;        
        id_control = 2;
    }
    if(event->key() == Qt::Key_4){
        team_control = 1;        
        id_control = 0;
    }
    if(event->key() == Qt::Key_5){
        team_control = 1;        
        id_control = 1;
    }
    if(event->key() == Qt::Key_6){
        team_control = 1;        
        id_control = 2;
    }







//    if(config::in2Bola){
//        // controla a bola
//        if(event->key() == Qt::Key_W){
//            _bola->setVelY(-0.6); // [mm/ms]
//        }
//        if(event->key() == Qt::Key_S){
//            _bola->setVelY(0.6);
//        }
//
//        if(event->key() == Qt::Key_A){
//            _bola->setVelX(-0.6);
//        }
//        if(event->key() == Qt::Key_D){
//            _bola->setVelX(0.6);
//        }
//    }

//    //controla robô[1] com wasd
//    if(config::in2Jogador1){
//        if(event->key() == Qt::Key_W){
//            robo[1].setVel(0.5); // [mm/ms]
//        }
//        if(event->key() == Qt::Key_S){
//            robo[1].setVel(-0.5);
//        }
//
//        if(event->key() == Qt::Key_A){
//            robo[1].setVelAng(-0.5);
//        }
//        if(event->key() == Qt::Key_D){
//            robo[1].setVelAng(0.5);
//        }
//    }

//    // coloca todos os robôs em posições aleatórias no campo
//    if(event->key() == Qt::Key_R){
//        for(int i = 0; i < robovss::nRobos; i++){
//            robo[i].setX((rand() % (int)(1500 - (2*robo[i].largura))) + 100 + robo[i].largura);
//            robo[i].setY((rand() % (int)(1300 - (2*robo[i].largura))) + 25 + robo[i].largura);
//        }
//    }
    
}

void graficoentrada::keyReleaseEvent(QKeyEvent *event){
    if((event->key() == Qt::Key_Up) || (event->key() == Qt::Key_Down)){
        interface.setVel(team_control,id_control,0.5);
    }
    else if((event->key() == Qt::Key_Left) || (event->key() == Qt::Key_Right)){
        interface.setVelAng(team_control,id_control,0.5);
    }

//    if(config::in2Jogador1){
//        if((event->key() == Qt::Key_W) || (event->key() == Qt::Key_S)){
//            robo[1].setVel(0);
//        }
//        else if((event->key() == Qt::Key_A) || (event->key() == Qt::Key_D)){
//            robo[1].setVelAng(0);
//        }
//    }

}
