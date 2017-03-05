#include "neuralnetwork.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

#define VERBOSE true

// primeiro cria os neuronios e os organiza na topologia escolhida
// depois connecta os neuronios
// depois seta os pesos deles
//
// CONEXOES:
// network_input - connector - network_output
NeuralNetwork::NeuralNetwork(double_ptr in, double_ptr out, std::vector<int> tp){
    set_input(in);
    set_output(out); 
    LoadNetwork("save0000.txt");
    PrintTopology();
    PrintNeuralNetwork();
//    DoTheJobOnce();
    DeleteAll();

//    set_topology(tp);
//    CreateNetwork();
//    set_input(in);
//    set_output(out); 
//    ConnectAll();
//    set_random_weights();
//    PrintTopology();
//    PrintNeuralNetwork();
////    DoTheJobOnce();
//    SaveNetwork("save0000.txt");
//    DeleteAll();
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
    if((network_input.size == 0) || (network_output.size == 0)){
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
        network[0][i].connect_input(network_input);
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
        network[(int)network.size()-1][i].connect_output(&network_output.ptr[i]);
        if(VERBOSE) std::cout << "conectando output do neuronio (" << (int)network.size()-1 << "," << i << ") com a output (" << i << ") da rede neural" << std::endl;
    }
}

void NeuralNetwork::DeleteAll(){
    if(VERBOSE) std::cout << std::endl << "DeleteAll" << std::endl;
    for(int i = 0; i < (int)connection.size(); i++){
        connection[i].del();
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
    if((network_output.size != topology[(int)topology.size() - 1]) && (network_output.size != 0)){
        std::cout << "ERROR: Outputs number differ from topology outputs number" << std::endl;
        exit(1);
    }

    // NÃO TESTADO
    // se a entrada já foi definida e a primeira camada tem um número diferente de neuronios do número de entradas, gera um erro
    if((network_input.size != topology[0]) && (network_output.size != 0)){
        std::cout << "ERROR: Inputs number differ from topology inputs number" << std::endl;
        exit(1);
    }
}

void NeuralNetwork::set_input(double_ptr i){
    if(VERBOSE) std::cout << std::endl << "set_input" << std::endl;
    network_input = i;

    // se a topologia já foi definida e a primeira camada tem um número diferente de neuronios do numero de entradas, gera um erro
    if(((int)topology.size() != 0) && (network_input.size != topology[0])){
        std::cout << "ERROR: Inputs number differ from topology inputs number" << std::endl;
        exit(1);
    }
}

void NeuralNetwork::set_output(double_ptr o){
    if(VERBOSE) std::cout << std::endl << "set_output" << std::endl;
    network_output = o;
    
    // NÃO TESTADO
    // se a topologia já foi definida e a última camada tem um número diferente de neuronios do número de saidas, gera um erro
    if(((int)topology.size() != 0) && (network_output.size != topology[(int)topology.size() - 1])){
        std::cout << "ERROR: Outputs number differ from topology outputs number" << std::endl;
        exit(1);
    }
}

void NeuralNetwork::DoTheJobOnce(){
    if(VERBOSE) std::cout << "DoTheJobOnce" << std::endl;
    for(int i = 0; i < (int)network.size(); i++){
        for(int j = 0; j < (int)network[i].size(); j++){
            network[i][j].work();
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
        }
    }
    nn_to_save.push_back(nn_line);
  
    // cria o arquivo e salva
    std::string data_name = "data/" + name;
    Csv::SaveData(nn_to_save, data_name, ',');
}

// essa função não usa a classe Csv que criei
void NeuralNetwork::_OldSaveNetwork(std::string name){
    if(VERBOSE) std::cout << std::endl << "_OldSaveNetwork" << std::endl;
    std::ofstream file;
    file.open(name.c_str());
    if(file.is_open()){
        for(int i = 0; i < (int)topology.size(); i++){
            file << topology[i];
            file << " ";
        }
        file << "\n ";
        // salva os pesos de todos os neurons, passando fileira por fileira, de cima para baixo
        for(int i = 0; i < (int)network.size(); i++){
            for(int j = 0; j < (int)network[i].size(); j++){
                // esse loop passa por todos os pesos do neuron
                for(int k = 0; k < topology[i]; k++){
                    file << network[i][j].get_weight(k);
                    file << " ";
                }
            }
        }
        file << "\n ";
        file.close();
    }
    else{
        std::cout << "ERROR: couldn't open file." << std::endl;
    }
}

void NeuralNetwork::_OldLoadNetwork(std::string name){
    if(VERBOSE) std::cout << std::endl << "LoadNetwork" << std::endl;

    if(topology.size() != 0) topology.clear();
    std::ifstream file;
    file.open(name);
    if(file.is_open()){
        std::string line = " ";
        // carrega topologia
        do{
            if(std::getline(file,line,' ')){
                if(line == "\n") break;
                topology.push_back(atoi(line.c_str()));
            }
        }while(line != "\n");

        // cria rede neural
        CreateNetwork();

        // conecta as entradas e saidas
        ConnectAll();

        //carrega pesos
        int i = 0; // coluna de neuronios
        int j = 0; // neuronio na coluna
        int k = -1; // peso no neuronio (-1 para a lógica dos ifs logo abaixo funcionar
        // debug
        PrintTopology();
        do{
            if(std::getline(file,line,' ')){
                if(line == "\n") break;

                // move as variaveis i,j,k
                if(++k < network[i][j].get_number_inputs()){
                }
                else if(++j < (int)network[i].size()){
                    k = 0;
                }
                else if(++i < (int)network.size()){
                    j = 0;
                    k = 0;
                }
                else{
                    break;
                }


                // aqui vai passar peso por peso que está no arquivo
                network[i][j].set_weight(k,std::stod(line.c_str()));
               
            }
        }while(line != "\n");
        file.close();
    }
    else{
        std::cout << "ERROR: couldn't open file." << std::endl;
        exit(1);
    }
}

void NeuralNetwork::LoadNetwork(std::string name){
    if(VERBOSE) std::cout << std::endl << "load" << std::endl;

    std::vector<std::vector<std::string> > nn_data;

    std::string data_name = "data/" + name;
    nn_data = Csv::GetStringData(data_name);

    if(topology.size() != 0) topology.clear();

    for(int i = 0; i < (int)nn_data[0].size(); i++){
        topology.push_back(atoi(nn_data[0][i].c_str()));
    }

    // cria rede neural
    CreateNetwork();

    // conecta as entradas e saidas
    ConnectAll();

    //carrega pesos
    int i = 0; // coluna de neuronios
    int j = 0; // neuronio na coluna
    int k = -1; // peso no neuronio (-1 para a lógica dos ifs logo abaixo funcionar
    // debug
    PrintTopology();
   
    for(int c = 0; i < (int)nn_data[1].size(); c++){
    
        // move as variaveis i,j,k
        if(++k < network[i][j].get_number_inputs()){
        }
        else if(++j < (int)network[i].size()){
            k = 0;
        }
        else if(++i < (int)network.size()){
            j = 0;
            k = 0;
        }
        else{
            break;
        }
        
        // aqui vai passar peso por peso que está no arquivo
        network[i][j].set_weight(k,std::stod(nn_data[1][c].c_str()));
        std::cout << "c=" << c << std::endl;
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
