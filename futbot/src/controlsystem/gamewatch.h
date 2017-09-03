#ifndef GAMEWATCH_H
#define GAMEWATCH_H

#include <QObject>
#include <QTimer>
#include <iostream>
#include "../wrsim/src/WRSim/grafico/grafico.h"
#include "../wrsim/src/WRSim/fisica.h"
#include "../wrsim/src/WRSim/objetos/bola.h"
#include "../wrsim/src/WRSim/objetos/robovss.h"
#include "../utils/my_ptr.h"
#include "../utils/csv.h"
#include "../neuralnetwork/neuralnetwork.h"
#include "../wrsim/src/WRSim/interface.h"
#include "referee.h"
#include <string>

class GameWatch: public QObject{
Q_OBJECT
public:
    GameWatch();
    ~GameWatch();
    void watch_game(std::string ia_0, std::string ia_1);
    void manual_mode();
    void manual_save_game(int rt);

public slots:
    void mostra();
    void mostra_watch_game();

private:
    // flags
    bool has_ai;
    bool has_timer;
    bool has_grafico;
    bool record_game;

    grafico* _grafico;
    fisica* _fisica;

    robovss* _robo;
    bola *_bola;
    probe *_probe;
    Referee* _referee;
    Interface interface;

    QTimer* _timer;
    unsigned long long *_tempo; // dois tempos de 10 minutos ou dois tempo de 600000000 microsegundos

    // ponteiros de entrada e saida da rede neural
    double_ptr input = double_ptr(88);
    double_ptr output{6};
    NeuralNetwork neural_network{input, output, "data/nn0002.csv"};

    // manual_save_game variables
    std::vector<std::vector<double> > input_data;
    std::vector<std::vector<double> > output_data;
    int recording_time;

};

#endif








//    // entrada
//    std::vector<double> posx_centro_r00;
//    std::vector<double> posx_0_r00;
//    std::vector<double> posx_1_r00;
//    std::vector<double> posx_2_r00;
//    std::vector<double> posx_3_r00;
//    std::vector<double> posy_centro_r00;
//    std::vector<double> posy_0_r00;
//    std::vector<double> posy_1_r00;
//    std::vector<double> posy_2_r00;
//    std::vector<double> posy_3_r00;
//    std::vector<double> velx_r00;
//    std::vector<double> vely_r00;
//    std::vector<double> vel_ang_r00;
//    std::vector<double> vel_lin_r00;
//
//    std::vector<double> posx_centro_r01;
//    std::vector<double> posx_0_r01;
//    std::vector<double> posx_1_r01;
//    std::vector<double> posx_2_r01;
//    std::vector<double> posx_3_r01;
//    std::vector<double> posy_centro_r01;
//    std::vector<double> posy_0_r01;
//    std::vector<double> posy_1_r01;
//    std::vector<double> posy_2_r01;
//    std::vector<double> posy_3_r01;
//    std::vector<double> velx_r01;
//    std::vector<double> vely_r01;
//    std::vector<double> vel_ang_r01;
//    std::vector<double> vel_lin_r01;
//
//    std::vector<double> posx_centro_r02;
//    std::vector<double> posx_0_r02;
//    std::vector<double> posx_1_r02;
//    std::vector<double> posx_2_r02;
//    std::vector<double> posx_3_r02;
//    std::vector<double> posy_centro_r02;
//    std::vector<double> posy_0_r02;
//    std::vector<double> posy_1_r02;
//    std::vector<double> posy_2_r02;
//    std::vector<double> posy_3_r02;
//    std::vector<double> velx_r02;
//    std::vector<double> vely_r02;
//    std::vector<double> vel_ang_r02;
//    std::vector<double> vel_lin_r02;
//
//    std::vector<double> posx_centro_r10;
//    std::vector<double> posx_0_r10;
//    std::vector<double> posx_1_r10;
//    std::vector<double> posx_2_r10;
//    std::vector<double> posx_3_r10;
//    std::vector<double> posy_centro_r10;
//    std::vector<double> posy_0_r10;
//    std::vector<double> posy_1_r10;
//    std::vector<double> posy_2_r10;
//    std::vector<double> posy_3_r10;
//    std::vector<double> velx_r10;
//    std::vector<double> vely_r10;
//    std::vector<double> vel_ang_r10;
//    std::vector<double> vel_lin_r10;
//
//    std::vector<double> posx_centro_r11;
//    std::vector<double> posx_0_r11;
//    std::vector<double> posx_1_r11;
//    std::vector<double> posx_2_r11;
//    std::vector<double> posx_3_r11;
//    std::vector<double> posy_centro_r11;
//    std::vector<double> posy_0_r11;
//    std::vector<double> posy_1_r11;
//    std::vector<double> posy_2_r11;
//    std::vector<double> posy_3_r11;
//    std::vector<double> velx_r11;
//    std::vector<double> vely_r11;
//    std::vector<double> vel_ang_r11;
//    std::vector<double> vel_lin_r11;
//
//    std::vector<double> posx_centro_r12;
//    std::vector<double> posx_0_r12;
//    std::vector<double> posx_1_r12;
//    std::vector<double> posx_2_r12;
//    std::vector<double> posx_3_r12;
//    std::vector<double> posy_centro_r12;
//    std::vector<double> posy_0_r12;
//    std::vector<double> posy_1_r12;
//    std::vector<double> posy_2_r12;
//    std::vector<double> posy_3_r12;
//    std::vector<double> velx_r12;
//    std::vector<double> vely_r12;
//    std::vector<double> vel_ang_r12;
//    std::vector<double> vel_lin_r12;
//
//    std::vector<double> bola_posx;
//    std::vector<double> bola_posy;
//    std::vector<double> bola_velx;
//    std::vector<double> bola_vely;
//
//
