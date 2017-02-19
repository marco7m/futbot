#include "eacontroller.h"
#include "wrsim/src/WRSim/controladorcompacto.h"

 
EAControler::EAControler(){
    for(int i = 0; i < NUM_NEURAL_NETWORK; i++){
        NeuralNetwork nn;
        neural_network.push_back(nn);
        NeuralNetwork tmp_nn;
        tmp_neural_network.push_back(tmp_nn);
    }
}

void EAControler::Run(){
    // loop que passa por cada uma das redes, testando elas
    for(int i = 0; i < (int)neural_network.size(); i++){
        ControladorCompacto controlador_compacto();
        inter = controlador_compacto.get_interface();


    }

}
