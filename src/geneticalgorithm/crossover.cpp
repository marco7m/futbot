#include "crossover.h"

Crossover::Crossover(){
    std::srand(std::time(nullptr));
}

void Crossover::alone(NeuralNetwork* nn_in, NeuralNetwork* nn_out, float rand_factor){
    for(int col = 0; col < nn_in->num_column(); col++){ // go through the columns
        for(int neu = 0; neu < nn_in->num_neurons_in_column(col); neu++){ // go through the neurons
            nn_out->set_neuron_bias(col, neu, nn_in->get_neuron_bias(col, neu) + simple_rand(rand_factor)); // update the bias
            for(int wgh = 0; wgh < nn_in->num_inputs_neuron(col, neu); wgh++){ // go through the weights of each neuron
                nn_out->set_neuron_weight(col, neu, wgh, nn_in->get_neuron_weight(col, neu, wgh) + simple_rand(rand_factor)); // update the weight
            }
        }
    }
}

// return a simetric random variable between -max and +max
double Crossover::simple_rand(double max){
    return (((double) std::rand() / (double) RAND_MAX) * 2 * max) - max;
}
