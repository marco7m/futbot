#include "neuralnetwork.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

#define VERBOSE false

// primeiro cria os neuronios e os organiza na topologia escolhida
// depois connecta os neuronios
// depois seta os pesos deles
//
// CONEXOES:
// input - connector - output
NeuralNetwork::NeuralNetwork(std::vector<int> tp){
    double_ptr in{tp[0]};
    double_ptr out{tp[(int)tp.size() - 1]};

    set_input(in);
    set_output(out); 

    set_topology(tp);

    CreateNetwork();
    ConnectAll();
    set_random_weights();
}

NeuralNetwork::NeuralNetwork(double_ptr in, double_ptr out, std::string name){
    set_input(in);
    set_output(out);
    LoadNetwork(name);
    PrintTopology();
}

NeuralNetwork::NeuralNetwork(std::vector<std::vector<double> > nn_data){
    double_ptr in{nn_data[0][0]};
    double_ptr out{nn_data[0][nn_data[0].size() - 1]};
    set_input(in);
    set_output(out);
    LoadNetwork(nn_data);
}

NeuralNetwork::~NeuralNetwork(){
    if(VERBOSE) std::cout << std::endl << "DeleteAll" << std::endl;
    for(int i = 0; i < (int)connection.size(); i++){
        connection[i].del();
    }
}

void NeuralNetwork::CreateNetwork(){
    if(VERBOSE) std::cout << std::endl << "CreateNetwork" << std::endl;
    if(topology.size() != 0){
        network.clear();

        // caminha por cada coluna da rede, ignorando a [0] (num inputs da rede)
        for(int i = 1; i < (int)topology.size(); i++){
            // cria um vector de neuronios chamando o contrutor defalt de cada um
            std::vector<Neuron> tmp_vetor_pronto(topology[i]);
            network.push_back(tmp_vetor_pronto);
        }
    }
    else{
        std::cout << "ERROR: topology not defined." << std::endl;
        exit(1);
    }
}

void NeuralNetwork::PrintTopology(){
    if(VERBOSE) std::cout << std::endl << "PrintTopology" << std::endl;
    for(int j = 0; j < topology[0]; j++){
        std::cout << "I ";
    }
    std::cout << std::endl;
    for(int i = 1; i < (int)topology.size(); i++){
        for(int j = 0; j < topology[i]; j++){
            std::cout << "N ";
        }
        std::cout << std::endl;
    }
}

void NeuralNetwork::PrintNeuralNetwork(){
    if(VERBOSE) std::cout << std::endl << "PrintNeuralNetwork" << std::endl;
    if((int)network.size() == 0){
        std::cout << "ERROR: tried to print a neural network with size zero" << std::endl;
        exit(1);
    }
    for(int i = 0; i < (int)network.size(); i++){
        for(int k = 0; k < topology[i]; k++){ // percorre a coluna anterior, para saber o número de entradas que o neuronio tem
            for(int j = 0; j < (int)network[i].size(); j++){
                std::cout << "N(" << i << "," << j << ") " << network[i][j].get_weight(k) << "     \t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void NeuralNetwork::ConnectAll(){
    if(VERBOSE) std::cout << std::endl << "ConnectAll" << std::endl;
    // checa se as entradas e saidas da rede já foram conectadas
    if((input.size == 0) || (output.size == 0)){
        std::cout << "ERROR: Connect first the inputs and outputs to the neural network" << std::endl;
        exit(1);
    }
    // checa se as conexões já foram criadas entre os neuronios
    if((int)connection.size() != 0){
        std::cout << "ERROR: Connection already made" << std::endl;
        exit(1);
    }
    // cria todas as conexões, menos a das entradas e das saídas
    
    // conecta as entradas na primeira camada
    for(int i = 0; i < (int)network[0].size(); i++){
        network[0][i].connect_input(input);
        if(VERBOSE) std::cout << "conectando input do neuronio (0," << i << ") com input (*) da rede neural" << std::endl;
    }

    // cria as conexões e liga os neuronios
    // esse loop passa por todas as camadas da rede neural, menos a ultima 
    // que não precisa ser criada, pois é a saida
    for(int j = 0; j < ((int)network.size() - 1); j++){
        double_ptr tmp_connect((int)network[j].size());
        connection.push_back(tmp_connect);
        // conect as saidas nos neuronios
        for(int i = 0; i < (int)network[j].size(); i++){
            network[j][i].connect_output(&connection[j].ptr[i]);
            if(VERBOSE) std::cout << "conectando output do neuronio (" << j << "," << i << ") com o connection (" << j << "," << i << ")"<< std::endl;
        }
    }
    // conecta as entradas dos neuronios
    // menos da primeira camada, que já está conectada
    for(int j = 1; j < (int)network.size(); j++){
        for(int i = 0; i < (int)network[j].size(); i++){
            network[j][i].connect_input(connection[j-1]);
            if(VERBOSE) std::cout << "conectando input do neuronio (" << j << "," << i << ") com connection ("<< j-1 << ",*)" << std::endl;
        }
    }

    // conecta a saida da ultima camada de neuronios
    // com a saida da rede
    for(int i = 0; i < (int)network[(int)network.size()-1].size(); i++){
        //Explicação da linha de baixo:
        //
        //(int)network.size()-1 = indice da ultima coluna da network
        // i = passa por todos os neuronios da ultima coluna da network
        // (int)network.size()-2 = indice da connection que está entre a ultima e a penultima coluna da network
        // &connection[(int)]network.size()-2].ptr[i] = ponteiro que aponta para 
        network[(int)network.size()-1][i].connect_output(&output.ptr[i]);
        if(VERBOSE) std::cout << "conectando output do neuronio (" << (int)network.size()-1 << "," << i << ") com a output (" << i << ") da rede neural" << std::endl;
    }
}

void NeuralNetwork::set_topology(std::vector<int> t){
    if(VERBOSE) std::cout << std::endl << "set_topology" << std::endl;
    topology.clear();
    for(int i = 0; i < (int)t.size(); i++){
        topology.push_back(t[i]);
    }

    // NÃO TESTADO
    // se a saida já foi definida e a última camada tem um número diferente de neuronios do número de saidas, gera um erro
    if((output.size != topology[(int)topology.size() - 1]) && (output.size != 0)){
        std::cout << "ERROR: Outputs number differ from topology outputs number" << std::endl;
        exit(1);
    }

    // NÃO TESTADO
    // se a entrada já foi definida e a primeira camada tem um número diferente de neuronios do número de entradas, gera um erro
    if((input.size != topology[0]) && (output.size != 0)){
        std::cout << "ERROR: Inputs number differ from topology inputs number" << std::endl;
        exit(1);
    }
}

void NeuralNetwork::set_input(double_ptr i){
    if(VERBOSE) std::cout << std::endl << "set_input" << std::endl;
    input = i;

    // se a topologia já foi definida e a primeira camada tem um número diferente de neuronios do numero de entradas, gera um erro
    if(((int)topology.size() != 0) && (input.size != topology[0])){
        std::cout << "ERROR: Inputs number differ from topology inputs number" << std::endl;
        exit(1);
    }
}

void NeuralNetwork::set_output(double_ptr o){
    if(VERBOSE) std::cout << std::endl << "set_output" << std::endl;
    output = o;
    
    // NÃO TESTADO
    // se a topologia já foi definida e a última camada tem um número diferente de neuronios do número de saidas, gera um erro
    if(((int)topology.size() != 0) && (output.size != topology[(int)topology.size() - 1])){
        std::cout << "ERROR: Outputs number differ from topology outputs number" << std::endl;
        exit(1);
    }
}

void NeuralNetwork::feed(){
    if(VERBOSE) std::cout << "feed" << std::endl;
    for(int i = 0; i < (int)network.size(); i++){
        for(int j = 0; j < (int)network[i].size(); j++){
            network[i][j].work();
            // AAA NÃO ENTENDI ESSA PARTE
            if( i == (int)network.size() - 1 ){
                if(network[i][j].get_output_value() != 0){
                }
            }
        }
    }
}

void NeuralNetwork::SaveNetwork(std::string name){
    if(VERBOSE) std::cout << std::endl << "SaveNetwork" << std::endl;
    std::vector<std::vector<std::string> > nn_to_save;
    std::vector<std::string> nn_line;

    // prepara a primeira linha com a topologia
    for(int i = 0; i < (int)topology.size(); i++){
        nn_line.push_back(std::to_string(topology[i]));
    }
    nn_to_save.push_back(nn_line);
    nn_line.clear();
 
    // prepara a segunda linha com os pesos
    for(int i = 0; i < (int)network.size(); i++){
        for(int j = 0; j < (int)network[i].size(); j++){
            // esse loop passa por todos os pesos do neuron
            for(int k = 0; k < topology[i]; k++){
                nn_line.push_back(std::to_string(network[i][j].get_weight(k)));
            }
            // coloca a bias do neuronio logo após os pesos
            nn_line.push_back(std::to_string(network[i][j].get_bias()));
        }
    }
    nn_to_save.push_back(nn_line);
  
    // cria o arquivo e salva
    std::string data_name = "data/" + name;
    Csv::save_data(nn_to_save, data_name, ',');
}

void NeuralNetwork::LoadNetwork(std::vector<std::vector<double> > nn_data){
    if(VERBOSE) std::cout << std::endl << "LoadNetwork" << std::endl;

    if(topology.size() != 0) topology.clear();

    for(int i = 0; i < (int)nn_data[0].size(); i++){
        topology.push_back((int)nn_data[0][i]);
    }

    // cria rede neural
    CreateNetwork();

    // conecta as entradas e saidas
    ConnectAll();

    //carrega pesos
    int i = 0; // coluna de neuronios
    int j = 0; // neuronio na coluna
    int k = -1; // peso no neuronio (-1 para a lógica dos ifs logo abaixo funcionar
   
    for(int c = 0; i < (int)nn_data[1].size(); c++){ // i < (int)nn_data[1].size() (não entendi essa parte)
    
        // move as variaveis i,j,k
        if(++k < network[i][j].get_number_inputs() + 1){} // o + 1 é por causa da bias
        else if(++j < (int)network[i].size()){
            k = 0;
        }
        else if(++i < (int)network.size()){
            j = 0;
            k = 0;
        }
        else{
            if(c !=  (int)nn_data[1].size() ){
                std::cout << "ERROR: Weights in file are of a different number than are indicated by topology." << std::endl;
                exit(1);
            }
            else{
                break;
            }
        }
        
//        // DEBUG 
//        std::cout << "" << std::endl;
//        std::cout << "c = " << c << std::endl;
//        std::cout << "k = " << k << std::endl;
//        std::cout << "i = " << i << std::endl;
//        std::cout << "j = " << j << std::endl;
//        // fim DEBUG
       
        // aqui vai passar peso por peso e bias que está no arquivo
        if(k == network[i][j].get_number_inputs()){
            network[i][j].set_bias(nn_data[1][c]);
        }
        else{
            network[i][j].set_weight(k,nn_data[1][c]);
        }
    
    }
}

void NeuralNetwork::LoadNetwork(std::string data_name){
    if(VERBOSE) std::cout << std::endl << "LoadNetwork" << std::endl;

    std::vector<std::vector<double> > nn_data; 
    nn_data = Csv::get_double_data(data_name, ',');

    if(topology.size() != 0) topology.clear();

    for(int i = 0; i < (int)nn_data[0].size(); i++){
        topology.push_back((int)nn_data[0][i]);
    }

    // cria rede neural
    CreateNetwork();

    // conecta as entradas e saidas
    ConnectAll();

    //carrega pesos
    int i = 0; // coluna de neuronios
    int j = 0; // neuronio na coluna
    int k = -1; // peso no neuronio (-1 para a lógica dos ifs logo abaixo funcionar
   
    for(int c = 0; i < (int)nn_data[1].size(); c++){
    
        // move as variaveis i,j,k
        if(++k < network[i][j].get_number_inputs() + 1){} // o + 1 é por causa da bias
        else if(++j < (int)network[i].size()){
            k = 0;
        }
        else if(++i < (int)network.size()){
            j = 0;
            k = 0;
        }
        else{
            std::cout << "ERROR: More weights in file than are indicated by topology." << std::endl;
            std::cout << "" << std::endl;
            exit(1);
        }
        
        // aqui vai passar peso por peso e bias que está no arquivo
        if(k == network[i][j].get_number_inputs()){
            network[i][j].set_bias(nn_data[1][c]);
        }
        else{
            network[i][j].set_weight(k,nn_data[1][c]);
        }
    }
}

void NeuralNetwork::set_random_weights(){
    if(VERBOSE) std::cout << "set_random_weights" << std::endl;
    for(int i = 0; i < (int)network.size(); i++){
        for(int j = 0; j < (int)network[i].size(); j++){
            network[i][j].set_randon_weight();
        }
    }    
}

int NeuralNetwork::num_column(){
    return network.size();    
}

int NeuralNetwork::num_neurons_in_column(int column){
    return network[column].size();
}

int NeuralNetwork::num_inputs_neuron(uint8_t net_column, uint8_t neuron_in_column){
    return network[net_column][neuron_in_column].get_number_inputs();
}

double NeuralNetwork::get_neuron_weight(uint8_t net_column, uint8_t neuron_in_column, uint8_t neuron_input){
    return network[net_column][neuron_in_column].get_weight(neuron_input);
}

void NeuralNetwork::set_neuron_weight(uint8_t net_column, uint8_t neuron_in_column, uint8_t neuron_input, double weight_value){
    network[net_column][neuron_in_column].set_weight(neuron_input, weight_value);
}

double NeuralNetwork::get_neuron_bias(uint8_t net_column, uint8_t neuron_in_column){
    return network[net_column][neuron_in_column].get_bias();
}

void NeuralNetwork::set_neuron_bias(uint8_t net_column, uint8_t neuron_in_column, double bias_value){
    network[net_column][neuron_in_column].set_bias(bias_value);
}
