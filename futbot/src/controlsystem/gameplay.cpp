#include "gameplay.h"

#include <iostream>
#include "wrsim/src/WRSim/interface.h"
#include "utils/csv.h"

GamePlay::GamePlay(){
}

GamePlay::~GamePlay(){
    clear_all_pointers();
}

void GamePlay::get_fit_move_point(NeuralNetwork* _neural_network_a, NeuralNetwork* _neural_network_b, double play_time){

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
    _interface = new Interface(_robo, _bola);
    _tempo = new unsigned long long;
    _referee = new Referee(*_interface, _tempo);
    _fisica = new fisica(_robo, _tempo, _bola);
    _feedforward = new FeedForward(_neural_network_a, _neural_network_b, *_interface);

    // posiciona os robôs
    MoveRobots::default_position(*_interface);

    *_tempo = 0;

    while(*_tempo < play_time){
        _fisica->roda();
        _referee->check_game();

        *_tempo = *_tempo+10;   

        _feedforward->ia_match();
    }

    clear_all_pointers();
}


void GamePlay::fast_mode(std::vector<std::vector<double> > team_a, std::vector<std::vector<double> > team_b, double play_time){

    _neural_network_a = new NeuralNetwork(team_a);
    _neural_network_b = new NeuralNetwork(team_b);

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
    _interface = new Interface(_robo, _bola);
    _tempo = new unsigned long long;
    _referee = new Referee(*_interface, _tempo);
    _fisica = new fisica(_robo, _tempo, _bola);
    _feedforward = new FeedForward(_neural_network_a, _neural_network_b, *_interface);

    // posiciona os robôs
    MoveRobots::default_position(*_interface);

    *_tempo = 0;

    while(*_tempo < play_time){
        _fisica->roda();
        _referee->check_game();

        *_tempo = *_tempo+10;   

        _feedforward->ia_match();
    }

    clear_all_pointers();
}

void GamePlay::watch_mode(std::vector<std::vector<double> > team_a, std::vector<std::vector<double> > team_b){

    _neural_network_a = new NeuralNetwork(team_a);
    _neural_network_b = new NeuralNetwork(team_b);

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
    _interface = new Interface(_robo, _bola);
    _tempo = new unsigned long long;
    _referee = new Referee(*_interface, _tempo);
    _fisica = new fisica(_robo, _tempo, _bola);
    _feedforward = new FeedForward(_neural_network_a, _neural_network_b, *_interface);

    // posiciona os robôs
    MoveRobots::default_position(*_interface);

    *_tempo = 0;

    // cria parte gráfica
    _grafico = new grafico(_robo, _bola, *_interface);

    // cria e inicializa o timer
    _timer = new QTimer();
    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(slot_watch_mode()));
    _timer->start(10);
}

void GamePlay::manual_mode(){
    
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
    _interface = new Interface(_robo, _bola);
    _tempo = new unsigned long long;
    _referee = new Referee(*_interface, _tempo);
    _fisica = new fisica(_robo, _tempo, _bola);

    // configurações pré inicio de partida

    // posiciona os robôs
    MoveRobots::default_position(*_interface);
    
    *_tempo = 0;

    // cria parte gráfica
    _grafico = new grafico(_robo, _bola, *_interface);

    // cria e inicializa o timer
    _timer = new QTimer();
    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(slot_manual_mode()));
    _timer->start(10);
}

void GamePlay::save_manual_mode(double tst){
    total_save_time = tst;
    
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
    _interface = new Interface(_robo, _bola);
    _tempo = new unsigned long long;
    _referee = new Referee(*_interface, _tempo);
    _fisica = new fisica(_robo, _tempo, _bola);

    // posiciona os robôs
    MoveRobots::default_position(*_interface);

    *_tempo = 0;

    // cria parte gráfica
    _grafico = new grafico(_robo, _bola, *_interface);

    // cria e inicializa o timer
    _timer = new QTimer();
    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(slot_save_manual_mode()));
    _timer->start(10);
}

void GamePlay::slot_watch_mode(){
    _fisica->roda();
    _referee->check_game();
    _grafico->roda();
    *_tempo = *_tempo+10;
    _feedforward->ia_match();
}

void GamePlay::slot_manual_mode(){
    _fisica->roda();
    _referee->check_game();
    _grafico->roda();
    *_tempo = *_tempo+10;
}

void GamePlay::slot_save_manual_mode(){
    _fisica->roda();
    _referee->check_game();
    _grafico->roda();
    *_tempo = *_tempo+10;

    std::vector<double> data_line_input;
    std::vector<double> data_line_output;

    for(int t = 0; t < 2; t++){
        for(int id = 0; id < 3; id++){
            data_line_input.push_back(_interface->getPosX(t,id));
            data_line_input.push_back(_interface->getPosXQuina(t,id,0));
            data_line_input.push_back(_interface->getPosXQuina(t,id,1));
            data_line_input.push_back(_interface->getPosXQuina(t,id,2));
            data_line_input.push_back(_interface->getPosXQuina(t,id,3));
            data_line_input.push_back(_interface->getPosY(t,id));
            data_line_input.push_back(_interface->getPosYQuina(t,id,0));
            data_line_input.push_back(_interface->getPosYQuina(t,id,1));
            data_line_input.push_back(_interface->getPosYQuina(t,id,2));
            data_line_input.push_back(_interface->getPosYQuina(t,id,3));
            data_line_input.push_back(_interface->getVelX(t,id));
            data_line_input.push_back(_interface->getVelY(t,id));
            data_line_input.push_back(_interface->getVelAng(t,id));
            data_line_input.push_back(_interface->getVel(t,id));
        }
    } 
    data_line_input.push_back(_interface->getPosBolaX());
    data_line_input.push_back(_interface->getPosBolaY());
    data_line_input.push_back(_interface->getVelBolaX());
    data_line_input.push_back(_interface->getVelBolaY());


    data_line_output.push_back(_interface->getVel(0,0));
    data_line_output.push_back(_interface->getVelAng(0,0));
    data_line_output.push_back(_interface->getVel(0,1));
    data_line_output.push_back(_interface->getVelAng(0,1));
    data_line_output.push_back(_interface->getVel(0,2));
    data_line_output.push_back(_interface->getVelAng(0,2));

    // junta os data_lines
    data_all_input.push_back(data_line_input);
    data_line_input.clear();
    data_all_output.push_back(data_line_output);
    data_line_output.clear();

    if(*_tempo > total_save_time){
        Csv::save_data(data_all_input, "data/save_game/input.csv", ',');
        Csv::save_data(data_all_output, "data/save_game/output.csv", ',');

        _timer->stop();
        clear_all_pointers();
    }
}

void GamePlay::clear_all_pointers(){
    if(_robo != nullptr){
        delete[] _robo;
        _robo = nullptr;
    }

    if(_bola != nullptr){
        delete _bola;
        _bola = nullptr;
    }

    if(_referee != nullptr){
        delete _referee;
        _referee = nullptr;
    }

    if(_interface != nullptr){
        delete _interface;
        _interface = nullptr;
    }

    if(_fisica != nullptr){
        delete _fisica;
        _fisica = nullptr;
    }

    if(_tempo != nullptr){
        delete _tempo;
        _tempo = nullptr;
    }

    if(_grafico != nullptr){
        delete _grafico;
        _grafico = nullptr;
    }

    if(_timer != nullptr){
        delete _timer;
        _timer = nullptr;
    }

    if(_feedforward != nullptr){
        delete _feedforward;
        _feedforward = nullptr;
    }

    if(_neural_network_a != nullptr){
        delete _neural_network_a;
        _neural_network_a = nullptr;
    }

    if(_neural_network_b != nullptr){
        delete _neural_network_b;
        _neural_network_b = nullptr;
    }
}
