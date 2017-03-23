#include "controlewrsim.h"
#include <QTimer>
#include "cte.h"
#include <QDebug>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

ControleWRSim::ControleWRSim(){

    // inicialização dos ponteiros das vias
    _robo = new robovss[robovss::nRobos];
    _bola = new bola();
    _probe = new probe[cte::nProbes];
    
    // atualmente esta instancia está sendo criada sem necessidade
    _interface = new interface(_robo, _bola);

    _tempo = new unsigned long long;

    // cria fisica
    _fisica = new fisica(_robo, _tempo, _bola, _probe);

    // inicia módulo gráfico
    _grafico = new grafico(_robo, _bola, _probe);

    _timer = new QTimer();
    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(mostra()));
    _timer->start(10);

    // configurações pré inicio de partida

    // posiciona os robôs em um local aleatório do campo
    srand((int)std::time(0));
    for(int i = 0; i < robovss::nRobos; i++){
        _robo[i].setX((rand() % (int)(1500 - (2*_robo[i].largura))) + 100 + _robo[i].largura);
        _robo[i].setY((rand() % (int)(1300 - (2*_robo[i].largura))) + 25 + _robo[i].largura);
    }

    // posiciona a bola em um local aleatório do campo
    _bola->setX((rand() % (int)(1500 - (4*_bola->raio))) + 100 + _bola->raio*2);
    _bola->setY((rand() % (int)(1300 - (4*_bola->raio))) + 25 + _bola->raio*2);

    *_tempo = 0;
}

ControleWRSim::~ControleWRSim(){
    delete[] _robo;
    delete _bola;
    delete[] _probe;
    delete _tempo;
    delete _timer;
    delete _fisica;
    delete _grafico;
    delete _interface; 
}

void ControleWRSim::mostra(){
    _fisica->roda();
    *_tempo = *_tempo+10;
    _grafico->roda();
}

