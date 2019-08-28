#include "controlsystem.h"

ControlSystem::ControlSystem(){
    // parametros de configuração
    ia_number = 100;
    play_time = 10*1000*60; 
    play_time = 10000;

    create_random_population();

//    gp.get_fit_move_point(population[0], population[0], play_time);
    gp.play_saved_game();
    
}

ControlSystem::~ControlSystem(){
    clear_population();
}

// cria uma nova população com número de individuos igual a ia_number
// os pesos de cada individuo é inicializado com valores aleatórios entre -1 e 1
std::vector<NeuralNetwork*> ControlSystem::create_random_population(){
    // crio uma topologia (sistema atual tem 88 entradas e 6 saidas)
    std::vector<int> tp{88,9,9,6};

    // carrego o vector de ponteiro de redes neurais que sera a minha população
    clear_population(); 
    for(int i = 0; i < ia_number; i++){
        NeuralNetwork* nn = new NeuralNetwork(tp);
        population.push_back(nn);
    }

    return population;
}

void ControlSystem::feed_forward(NeuralNetwork* nn){
    //======================  ENTRADA DE DADOS IA_A =========================
    int i = 0;
    for(int t = 0; t < 2; t++){
        for(int id = 0; id < 3; id++){
            nn->input.ptr[i] = interface.getPosX(t,id);
            i++;
            nn->input.ptr[i] = interface.getPosXQuina(t,id,0);
            i++;
            nn->input.ptr[i] = interface.getPosXQuina(t,id,1);
            i++;
            nn->input.ptr[i] = interface.getPosXQuina(t,id,2);
            i++;
            nn->input.ptr[i] = interface.getPosXQuina(t,id,3);
            i++;
            nn->input.ptr[i] = interface.getPosY(t,id);
            i++;
            nn->input.ptr[i] = interface.getPosYQuina(t,id,0);
            i++;
            nn->input.ptr[i] = interface.getPosYQuina(t,id,1);
            i++;
            nn->input.ptr[i] = interface.getPosYQuina(t,id,2);
            i++;
            nn->input.ptr[i] = interface.getPosYQuina(t,id,3);
            i++;
            nn->input.ptr[i] = interface.getVelX(t,id);
            i++;
            nn->input.ptr[i] = interface.getVelY(t,id);
            i++;
            nn->input.ptr[i] = interface.getVelAng(t,id);
            i++;
            nn->input.ptr[i] = interface.getVel(t,id);
            i++;
        }
    } 
    nn->input.ptr[i] = interface.getPosBolaX();
    i++;
    nn->input.ptr[i] = interface.getPosBolaY();
    i++;
    nn->input.ptr[i] = interface.getVelBolaX();
    i++;
    nn->input.ptr[i] = interface.getVelBolaY();
    i = 0;

    // aplica as entradas na rede neural
    nn->feed();

    // APLICA AS SAIDAS DAS REDES NEURAIS

    // saida dos dados da rede neural A
    interface.setVel(0,0,nn->output.ptr[0]);
    interface.setVelAng(0,0,nn->output.ptr[1]);
}

// deleta todos os ponteiros de NeuralNetwork dos individuos da população, e da um clear no vector
void ControlSystem::clear_population(){
    for(int i = 0; i < (int)population.size(); i++){
        delete population[i];
    }
    population.clear();
}


