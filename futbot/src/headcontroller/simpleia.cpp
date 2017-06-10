#include "simpleia.h"
#include <QTimer>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "../utils/csv.h"

SimpleIa::SimpleIa(){

    // inicialização dos ponteiros das vias
    _robo = new robovss[robovss::nRobos];
    _bola = new bola();
    _probe = new probe[cte::nProbes];
    
    _tempo = new unsigned long long;

    // cria fisica
    _fisica = new fisica(_robo, _tempo, _bola, _probe);

    // inicia módulo gráfico
    _grafico = new grafico(_robo, _bola, _probe);

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
}

void SimpleIa::mostra(){
        _fisica->roda();
        *_tempo = *_tempo+10;
        _grafico->roda();


        // Entrada de dados
        // jogador lado esquerdo
        input.ptr[0] = _robo[1].getX();
        input.ptr[1] = _robo[1].getY();
        input.ptr[2] = getQuinas(_robo[1], 0).x();
        input.ptr[3] = getQuinas(_robo[1], 0).y();
        input.ptr[4] = getQuinas(_robo[1], 1).x();
        input.ptr[5] = getQuinas(_robo[1], 1).y();
        input.ptr[6] = getQuinas(_robo[1], 2).x();
        input.ptr[7] = getQuinas(_robo[1], 2).y();
        input.ptr[8] = getQuinas(_robo[1], 3).x();
        input.ptr[9] = getQuinas(_robo[1], 3).y();
        input.ptr[10] = _robo[1].getVel();
        input.ptr[11] = _robo[1].getVelAng();
  
      
        // jogador lado direito
        input.ptr[12] = _robo[0].getX();
        input.ptr[13] = _robo[0].getY();
        input.ptr[14] = getQuinas(_robo[0], 0).x();
        input.ptr[15] = getQuinas(_robo[0], 0).y();
        input.ptr[16] = getQuinas(_robo[0], 1).x();
        input.ptr[17] = getQuinas(_robo[0], 1).y();
        input.ptr[18] = getQuinas(_robo[0], 2).x();
        input.ptr[19] = getQuinas(_robo[0], 2).y();
        input.ptr[20] = getQuinas(_robo[0], 3).x();
        input.ptr[21] = getQuinas(_robo[0], 3).y();
           
  
      // bola
        input.ptr[22] = _bola->getX();
        input.ptr[23] = _bola->getY();
        input.ptr[24] = _bola->getVelX();
        input.ptr[25] = _bola->getVelY();
        input.ptr[26] = _robo[0].getVel();
        input.ptr[27] = _robo[0].getVelAng();

        for(int h = 0; h < input.size; h++){
            input.ptr[h] = input.ptr[h]/1000;
        }

        // calcula a sainda da rede neural a partir das entradas
        neural_network.DoTheJobOnce();
        
        // Saida de dados
        _robo[0].setVel(output.ptr[0] * 1000);
        _robo[0].setVelAng(output.ptr[1] * 1000);

}

QPointF SimpleIa::getQuinas(robovss rob, int l){ // 0 - top dir; 1 - bai dir; 2 - bai esq; 3 - top esq
    QPointF quina;
    if(l == 0){
        quina.setY(rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() + 45))));
        quina.setX(rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() + 45))));
    }
    if(l == 1){
        quina.setY(rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() + 135))));
        quina.setX(rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() + 135))));
    }
    if(l == 2){
        quina.setY(rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() + 225))));
        quina.setX(rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() + 225))));
    }
    if(l == 3){
        quina.setY(rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() - 45))));
        quina.setX(rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() - 45))));
    }
    return quina;
}
