// Esse headcontroller faz o jogador poder jogar contra uma IA

#ifndef SIMPLEIA_H
#define SIMPLEIA_H

#include <QPointF>
#include <QObject>
#include <vector>
#include "../wrsim/src/WRSim/grafico/grafico.h"
#include "../wrsim/src/WRSim/fisica.h"
#include "../wrsim/src/WRSim/objetos/bola.h"
#include "../wrsim/src/WRSim/objetos/robovss.h"
#include "../utils/my_ptr.h"
#include "../neuralnetwork/neuralnetwork.h"
#include <iostream>
#include "../wrsim/src/WRSim/interface.h"

class SimpleIa: public QObject{
Q_OBJECT
public:
    SimpleIa();
    ~SimpleIa();

public slots:
    void mostra();

private:
    grafico *_grafico;
    fisica *_fisica;
    QTimer *_timer;
    // VIAS
    robovss *_robo;
    bola *_bola;
    probe *_probe;
    Interface *interface;
    unsigned long long *_tempo; // dois tempos de 10 minutos ou dois tempo de 600000000 microsegundos

    // ponteiros de entrada e saida da rede neural
    double_ptr input = double_ptr(12);
    double_ptr output{2};

    NeuralNetwork neural_network{input, output, "data/nn_save_data.csv"};
    
    // entrada
    std::vector<double> posx_centro;
    std::vector<double> posx_0;
    std::vector<double> posx_1;
    std::vector<double> posx_2;
    std::vector<double> posx_3;
    std::vector<double> posy_centro;
    std::vector<double> posy_0;
    std::vector<double> posy_1;
    std::vector<double> posy_2;
    std::vector<double> posy_3;
    std::vector<double> velx;
    std::vector<double> vely;

    // saida
    std::vector<double> vel;
    std::vector<double> velang;


};

#endif

