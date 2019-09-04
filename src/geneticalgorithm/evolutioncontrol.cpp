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
    std::vector<int> tp{10,1000,1000,1000,2};

    // carrego o vector de ponteiro de redes neurais que sera a minha população
    clear_population(); 
    for(int i = 0; i < population_size; i++){
        population.push_back({0,new NeuralNetwork(tp)});
    }

    return;
}

void EvolutionControl::train_the_guys(int game_duration){

    const int NUM_GENERATIONS = 10000; // number of generations
    const float PCT_SAVE_POPULATION = 0.1;

    GamePlay gp{};
    Crossover cross{};
    std::srand(std::time(nullptr));

    for(int gen = 0; gen < NUM_GENERATIONS; gen++){
        std::cout << "gen " << gen;
        double pos_ball_x;
        double pos_ball_y;
        double pos_rob_x;
        double pos_rob_y;
        pos_ball_x = ((float) std::rand() / (float) RAND_MAX) * 1;
        pos_ball_y = ((float) std::rand() / (float) RAND_MAX) * 1;
        pos_rob_x = 0.1 + (((float) std::rand() / (float) RAND_MAX) * 0.8);
        pos_rob_y = 0.1 + (((float) std::rand() / (float) RAND_MAX) * 0.8);
        for(int ind = 0; ind < population.size(); ind++){
            population[ind].fit = gp.fast_one_with_one_dead_robot(
                    population[ind].net, \
                    game_duration, \
                    pos_ball_x, \
                    pos_ball_y, \
                    pos_rob_x, \
                    pos_rob_y \
                    );
        }
        sort(population.begin(), population.end(), [](Individual const &a, Individual const &b) { return a.fit > b.fit; });

        std::cout << "\tbest " << population[0].fit;
        std::cout << "\tworst " << population[population.size()-1].fit << std::endl;

        // save game of the best one
        gp.fast_one_with_one_dead_robot(population[0].net, \
                game_duration, \
                pos_ball_x, \
                pos_ball_y, \
                pos_rob_x, \
                pos_rob_y, \
                std::string("data/referee/training12-big_nn/gen_") + std::to_string(gen) + std::string("-fit_") + std::to_string(population[0].fit) + std::string(".csv") \
                );

        // generate next generation
        int choosen_mate = 0;
        float rand_factor = 0;
        for(int i = population.size()*PCT_SAVE_POPULATION; i < population.size(); i++){
            choosen_mate = (int)(((float) std::rand() / (float) RAND_MAX) * PCT_SAVE_POPULATION*population.size());
            rand_factor = (((float) std::rand() / (float) RAND_MAX) * 0.5);
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
