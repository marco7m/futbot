#include "neuron.h"
#include "my_ptr.h"
#include <iostream>
#include "neuralnetwork.h"

int main(){
    std::vector<int> topologia1 = { 2, 5, 4 };

    std::vector<int> topologia2 = {2, 6, 4, 5, 4, 3, 1};
    
    std::vector<int> topologia3 = {2, 3, 2};
    
    std::vector<int> topologia4 = {1, 4, 1, 3};

    double_ptr input(3);
    input.ptr[0] = 0.5;
    input.ptr[1] = 0.5;
    input.ptr[2] = 0.5;

    double_ptr output(2);

    NeuralNetwork neural_network(input, output, topologia3);
    

    return 0;
}

