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
    const int play_time = 10000; // tempo de duração da partida

    std::vector<NeuralNetwork*> create_random_population();

    std::vector<NeuralNetwork*> population;
    GamePlay gp{};

    void clear_population();

};

#endif
