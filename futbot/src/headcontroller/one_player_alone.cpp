// Esse headcontroller faz o jogador jogar com outros robos parados

#include "one_player_alone.h"
#include <QTimer>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include "../wrsim/src/WRSim/interface.h"

OnePlayerAlone::OnePlayerAlone(){

    // inicialização dos ponteiros das vias
    _robo = new robovss[robovss::nRobos];
    _robo[0].setTime(0);
    _robo[0].setIdRobo(0);
    
    _robo[1].setTime(1);
    _robo[1].setIdRobo(0);

    _bola = new bola();
    _probe = new probe[cte::nProbes];

    Interface interface(_robo, _bola);
    
    _tempo = new unsigned long long;

    // cria fisica
    _fisica = new fisica(_robo, _tempo, _bola, _probe);

    // inicia módulo gráfico
    _grafico = new grafico(_robo, _bola, _probe, interface);

    // configurações pré inicio de partida

    // posiciona os robôs
    _robo[0].setX(1300);
    _robo[0].setY(650);
    
    _robo[1].setX(400);
    _robo[1].setY(650);


    // posiciona a bola
    _bola->setX(850);
    _bola->setY(650);

    *_tempo = 0;
    
    _timer = new QTimer();
    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(mostra()));
    _timer->start(10);
}

OnePlayerAlone::~OnePlayerAlone(){
    delete[] _robo;
    delete[] _probe;
    delete _bola;
    delete _tempo;
    delete _fisica;
    delete _grafico;
    delete _timer;
}

void OnePlayerAlone::mostra(){
        _fisica->roda();
        *_tempo = *_tempo+10;
        _grafico->roda();
}
