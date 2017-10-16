#include "neuron.h"
#include <iostream>
#include "random.h"
#include "math.h"

Neuron::Neuron(){
    bias = 0;
}

void Neuron::set_randon_weight(){
    if(input.size == 0){
        std::cout << "ERROR: tried to set weight in neuron without inputs set." << std::endl;
        exit(1);
    }
    else{
        if((int)weight.size() != 0) weight.clear();
        for(int i = 0; i < input.size; i++){
            weight.push_back(randomize::unit_rand());
        }
    }
}

void Neuron::set_zero_weight(){
    if(input.size == 0){
        std::cout << "ERROR: tried to set weight in neuron without inputs set." << std::endl;
        exit(1);
    }
    else{
        if((int)weight.size() != 0) weight.clear();
        for(int i = 0; i < input.size; i++){
            weight.push_back(0);
        }
    }
}

void Neuron::connect_input(double_ptr in){
    input = in;
    set_zero_weight();
}

void Neuron::connect_output(double *out){
    output = out;
}

double Neuron::get_weight(int n){
    return weight[n];
}

void Neuron::set_weight(int n, double w){
    if(n >= (int)weight.size()){
        std::cout << "ERROR: can not set a weight in neuron bigger then the weights size." << std::endl;
        exit(1);
    }
    weight[n] = w;
}

double Neuron::get_bias(){
    return bias;
}

void Neuron::set_bias(double b){
    bias = b;
}

int Neuron::get_number_inputs(){
    return input.size;
}

// essa função não possui checagem de erros (verificar se todos os pesos já foram inicializados) por motivos de performance
void Neuron::work(){
    *output = 0;
    for(int i = 0; i < input.size; i++){
        *output += (weight[i] * input.ptr[i]);
    }
    *output += bias;  // *output += bias * 1
    // a função de ativação é tangente hiperbólico
    *output = (2/(1 + exp(-2 * (*output))))-1;
}


double Neuron::get_output_value(){
    return *output;
}
