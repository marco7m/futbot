#include "crossover.h"

Crossover::Crossover(){

}

void Crossover::alone(NeuralNetwork* nn, float rand_factor){
    std::srand(std::time(nullptr));
    for(int col = 0; col < nn->num_column(); col++){
        for(int neu = 0; neu < nn->num_neurons_in_column(col); neu++){
            for(int wgh = 0; wgh < nn->num_inputs_neuron(col, neu); wgh++){
                float rand_characteristic = (std::rand() % rand_factor) - (rand_factor-1)/2; // DA PRA MELHORAR
                nn.set_neuron_weight(col, neu, wgh, nn->get_neuron_weight(col, neu, wgh) + rand_characteristic);
            }
        }
    }
}
