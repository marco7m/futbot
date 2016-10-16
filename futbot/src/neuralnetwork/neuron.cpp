#include "neuron.h"
#include <iostream>
#include "random.h"

Neuron::Neuron(){
}

Neuron::Neuron(std::vector<double> w){
    weight = w;
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

void Neuron::set_uni_weight(){
    if(input.size == 0){
        std::cout << "ERROR: tried to set weight in neuron without inputs set." << std::endl;
        exit(1);
    }
    else{
        if((int)weight.size() != 0) weight.clear();
        for(int i = 0; i < input.size; i++){
            weight.push_back(1);
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

int Neuron::get_number_inputs(){
    return input.size;
}

void Neuron::work(){
    *output = 0;
    for(int i = 0; i < input.size; i++){
        *output += (weight[i] * input.ptr[i]);
    }
    std::cout << *output << std::endl;
}
