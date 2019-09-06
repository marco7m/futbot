#ifndef FEEDFORWARD_H
#define FEEDFORWARD_H

#include "src/neuralnetwork/neuralnetwork.h"
#include "src/wrsim/src/WRSim/interface.h"

class FeedForward{
public:
    FeedForward(Interface inter, NeuralNetwork* iaa, NeuralNetwork* iab = nullptr);

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
    void ia_alone_full_raw_inputs();
    void ia_alone_with_ball_pos();
    void ia_alone_with_ball_pos_and_more();

private:
    NeuralNetwork* ia_a = nullptr;
    NeuralNetwork* ia_b = nullptr;
    Interface interface;

};

#endif
