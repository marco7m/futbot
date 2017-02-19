#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "neuron.h"
#include <vector>
#include <string>
#include "../utils/csv.h"


class NeuralNetwork{
public:
    NeuralNetwork(double_ptr in, double_ptr out, std::vector<int> tp);
    void CreateNetwork();
    void PrintTopology();
    void PrintNeuralNetwork();
    void ConnectAll();
    void DeleteAll();
    void set_topology(std::vector<int> t);
    void set_input(double_ptr i);
    void set_output(double_ptr o);
    void DoTheJobOnce();
    void set_random_weights();
    void SaveNetwork(std::string name);
    void _OldSaveNetwork(std::string name);
    void LoadNetwork(std::string name);
    void _OldLoadNetwork(std::string name);

private:
    // a rede contém todos os neuronios
    std::vector< std::vector<Neuron> > network;

    double_ptr network_input;
    double_ptr network_output;

    std::vector<double_ptr> connection;
    
    // = { num ent, num neur col 1, num neur col 2, ..., num neur col N}
    std::vector<int> topology;
};

#endif
