#ifndef RECORDGAME_H
#define RECORDGAME_H

#include <QPointF>
#include <QObject>
#include <vector>
#include "../wrsim/src/WRSim/grafico/grafico.h"
#include "../wrsim/src/WRSim/fisica.h"
#include "../wrsim/src/WRSim/objetos/bola.h"
#include "../wrsim/src/WRSim/objetos/robovss.h"
#include <iostream>
#include <fstream>

class RecordGame: public QObject{
Q_OBJECT
public:
    RecordGame();
    ~RecordGame();

public slots:
    void mostra();

private:
    grafico *_grafico;
    fisica *_fisica;
    QTimer * _timer;
    // VIAS
    robovss *_robo;
    bola *_bola;
    probe *_probe;
    unsigned long long *_tempo; // dois tempos de 10 minutos ou dois tempo de 600000000 microsegundos

    // VARIÁVEIS PARA SALVAR OS DADOS
    std::ofstream file;
    
    // jogador lado esquerdo
    std::vector<double> l_pos_center_x;
    std::vector<double> l_pos_center_y;

    std::vector<double> l_pos_0_x;
    std::vector<double> l_pos_0_y;
    
    std::vector<double> l_pos_1_x;
    std::vector<double> l_pos_1_y;

    std::vector<double> l_pos_2_x;
    std::vector<double> l_pos_2_y;

    std::vector<double> l_pos_3_x;
    std::vector<double> l_pos_3_y;

    std::vector<double> l_vel;

    std::vector<double> l_vel_rot;

    
    // jogador lado direito
    std::vector<double> r_pos_center_x;
    std::vector<double> r_pos_center_y;

    std::vector<double> r_pos_0_x;
    std::vector<double> r_pos_0_y;
    
    std::vector<double> r_pos_1_x;
    std::vector<double> r_pos_1_y;

    std::vector<double> r_pos_2_x;
    std::vector<double> r_pos_2_y;

    std::vector<double> r_pos_3_x;
    std::vector<double> r_pos_3_y;

    std::vector<double> r_vel;

    std::vector<double> r_vel_rot;


    // bola
    std::vector<double> b_pos_x;
    std::vector<double> b_pos_y;
    
    std::vector<double> b_vel_x;
    std::vector<double> b_vel_y;

 

    QPointF getQuinas(robovss rob, int l);
};

#endif
