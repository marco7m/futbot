#include "gamewatch.h"

GameWatch::GameWatch(){
    has_ai = false;
    has_timer = false;
    has_grafico = false;
    record_game = false;

    // inicialização dos robôs
    _robo = new robovss[6];

    _robo[0].setTime(0);
    _robo[0].setIdRobo(0);
 
    _robo[1].setTime(0);
    _robo[1].setIdRobo(1);
 
    _robo[2].setTime(0);
    _robo[2].setIdRobo(2);
 
    _robo[3].setTime(1);
    _robo[3].setIdRobo(0);
 
    _robo[4].setTime(1);
    _robo[4].setIdRobo(1);
 
    _robo[5].setTime(1);
    _robo[5].setIdRobo(2);
 
    _bola = new bola();

    interface = Interface(_robo, _bola);

    _tempo = new unsigned long long;
    
    _referee = new Referee(interface, _tempo);
    
    // cria fisica
    _fisica = new fisica(_robo, _tempo, _bola, _probe);

    _probe = new probe[cte::nProbes];
    

    // configurações pré inicio de partida

    // posiciona os robôs
    interface.setPosX(0,0,0.25);
    interface.setPosY(0,0,0.5);
    interface.setAng(0,0,0.25);
    interface.setVel(0,0,0.5);
    interface.setVelAng(0,0,0.5);

    interface.setPosX(0,1,0.25);
    interface.setPosY(0,1,0.25);
    interface.setAng(0,1,0.25);
    interface.setVel(0,1,0.5);
    interface.setVelAng(0,1,0.5);

    interface.setPosX(0,2,0.25);
    interface.setPosY(0,2,0.75);
    interface.setAng(0,2,0.25);
    interface.setVel(0,2,0.5);
    interface.setVelAng(0,2,0.5);

    interface.setPosX(1,0,0.25);
    interface.setPosY(1,0,0.5);
    interface.setAng(1,0,0.25);
    interface.setVel(1,0,0.5);
    interface.setVelAng(1,0,0.5);

    interface.setPosX(1,1,0.25);
    interface.setPosY(1,1,0.25);
    interface.setAng(1,1,0.25);
    interface.setVel(1,1,0.5);
    interface.setVelAng(1,1,0.5);

    interface.setPosX(1,2,0.25);
    interface.setPosY(1,2,0.75);
    interface.setAng(1,2,0.25);
    interface.setVel(1,2,0.5);
    interface.setVelAng(1,2,0.5);

    // posiciona a bola
    interface.setPosBolaX(0.5);
    interface.setPosBolaY(0.5);
    interface.setVelBolaX(0.5);
    interface.setVelBolaY(0.5);

    *_tempo = 0;
}

GameWatch::~GameWatch(){
    delete[] _robo;
    delete[] _probe;
    delete _bola;
    delete _tempo;
    delete _fisica;
    if(has_grafico) delete _grafico;
    if(has_timer) delete _timer;
    delete _referee;
}

void GameWatch::mostra_watch_game(){
    _fisica->roda();
    _referee->check_game();
    _grafico->roda();
    
    *_tempo = *_tempo+10;

    // Entrada de dados
    int i = 0;
    for(int t = 0; t < 2; t++){
        for(int id = 0; id < 3; id++){
            input.ptr[i] = interface.getPosX(t,id);
            i++;
            input.ptr[i] = interface.getPosXQuina(t,id,0);
            i++;
            input.ptr[i] = interface.getPosXQuina(t,id,1);
            i++;
            input.ptr[i] = interface.getPosXQuina(t,id,2);
            i++;
            input.ptr[i] = interface.getPosXQuina(t,id,3);
            i++;
            input.ptr[i] = interface.getPosY(t,id);
            i++;
            input.ptr[i] = interface.getPosYQuina(t,id,0);
            i++;
            input.ptr[i] = interface.getPosYQuina(t,id,1);
            i++;
            input.ptr[i] = interface.getPosYQuina(t,id,2);
            i++;
            input.ptr[i] = interface.getPosYQuina(t,id,3);
            i++;
            input.ptr[i] = interface.getVelX(t,id);
            i++;
            input.ptr[i] = interface.getVelY(t,id);
            i++;
            input.ptr[i] = interface.getVelAng(t,id);
            i++;
            input.ptr[i] = interface.getVel(t,id);
            i++;
        }
    } 



}

void GameWatch::mostra(){
    _fisica->roda();
    _referee->check_game();
    _grafico->roda();
    
    *_tempo = *_tempo+10;

    if(has_ai){
        // Entrada de dados
        int i = 0;
        for(int t = 0; t < 2; t++){
            for(int id = 0; id < 3; id++){
                input.ptr[i] = interface.getPosX(t,id);
                i++;
                input.ptr[i] = interface.getPosXQuina(t,id,0);
                i++;
                input.ptr[i] = interface.getPosXQuina(t,id,1);
                i++;
                input.ptr[i] = interface.getPosXQuina(t,id,2);
                i++;
                input.ptr[i] = interface.getPosXQuina(t,id,3);
                i++;
                input.ptr[i] = interface.getPosY(t,id);
                i++;
                input.ptr[i] = interface.getPosYQuina(t,id,0);
                i++;
                input.ptr[i] = interface.getPosYQuina(t,id,1);
                i++;
                input.ptr[i] = interface.getPosYQuina(t,id,2);
                i++;
                input.ptr[i] = interface.getPosYQuina(t,id,3);
                i++;
                input.ptr[i] = interface.getVelX(t,id);
                i++;
                input.ptr[i] = interface.getVelY(t,id);
                i++;
                input.ptr[i] = interface.getVelAng(t,id);
                i++;
                input.ptr[i] = interface.getVel(t,id);
                i++;
            }
        } 

        input.ptr[i] = interface.getPosBolaX(0);
                i++;
        input.ptr[i] = interface.getPosBolaY();
                i++;
        input.ptr[i] = interface.getVelBolaX(0);
                i++;
        input.ptr[i] = interface.getVelBolaY();
        std::cout << "i = " << i << std::endl;
        i = 0;

        // calcula a saida da rede neural a partir das entradas
        neural_network.DoTheJobOnce();
        
        // Saida de dados
        interface.setVel(0,0,output.ptr[0]);
        interface.setVelAng(0,0,output.ptr[1]);
        interface.setVel(0,1,output.ptr[2]);
        interface.setVelAng(0,1,output.ptr[3]);
        interface.setVel(0,2,output.ptr[4]);
        interface.setVelAng(0,2,output.ptr[5]);
    }

    // se vai salvar o jogo:
    if(record_game){
        // armazena dados a cada 100 milisegundos
        if(*_tempo % 100 == 0){
            // Entrada de dados
            int i = 0;
            for(int t = 0; t < 2; t++){
                for(int id = 0; id < 3; id++){
                    input_data[i].push_back(interface.getPosX(t,id));
                    i++;
                    input_data[i].push_back(interface.getPosXQuina(t,id,0));
                    i++;
                    input_data[i].push_back(interface.getPosXQuina(t,id,1));
                    i++;
                    input_data[i].push_back(interface.getPosXQuina(t,id,2));
                    i++;
                    input_data[i].push_back(interface.getPosXQuina(t,id,3));
                    i++;
                    input_data[i].push_back(interface.getPosY(t,id));
                    i++;
                    input_data[i].push_back(interface.getPosYQuina(t,id,0));
                    i++;
                    input_data[i].push_back(interface.getPosYQuina(t,id,1));
                    i++;
                    input_data[i].push_back(interface.getPosYQuina(t,id,2));
                    i++;
                    input_data[i].push_back(interface.getPosYQuina(t,id,3));
                    i++;
                    input_data[i].push_back(interface.getVelX(t,id));
                    i++;
                    input_data[i].push_back(interface.getVelY(t,id));
                    i++;
                    input_data[i].push_back(interface.getVelAng(t,id));
                    i++;
                    input_data[i].push_back(interface.getVel(t,id));
                    i++;
                }
            } 

            input_data[i].push_back(interface.getPosBolaX(0));
                    i++;
            input_data[i].push_back(interface.getPosBolaY());
                    i++;
            input_data[i].push_back(interface.getVelBolaX(0));
                    i++;
            input_data[i].push_back(interface.getVelBolaY());
            
            i = 0;
            
            // Saida de dados
            output_data[0].push_back(interface.getVel(0,0));
            output_data[1].push_back(interface.getVelAng(0,0));
            output_data[2].push_back(interface.getVel(0,1));
            output_data[3].push_back(interface.getVelAng(0,1));
            output_data[4].push_back(interface.getVel(0,2));
            output_data[5].push_back(interface.getVelAng(0,2));
        }
        if((int)*_tempo > recording_time){
            _timer->stop();

            // save data to .csv file
            Csv::save_data(input_data, "data/gamewatch/input.csv", ',');
            Csv::save_data(output_data, "data/gamewatch/output.csv", ',');
        }
    }



    // printa tempo
//    if(*_tempo % 100 == 0) std::cout << *_tempo << std::endl;
}

void GameWatch::watch_game(std::string ia_0, std::string ia_1){
    double_ptr input_ia_0{88};
    double_ptr output_ia_0{6};

    double_ptr input_ia_1 = double_ptr(88);
    double_ptr output_ia_1 = double_ptr(6);

    NeuralNetwork ia0 = NeuralNetwork(input_ia_0, output_ia_0, ia_0);
    NeuralNetwork ia1 = NeuralNetwork(input_ia_1, output_ia_1, ia_1);

    grafico _grafico = grafico(_robo, _bola, _probe, interface);

}


//void GameWatch::watch_game(){
//    has_ai = true;
//    record_game = false;
//
//    _grafico = new grafico(_robo, _bola, _probe, interface);
//    has_grafico = true;
//   
//    _timer = new QTimer();
//    has_timer = true;
//    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(mostra()));
//    _timer->start(10);
//}

void GameWatch::manual_mode(){
    has_ai = false;
    record_game = false;

    _grafico = new grafico(_robo, _bola, _probe, interface);
    has_grafico = true;
   
    _timer = new QTimer();
    has_timer = true;
    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(mostra()));
    _timer->start(10);
}

// saves all inputs and as output only the data of team 0
void GameWatch::manual_save_game(int rt){
    has_ai = false;
    record_game = true;

    recording_time = rt;

    // inicializa input_data
    for(int i = 0; i < input.size; i++){
        std::vector<double> tmp;
        input_data.push_back(tmp);
    }
    
    // inicializa output_data
    for(int i = 0; i < 6; i++){
        std::vector<double> tmp;
        output_data.push_back(tmp);
    }    

    _grafico = new grafico(_robo, _bola, _probe, interface);
    has_grafico = true;
   
    _timer = new QTimer();
    has_timer = true;
    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(mostra()));
    _timer->start(10);
}
