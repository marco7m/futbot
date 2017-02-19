#ifndef CONTROLADORCOMPACTO_H
#define CONTROLADORCOMPACTO_H

#include "fisica.h"
#include "objetos/bola.h"
#include "objetos/robovss.h"
#include "interface.h"
#include "evolutivealgorithm/observer.h"
#include "neuralnetwork/neuralnetwork.h"


class ControladorCompacto{
public:
    ControladorCompacto();
    void RealizaPartida(Observer obs, NeuralNetwork nn);
    interface* get_interface();
    void LiberaMemoria();
private:
    fisica *_fisica;
    interface *_interface;

    robovss *robo;
    bola *_bola;
    probe *_probe;
    unsigned long long *tempo; 
};

#endif
