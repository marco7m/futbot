// main do HeadController

#include <QApplication>
#include "controlsystem/gameplay.h"
#include "controlsystem/controlsystem.h"
#include "utils/csv.h"
#include <iostream>

// main generica
int main(int argc, char *argv[]){
//    QApplication a(argc, argv);

    ControlSystem cs{};
//    GamePlay gameplay{};
//    gameplay.save_manual_mode(60000);
//    gameplay.manual_mode();

//    std::vector<std::vector<double> > team_a = Csv::get_double_data("data/ia_list/nn_teste/nn_teste.csv");
//    std::vector<std::vector<double> > team_b = Csv::get_double_data("data/ia_list/nn_teste/nn_teste.csv");
//    gameplay.fast_mode(team_a, team_b, 3600000);
//    gameplay.watch_mode(team_a, team_b);

//    return a.exec();
    return 0;
}





//========================================================

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

//========================================================

//// main do NeuralNetwork
//
//#include "neuralnetwork/neuralnetwork.h"
//#include "neuralnetwork/neuron.h"
//#include "utils/my_ptr.h"
//#include <iostream>
//
//int main(){
//    std::vector<int> topologia1 = {2, 5, 4};
//
//    std::vector<int> topologia2 = {3, 2, 6, 4, 5, 4, 3, 1};
//    
//    std::vector<int> topologia3 = {2, 3, 2};
//    
//    std::vector<int> topologia4 = {1, 4, 1, 3};
//
//    double_ptr input(3);
//
//    input.ptr[0] = 0.5;
//    input.ptr[1] = 0.5;
//    input.ptr[2] = 0.5;
//
//    double_ptr output(1);
//
//    NeuralNetwork neural_network(input, output, topologia2);
//    
//
//    return 0;
//}

//========================================================
//
// main do NeuralNetwork 2
//
//#include "neuralnetwork/neuralnetwork.h"
//#include "neuralnetwork/neuron.h"
//#include "utils/my_ptr.h"
//#include <iostream>
//
//int main(){
//    double_ptr input(26);
//
//    double_ptr output(2);
//
//    NeuralNetwork neural_network(input, output, "nn0001.csv");
//
//    return 0;
//}
