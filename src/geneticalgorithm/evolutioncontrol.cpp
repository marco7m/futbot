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
    std::vector<int> tp{6,60,60,60,2};

    // carrego o vector de ponteiro de redes neurais que sera a minha população
    clear_population(); 
    for(int i = 0; i < population_size; i++){
        population.push_back({0,new NeuralNetwork(tp)});
    }

    return;
}

void EvolutionControl::train_the_guys(int game_duration){
    GamePlay gp{};
    Crossover cross{};
    std::srand(std::time(nullptr));

    for(int gen = 0; gen < 120; gen++){
        std::cout << "gen " << gen << std::endl;
        for(int ind = 0; ind < population.size(); ind++){
            population[ind].fit = gp.fast_one_with_one_dead_robot(population[ind].net, game_duration, 0.5, 0.5, 0.8, 0.5);
        }
        sort(population.begin(), population.end(), [](Individual const &a, Individual const &b) { return a.fit > b.fit; });
        
        std::cout << "best " << population[0].fit << std::endl;
        std::cout << "worst " << population[population.size()-1].fit << std::endl;

        // save game of the best one
        gp.fast_one_with_one_dead_robot(population[0].net, game_duration, 0.5, 0.5, 0.8, 0.5,std::string("data/referee/training07/gen_") + std::to_string(gen) + std::string("-fit_") + std::to_string(population[0].fit) + std::string(".csv"));

        // generate next generation
        std::cout << "std::time "<< std::time(nullptr) << std::endl;
        float pct_to_save = 0.1;
        int choosen_mate = 0;
        float rand_factor = 0;
        for(int i = population.size()*pct_to_save; i < population.size(); i++){
            choosen_mate = (int)(((float) std::rand() / (float) RAND_MAX) * pct_to_save*population.size());
            rand_factor = (((float) std::rand() / (float) RAND_MAX) * 0.1);
            cross.alone(population[choosen_mate].net, population[i].net,rand_factor);        
        }
    }
}

// deleta todos os ponteiros de NeuralNetwork dos individuos da população, e da um clear no vector
void EvolutionControl::clear_population(){
    for(int i = 0; i < (int)population.size(); i++){
        delete population[i].net;
    }
    population.clear();
}
