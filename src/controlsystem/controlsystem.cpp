#include "controlsystem.h"

ControlSystem::ControlSystem(){

    std::cout << "Create population" << std::endl;
    create_random_population();

    GamePlay gp{};

    std::vector<double> value;
    for(int i = 0; i < ia_number; i++){
        std::cout << "match: " << i << std::endl;
        value.push_back(gp.fast_one_with_one_dead_robot(population[i], play_time, 0.5, 0.5, 0.8, 0.5));
    }

    for(int i = 0; i < value.size(); i++){
        std::cout << "value: " << value[i] << std::endl;
    }
}

ControlSystem::~ControlSystem(){
    std::cout << "Purge the world" << std::endl;
    clear_population();
}

// cria uma nova população com número de individuos igual a ia_number
// os pesos de cada individuo é inicializado com valores aleatórios entre -1 e 1
void ControlSystem::create_random_population(){
    // crio uma topologia (sistema atual tem 88 entradas e 6 saidas)
    std::vector<int> tp{88,9,9,2};

    // carrego o vector de ponteiro de redes neurais que sera a minha população
    clear_population(); 
    for(int i = 0; i < ia_number; i++){
        NeuralNetwork* nn = new NeuralNetwork(tp);
        population.push_back(nn);
    }

    return;
}

// deleta todos os ponteiros de NeuralNetwork dos individuos da população, e da um clear no vector
void ControlSystem::clear_population(){
    for(int i = 0; i < (int)population.size(); i++){
        delete population[i];
    }
    population.clear();
}
