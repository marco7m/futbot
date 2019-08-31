#include "evolutioncontrol.h"

EvolutionControl::EvolutionControl(){

}
EvolutionControl::~EvolutionControl(){
    clear_population();
}
// cria uma nova população com número de individuos igual a ia_number
// os pesos de cada individuo é inicializado com valores aleatórios entre -1 e 1
void EvolutionControl::create_random_population(int population_size){
    // crio uma topologia (sistema atual tem 88 entradas e 2 saidas)
    std::vector<int> tp{88,9,9,2};

    // carrego o vector de ponteiro de redes neurais que sera a minha população
    clear_population(); 
    for(int i = 0; i < population_size; i++){
        population.push_back({0,new NeuralNetwork(tp)});
    }

    return;
}

void EvolutionControl::train_the_guys(int play_time){
    GamePlay gp{};

    for(int i = 0; i < population.size(); i++){
        population[i].fitness = gp.fast_one_with_one_dead_robot(population[i].net, play_time, 0.5, 0.5, 0.8, 0.5);
    }
    sort(population.begin(), population.end(), [](Individual const &a, Individual const &b) { return a.fitness < b.fitness; });

    for(int i = 0; i < population.size(); i++){
        std::cout << population[i].fitness << std::endl;
    }


}

// deleta todos os ponteiros de NeuralNetwork dos individuos da população, e da um clear no vector
void EvolutionControl::clear_population(){
    for(int i = 0; i < (int)population.size(); i++){
        delete population[i].net;
    }
    population.clear();
}
