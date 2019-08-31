#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H

#include <vector>
#include "src/neuralnetwork/neuralnetwork.h"
#include "src/wrsim/src/WRSim/interface.h"
#include "src/controlsystem/gameplay.h"

class ControlSystem{
public:
    ControlSystem();
    ~ControlSystem();

private:
    // parametros de configuração
    const int ia_number = 100; // número de IAs a cada geração
    const int play_time = 60000; // tempo de duração da partida

    void create_random_population();
    void clear_population();

    std::vector<NeuralNetwork*> population;

//tirar populatio de global e criar ela no construtor
};

#endif
