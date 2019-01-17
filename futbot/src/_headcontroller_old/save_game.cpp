// Esse headcontroller faz o jogador jogar com outros robos parados e salvar os dados do jogador da direita em .csv

#include "save_game.h"
#include <QTimer>
#include <QDebug>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include "../utils/csv.h"

SaveGame::SaveGame(){

    // inicialização dos robôs
    _robo = new robovss[robovss::nRobos];
    _robo[0].setTime(0);
    _robo[0].setIdRobo(0);
    
    _robo[1].setTime(1);
    _robo[1].setIdRobo(0);

    _bola = new bola();
    _probe = new probe[cte::nProbes];

    interface = new Interface(_robo, _bola);
    
    _tempo = new unsigned long long;

    // cria fisica
    _fisica = new fisica(_robo, _tempo, _bola, _probe);

    // inicia módulo gráfico
    _grafico = new grafico(_robo, _bola, _probe, *interface);

    // configurações pré inicio de partida

    // posiciona os robôs
    interface->setPosX(0,0,0.75);
    interface->setPosY(0,0,0.5);
    interface->setAng(0,0,0.75);
    
    interface->setPosX(1,0,0.25);
    interface->setPosY(1,0,0.5);
    interface->setAng(1,0,0.25);

    // posiciona a bola
    interface->setPosBolaX(0.5);
    interface->setPosBolaY(0.5);

    continua = true;

    *_tempo = 0;
    
    _timer = new QTimer();
    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(mostra()));
    _timer->start(10);

    
}

SaveGame::~SaveGame(){
    delete[] _robo;
    delete[] _probe;
    delete _bola;
    delete _tempo;
    delete _fisica;
    delete _grafico;
    delete _timer;
    delete interface;
}

void SaveGame::mostra(){
   
    if(continua){
         _fisica->roda();
        *_tempo = *_tempo+10;
        _grafico->roda();
        
        qDebug() << *_tempo; 
        if(*_tempo > 200000){
            qDebug() << "Acabou o tempo";
            
            input_data.push_back(posx_centro);
            input_data.push_back(posx_0);
            input_data.push_back(posx_1);
            input_data.push_back(posx_2);
            input_data.push_back(posx_3);
            input_data.push_back(posy_centro);
            input_data.push_back(posy_0);
            input_data.push_back(posy_1);
            input_data.push_back(posy_2);
            input_data.push_back(posy_3);
            input_data.push_back(velx);
            input_data.push_back(vely);

            // saida
            output_data.push_back(vel);
            output_data.push_back(velang);

            // save data to .csv file
            Csv::save_data(input_data, "data/save_game/input.csv", ',');
            Csv::save_data(output_data, "data/save_game/output.csv", ',');

            // fim da gravação
            continua = false;
        }
       
        if(*_tempo % 100 == 0){
            // entradas
            posx_centro.push_back(interface->getPosX(0,0));
            posx_0.push_back(interface->getPosXQuina(0,0,0));
            posx_1.push_back(interface->getPosXQuina(0,0,1));
            posx_2.push_back(interface->getPosXQuina(0,0,2));
            posx_3.push_back(interface->getPosXQuina(0,0,3));
            posy_centro.push_back(interface->getPosY(0,0));
            posy_0.push_back(interface->getPosYQuina(0,0,0));
            posy_1.push_back(interface->getPosYQuina(0,0,1));
            posy_2.push_back(interface->getPosYQuina(0,0,2));
            posy_3.push_back(interface->getPosYQuina(0,0,3));
            velx.push_back(interface->getVelX(0,0));
            vely.push_back(interface->getVelY(0,0));

            // saidas
            vel.push_back(interface->getVel(0,0));
            velang.push_back(interface->getVelAng(0,0));
        }
    }
}


