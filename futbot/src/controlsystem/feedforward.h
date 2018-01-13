#ifndef FEEDFORWARD_H
#define FEEDFORWARD_H

#include "src/neuralnetwork/neuralnetwork.h"
#include "src/wrsim/src/WRSim/interface.h"

class FeedForward{
public:
    FeedForward(NeuralNetwork* iaa, NeuralNetwork* iab, Interface inter);

    // IAs = 2
    // Inputs = 88
    // Outputs = 6
    // uma partida normal com dois times de 3 robôs cada
    void ia_match();

    // IAs = 1
    // Inputs = 
    // Outputs = 
    // uma partida com apenas um robô, o robô do time 0 e com id 0
    // os outros robôs e a bola estarão escondidos no canto superior esquerdo
    void ia_alone();

private:
    NeuralNetwork* ia_a = nullptr;
    NeuralNetwork* ia_b = nullptr;
    Interface interface;

};

#endif
