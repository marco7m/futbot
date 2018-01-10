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
#include <iostream>

graficoentrada::graficoentrada(Interface inter){
    interface = inter;
    team_control = 0;
    id_control = 0;
    mirror = false;
}

void graficoentrada::keyPressEvent(QKeyEvent *event){
    // controla o robo
    if(event->key() == Qt::Key_Up){
        interface.setVel(team_control,id_control,0.75); // vel abaixo de 0.5 na interface é vel negativa
        if(mirror) interface.setVel(team_control? 0:1,id_control,0.75, true); // vel abaixo de 0.5 na interface é vel negativa
    }
    if(event->key() == Qt::Key_Down){
        interface.setVel(team_control,id_control,0.25);
        if(mirror) interface.setVel(team_control? 0:1,id_control,0.25, true);
    }

    if(event->key() == Qt::Key_Left){
        interface.setVelAng(team_control,id_control,0.25);
        if(mirror) interface.setVelAng(team_control? 0:1,id_control,0.25, true);
    }
    if(event->key() == Qt::Key_Right){
        interface.setVelAng(team_control,id_control,0.75);
        if(mirror) interface.setVelAng(team_control? 0:1,id_control,0.75, true);
    }
    
    // mostra dados para debug
    if(event->key() == Qt::Key_D){
        std::cout << std::endl;
        std::cout << "time 0" << std::endl;
        std::cout << "getPosX " << interface.getPosX(0,0) << std::endl;
        std::cout << "getPosXQuina " << interface.getPosXQuina(0,0,0) << std::endl;
        std::cout << "getPosXQuina " << interface.getPosXQuina(0,0,1) << std::endl;
        std::cout << "getPosXQuina " << interface.getPosXQuina(0,0,2) << std::endl;
        std::cout << "getPosXQuina " << interface.getPosXQuina(0,0,3) << std::endl;
        std::cout << "getPosY " << interface.getPosY(0,0) << std::endl;
        std::cout << "getPosYQuina " << interface.getPosYQuina(0,0,0) << std::endl;
        std::cout << "getPosYQuina " << interface.getPosYQuina(0,0,1) << std::endl;
        std::cout << "getPosYQuina " << interface.getPosYQuina(0,0,2) << std::endl;
        std::cout << "getPosYQuina " << interface.getPosYQuina(0,0,3) << std::endl;
        std::cout << "getVelX " << interface.getVelX(0,0) << std::endl;
        std::cout << "getVelY " << interface.getVelY(0,0) << std::endl;
        std::cout << "getVelAng " << interface.getVelAng(0,0) << std::endl;
        std::cout << "getVel " << interface.getVel(0,0) << std::endl;

        std::cout << std::endl;
        std::cout << "time 1" << std::endl;
        std::cout << "getPosX " << interface.getPosX(1,0,true) << std::endl;
        std::cout << "getPosXQuina " << interface.getPosXQuina(1,0,0,true) << std::endl;
        std::cout << "getPosXQuina " << interface.getPosXQuina(1,0,1,true) << std::endl;
        std::cout << "getPosXQuina " << interface.getPosXQuina(1,0,2,true) << std::endl;
        std::cout << "getPosXQuina " << interface.getPosXQuina(1,0,3,true) << std::endl;
        std::cout << "getPosY " << interface.getPosY(1,0,true) << std::endl;
        std::cout << "getPosYQuina " << interface.getPosYQuina(1,0,0,true) << std::endl;
        std::cout << "getPosYQuina " << interface.getPosYQuina(1,0,1,true) << std::endl;
        std::cout << "getPosYQuina " << interface.getPosYQuina(1,0,2,true) << std::endl;
        std::cout << "getPosYQuina " << interface.getPosYQuina(1,0,3,true) << std::endl;
        std::cout << "getVelX " << interface.getVelX(1,0,true) << std::endl;
        std::cout << "getVelY " << interface.getVelY(1,0,true) << std::endl;
        std::cout << "getVelAng " << interface.getVelAng(1,0,true) << std::endl;
        std::cout << "getVel " << interface.getVel(1,0,true) << std::endl;


        std::cout << std::endl;
        std::cout << "bola" << std::endl;
        std::cout << "getPosBolaX " << interface.getPosBolaX(true) << std::endl;
        std::cout << "getPosBolaY " << interface.getPosBolaY(true) << std::endl;
        std::cout << "getVelBolaX " << interface.getVelBolaX(true) << std::endl;
        std::cout << "getVelBolaY " << interface.getVelBolaY(true) << std::endl;
    }
    
    if(event->key() == Qt::Key_M){
        mirror = !mirror;
    }

    // move para posição tal (debug)
    if(event->key() == Qt::Key_C){
        MoveRobots::default_position(interface);
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
        if(mirror) interface.setVel(team_control? 0:1,id_control,0.5);
    }
    else if((event->key() == Qt::Key_Left) || (event->key() == Qt::Key_Right)){
        interface.setVelAng(team_control,id_control,0.5);
        if(mirror) interface.setVelAng(team_control? 0:1,id_control,0.5);
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
