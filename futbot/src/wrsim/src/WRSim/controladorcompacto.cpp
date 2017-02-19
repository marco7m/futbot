#include "controladorcompacto.h"
#include "cte.h"

ControladorCompacto::ControladorCompacto(){

    robo = new robovss[robovss::nRobos];
    _bola = new bola();
    _probe = new probe[cte::nProbes];
    _interface = new interface(robo, _bola);
    
    tempo = new unsigned long long;
    
    _fisica = new fisica(robo, tempo, _bola, _probe);

    // configurações pré inicio de partida

    // posiciona os robôs
        robo[0].setX(1300);
        robo[0].setY(687.5);

    // posiciona a bola
    _bola->setX(0);
    _bola->setY(0);

    *tempo = 0;
}

void ControladorCompacto::RealizaPartida(Observer observer, NeuralNetwork neural_network){
    
    _fisica->roda();

    while(*tempo < 1200000){ // partidade 1200000 ms ou 20 min
        neural_network.Run();
        _fisica->roda();
        observer.Run();
        *tempo = *tempo+10;
    }
}

interface* ControladorCompacto::get_interface(){
    return _interface;
}

void ControladorCompacto::LiberaMemoria(){
    _fisica->liberaMemoria();
    delete _fisica;
    delete _interface;
    delete[] robo;
    delete _bola;
    delete[] _probe;
    delete tempo;
}
