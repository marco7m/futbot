// Esse headcontroller faz o jogador jogar com outros robos parados

#include "one_player_alone.h"
#include <QTimer>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include "../wrsim/src/WRSim/interface.h"

OnePlayerAlone::OnePlayerAlone(){

    // inicialização dos robôs
    _robo = new robovss[robovss::nRobos];
    _robo[0].setTime(0);
    _robo[0].setIdRobo(0);
    
    _robo[1].setTime(1);
    _robo[1].setIdRobo(0);
    //

    _bola = new bola();
    _probe = new probe[cte::nProbes];

    Interface interface(_robo, _bola);
    
    _tempo = new unsigned long long;

    // cria fisica
    _fisica = new fisica(_robo, _tempo, _bola, _probe);
    //

    // inicia módulo gráfico
    _grafico = new grafico(_robo, _bola, _probe, interface);
    //

    // configurações pré inicio de partida

    // posiciona os robôs
    interface.setPosX(0,0,0.75);
    interface.setPosY(0,0,0.5);
//    interface.setAng(0,0,270);
    interface.setAng(0,0,0.75);
    
    interface.setPosX(1,0,0.25);
    interface.setPosY(1,0,0.5);
//    interface.setAng(1,0,90);
    interface.setAng(1,0,0.25);
    //

    // posiciona a bola
    interface.setPosBolaX(0.5);
    interface.setPosBolaY(0.5);
    //

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
