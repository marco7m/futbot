#include "recordgame.h"
#include <QTimer>
//#include "../wrsim/src/WRSim/cte.h"
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "../utils/csv.h"

RecordGame::RecordGame(){

    // inicialização dos ponteiros das vias
    _robo = new robovss[robovss::nRobos];
    _bola = new bola();
    _probe = new probe[cte::nProbes];
    
    _tempo = new unsigned long long;

    // cria fisica
    _fisica = new fisica(_robo, _tempo, _bola, _probe);

    // inicia módulo gráfico
    _grafico = new grafico(_robo, _bola, _probe);

    // configurações pré inicio de partida

    // posiciona os robôs
    _robo[0].setX(1300);
    _robo[0].setY(650);
    
    _robo[1].setX(400);
    _robo[1].setY(650);


    // posiciona a bola
    _bola->setX(850);
    _bola->setY(650);

    // tempo de gravação em milisegundos
    recording_time = 300000;

    *_tempo = 0;
    
    _timer = new QTimer();
    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(mostra()));
    _timer->start(10);
}

RecordGame::~RecordGame(){
    delete[] _robo;
    delete[] _probe;
    delete _bola;
    delete _tempo;
    delete _fisica;
    delete _grafico;
    delete _timer;
}

void RecordGame::mostra(){
    if(*_tempo < recording_time){
        file_saved = false;

        _fisica->roda();
        *_tempo = *_tempo+10;
        _grafico->roda();
        
        // grava dados em memória volátil
        //
        // jogador lado esquerdo
        l_pos_center_x.push_back(_robo[1].getX());
        l_pos_center_y.push_back(_robo[1].getY());
        l_pos_0_x.push_back(getQuinas(_robo[1], 0).x());
        l_pos_0_y.push_back(getQuinas(_robo[1], 0).y());
        l_pos_1_x.push_back(getQuinas(_robo[1], 1).x());
        l_pos_1_y.push_back(getQuinas(_robo[1], 1).y());
        l_pos_2_x.push_back(getQuinas(_robo[1], 2).x());
        l_pos_2_y.push_back(getQuinas(_robo[1], 2).y());
        l_pos_3_x.push_back(getQuinas(_robo[1], 3).x());
        l_pos_3_y.push_back(getQuinas(_robo[1], 3).y());
        l_vel.push_back(_robo[1].getVel());
        l_vel_rot.push_back(_robo[1].getVelAng());
    
        
        // jogador lado direito
        r_pos_center_x.push_back(_robo[0].getX());
        r_pos_center_y.push_back(_robo[0].getY());
        r_pos_0_x.push_back(getQuinas(_robo[0], 0).x());
        r_pos_0_y.push_back(getQuinas(_robo[0], 0).y());
        r_pos_1_x.push_back(getQuinas(_robo[0], 1).x());
        r_pos_1_y.push_back(getQuinas(_robo[0], 1).y());
        r_pos_2_x.push_back(getQuinas(_robo[0], 2).x());
        r_pos_2_y.push_back(getQuinas(_robo[0], 2).y());
        r_pos_3_x.push_back(getQuinas(_robo[0], 3).x());
        r_pos_3_y.push_back(getQuinas(_robo[0], 3).y());
        r_vel.push_back(_robo[0].getVel());
        r_vel_rot.push_back(_robo[0].getVelAng());
    
    
        // bola
        b_pos_x.push_back(_bola->getX());
        b_pos_y.push_back(_bola->getY());
        b_vel_x.push_back(_bola->getVelX());
        b_vel_y.push_back(_bola->getVelY());

       
    }
    else if(!file_saved){

    file_saved = true; 

    // salvar no arquivo

    // INPUT
    // jogador lado esquerdo
    data_input_double.push_back(l_pos_center_x);
    data_input_double.push_back(l_pos_center_y);
    data_input_double.push_back(l_pos_0_x);
    data_input_double.push_back(l_pos_0_y);
    data_input_double.push_back(l_pos_1_x);
    data_input_double.push_back(l_pos_1_y);
    data_input_double.push_back(l_pos_2_x);
    data_input_double.push_back(l_pos_2_y);
    data_input_double.push_back(l_pos_3_x);
    data_input_double.push_back(l_pos_3_y);
    data_input_double.push_back(l_vel);
    data_input_double.push_back(l_vel_rot);
    
    // jogador lado direito
    data_input_double.push_back(r_pos_center_x);
    data_input_double.push_back(r_pos_center_y);
    data_input_double.push_back(r_pos_0_x);
    data_input_double.push_back(r_pos_0_y);
    data_input_double.push_back(r_pos_1_x);
    data_input_double.push_back(r_pos_1_y);
    data_input_double.push_back(r_pos_2_x);
    data_input_double.push_back(r_pos_2_y);
    data_input_double.push_back(r_pos_3_x);
    data_input_double.push_back(r_pos_3_y);

    // bola
    data_input_double.push_back(b_pos_x);
    data_input_double.push_back(b_pos_y);
    data_input_double.push_back(b_vel_x);
    data_input_double.push_back(b_vel_y);
    

    // OUTPUT   
    data_output_double.push_back(r_vel);
    data_output_double.push_back(r_vel_rot);

//    // passar o tipo de double para string
//    std::vector<std::vector<std::string> > data_input_string;
//    std::vector<std::vector<std::string> > data_output_string;
//
//    for(int i = 0; i < (int)data_input_double.size(); i++){
//        for(int j = 0; j < (int)data_input_double[i].size(); j++){
//            data_input_string.push_back(
//            
//            
//        }
//    }


    // gerar arquivos csv
    Csv::SaveData(data_input_double, "data/recordgame/000_data_input.csv", ',');
    Csv::SaveData(data_output_double, "data/recordgame/000_data_output.csv", ',');
    }
}


QPointF RecordGame::getQuinas(robovss rob, int l){ // 0 - top dir; 1 - bai dir; 2 - bai esq; 3 - top esq
    QPointF quina;
    if(l == 0){
        quina.setY(rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() + 45))));
        quina.setX(rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() + 45))));
    }
    if(l == 1){
        quina.setY(rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() + 135))));
        quina.setX(rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() + 135))));
    }
    if(l == 2){
        quina.setY(rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() + 225))));
        quina.setX(rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() + 225))));
    }
    if(l == 3){
        quina.setY(rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() - 45))));
        quina.setX(rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() - 45))));
    }
    return quina;
}
