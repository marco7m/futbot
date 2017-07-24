#include "gamewatch.h"

GameWatch::GameWatch(){
    has_ai = false;
    has_timer = false;
    has_grafico = false;

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
    interface.setPosX(0,0,0.75);
    interface.setPosY(0,0,0.5);
    interface.setAng(0,0,0.75);

    interface.setPosX(0,1,0.75);
    interface.setPosY(0,1,0.25);
    interface.setAng(0,1,0.75);

    interface.setPosX(0,2,0.75);
    interface.setPosY(0,2,0.75);
    interface.setAng(0,2,0.75);

    interface.setPosX(1,0,0.25);
    interface.setPosY(1,0,0.5);
    interface.setAng(1,0,0.25);

    interface.setPosX(1,1,0.25);
    interface.setPosY(1,1,0.25);
    interface.setAng(1,1,0.25);

    interface.setPosX(1,2,0.25);
    interface.setPosY(1,2,0.75);
    interface.setAng(1,2,0.25);


    // posiciona a bola
    interface.setPosBolaX(0.5);
    interface.setPosBolaY(0.5);

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

        input.ptr[i] = interface.getPosBolaX();
                i++;
        input.ptr[i] = interface.getPosBolaY();
                i++;
        input.ptr[i] = interface.getVelBolaX();
                i++;
        input.ptr[i] = interface.getVelBolaY();

        i = 0;

        // calcula a saida da rede neural a partir das entradas
        neural_network.DoTheJobOnce();
        
        // Saida de dados
        interface.setVel(0,0,output.ptr[0]);
        interface.setVelAng(0,0,output.ptr[1]);
    }

//        std::cout << *_tempo << std::endl;
}

double GameWatch::run_and_get_fitness(){
    has_ai = true;

//    initial_condition();
    while(true){
        mostra();
        if(*_tempo > 20000){
            std::cout << "\nend game" << std::endl;
            return 42;
        }
    }
}

void GameWatch::watch_game(){
    has_ai = true;

    _grafico = new grafico(_robo, _bola, _probe, interface);
    has_grafico = true;
   
    _timer = new QTimer();
    has_timer = true;
    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(mostra()));
    _timer->start(10);
}

void GameWatch::manual_mode(){
    has_ai = false;

    _grafico = new grafico(_robo, _bola, _probe, interface);
    has_grafico = true;
   
    _timer = new QTimer();
    has_timer = true;
    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(mostra()));
    _timer->start(10);
}

//void GameWatch::manual_save_game(){
//    has_ai = false;
//
//    _grafico = new grafico(_robo, _bola, _probe, interface);
//    has_grafico = true;
//   
//    _timer = new QTimer();
//    has_timer = true;
//    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(mostra()));
//    _timer->start(10);
//   
//    std::vector<std::vector<double> > input_data;
//    std::vector<std::vector<double> > output_data;
//
//    // entrada
//    std::vector<double> posx_centro;
//    std::vector<double> posx_0;
//    std::vector<double> posx_1;
//    std::vector<double> posx_2;
//    std::vector<double> posx_3;
//    std::vector<double> posy_centro;
//    std::vector<double> posy_0;
//    std::vector<double> posy_1;
//    std::vector<double> posy_2;
//    std::vector<double> posy_3;
//    std::vector<double> velx;
//    std::vector<double> vely;
//
//    // saida
//    std::vector<double> vel;
//    std::vector<double> velang;
//
//}
