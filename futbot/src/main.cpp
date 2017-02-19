// main do HeadController

#include <QApplication>
#include "headcontroller/recordgame.h"

//// main generica
//int main(int argc, char *argv[]){
//    QApplication a(argc, argv);
//
//    RecordGame *_recordgame = new RecordGame();
//
//    return a.exec();
//}

//// main do WRSim
//
//#include <QApplication>
//#include "wrsim/src/WRSim/controle.h"
//
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//
//    // da início ao módulo principal
//    Controle *_controle = new Controle();
//
//    return a.exec();
//}


// main do NeuralNetwork

#include "neuralnetwork/neuralnetwork.h"
#include "neuralnetwork/neuron.h"
#include "utils/my_ptr.h"
#include <iostream>

int main(){
    std::vector<int> topologia1 = {2, 5, 4};

    std::vector<int> topologia2 = {3, 2, 6, 4, 5, 4, 3, 1};
    
    std::vector<int> topologia3 = {2, 3, 2};
    
    std::vector<int> topologia4 = {1, 4, 1, 3};

    double_ptr input(3);

    input.ptr[0] = 0.5;
    input.ptr[1] = 0.5;
    input.ptr[2] = 0.5;

    double_ptr output(1);

    NeuralNetwork neural_network(input, output, topologia2);
    

    return 0;
}
