// esse headcontroller joga com uma IA treinada a partir dos dados coletados com o save_game

#include "simpleia.h"
#include <QTimer>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "../utils/csv.h"

SimpleIa::SimpleIa(){

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

    *_tempo = 0;
    
    _timer = new QTimer();
    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(mostra()));
    _timer->start(10);

    // debug
    neural_network.PrintTopology();
    neural_network.PrintNeuralNetwork();
}

SimpleIa::~SimpleIa(){
    delete[] _robo;
    delete[] _probe;
    delete _bola;
    delete _tempo;
    delete _fisica;
    delete _grafico;
    delete _timer;
    delete interface;
}

void SimpleIa::mostra(){
        _fisica->roda();
        *_tempo = *_tempo+10;
        _grafico->roda();


        // Entrada de dados
        input.ptr[0] = interface->getPosX(0,0);
        input.ptr[1] = interface->getPosXQuina(0,0,0);
        input.ptr[2] = interface->getPosXQuina(0,0,1);
        input.ptr[3] = interface->getPosXQuina(0,0,2);
        input.ptr[4] = interface->getPosXQuina(0,0,3);
        input.ptr[5] = interface->getPosY(0,0);
        input.ptr[6] = interface->getPosYQuina(0,0,0);
        input.ptr[7] = interface->getPosYQuina(0,0,1);
        input.ptr[8] = interface->getPosYQuina(0,0,2);
        input.ptr[9] = interface->getPosYQuina(0,0,3);
        input.ptr[10] = interface->getVelX(0,0);
        input.ptr[11] = interface->getVelY(0,0);

        // calcula a saida da rede neural a partir das entradas
        neural_network.DoTheJobOnce();
        
        // Saida de dados
        interface->setVel(0,0,output.ptr[0]);
        interface->setVelAng(0,0,output.ptr[1]);
}
