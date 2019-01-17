// Esse headcontroller compara a saida da rede neural com os dados usados
// para o treinamento, e verifica se ela está correta ou não

#ifndef GETBPERROR_H
#define GETBPERROR_H

#include <vector>
#include "../neuralnetwork/neuralnetwork.h"
#include "../utils/my_ptr.h"
#include "../utils/csv.h"

class GetBPError{
public:
    GetBPError();

private:
    
    double_ptr input = double_ptr(26);
    double_ptr output{2};

    NeuralNetwork neural_network{input, output, "nn0001.csv"};

    std::vector<std::vector<double> > data_input;
    std::vector<std::vector<double> > data_output;
    std::vector<double> error_0;
    std::vector<double> error_1;
};

#endif
