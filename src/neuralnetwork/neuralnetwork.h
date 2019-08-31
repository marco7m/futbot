#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "neuron.h"
#include <vector>
#include <string>
#include "../utils/csv.h"


class NeuralNetwork{
public:
    NeuralNetwork(std::vector<int> tp);
    NeuralNetwork(double_ptr in, double_ptr out, std::string name);
    NeuralNetwork(std::vector<std::vector<double> > nn_data);
    ~NeuralNetwork();
    
    void CreateNetwork();
    void ConnectAll();
    
    void PrintTopology();
    void PrintNeuralNetwork();
    void set_topology(std::vector<int> t);
    void set_input(double_ptr i);
    void set_output(double_ptr o);
    void set_random_weights();
    
    double_ptr input;
    double_ptr output;
    
    void feed();

    // salva na primeira linha do arquivo .csv a topologia, na segunda linha os pesos dos neuronios
    // os pesos estão da seguinte forma:
    // todos os pesos do primeiro neuronio da rede mais perto da entrada, do segundo mais perto da entrada, e por ai vai
    // então ele começa a percorrer as outras fileiras até chegar a última.
    void SaveNetwork(std::string name);

    void LoadNetwork(std::vector<std::vector<double> > nn_data);
    void LoadNetwork(std::string name);

    // accessing neurons weights and bias from outside
    int num_column(); // number of columns of the neural network
    int num_neurons_in_column(int column); // number of neurons in column 'column'
    int num_inputs_neuron(uint8_t net_column, uint8_t neuron_in_column); // number of inputs connected to neuron
    double get_neuron_weight(uint8_t net_column, uint8_t neuron_in_column, uint8_t neuron_input); 
    void set_neuron_weight(uint8_t net_column, uint8_t neuron_in_column, uint8_t neuron_input, double weight_value); 
    double get_neuron_bias(uint8_t net_column, uint8_t neuron_in_column);
    void set_neuron_bias(uint8_t net_column, uint8_t neuron_in_column, double bias_value);

private:
    // a rede contém todos os neuronios
    // network[column][neurons_in_column]
    // network.size() => num columns
    // network[i].size() => num neurons in column i
    std::vector< std::vector<Neuron> > network;

    std::vector<double_ptr> connection;
    
    // = { num ent, num neur col 1, num neur col 2, ..., num neur col N}
    std::vector<int> topology;
};

#endif
