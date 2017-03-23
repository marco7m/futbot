#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "neuron.h"
#include <vector>
#include <string>
#include "../utils/csv.h"


class NeuralNetwork{
public:
    NeuralNetwork(double_ptr in, double_ptr out, std::vector<int> tp);
    NeuralNetwork(double_ptr in, double_ptr out, std::string name);
    ~NeuralNetwork();
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

    // salva na primeira linha do arquivo .csv a topologia, na segunda linha os pesos dos neuronios
    // os pesos estão da seguinte forma:
    // todos os pesos do primeiro neuronio da rede mais perto da entrada, do segundo mais perto da entrada, e por ai vai
    // então ele começa a percorrer as outras fileiras até chegar a última.
    void SaveNetwork(std::string name);

    // igual a outra, mas sem a classe Csv
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
