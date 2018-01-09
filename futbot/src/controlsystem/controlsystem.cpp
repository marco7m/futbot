#include "controlsystem.h"

ControlSystem::ControlSystem(){
    // parametros de configuração
    ia_number = 9;

    create_random_population();
}

ControlSystem::~ControlSystem(){
    clear_population();
}

// cria uma nova população com número de individuos igual a ia_number
// os pesos de cada individuo é inicializado com valores aleatórios entre -1 e 1
std::vector<NeuralNetwork*> ControlSystem::create_random_population(){
    // crio uma topologia (sistema atual tem 88 entradas e 6 saidas)
    std::vector<int> tp{88,9,9,6};

    // carrego o vector de ponteiro de redes neurais que sera a minha população
    clear_population(); 
    for(int i = 0; i < ia_number; i++){
        NeuralNetwork* nn = new NeuralNetwork(tp);
        population.push_back(nn);
    }

    return population;
}

// deleta todos os ponteiros de NeuralNetwork dos individuos da população, e da um clear no vector
void ControlSystem::clear_population(){
    if(population.size() != 0){
        for(int i = 0; i < (int)population.size(); i++){
            delete population[i];
        }
        population.clear();
    }
}
