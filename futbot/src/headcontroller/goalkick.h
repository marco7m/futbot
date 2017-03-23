// Esse headcontroller faz o jogador poder jogar contra uma IA

#ifndef GOALKICK_H
#define GOALKICK_H

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

class GoalKick: public QObject{
Q_OBJECT
public:
    GoalKick();
    ~GoalKick();

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
    unsigned long long *_tempo; // dois tempos de 10 minutos ou dois tempo de 600000000 microsegundos

    // ponteiros de entrada e saida da rede neural
    double_ptr input = double_ptr(26);
    double_ptr output{2};

    NeuralNetwork neural_network{input, output, "nn0001.csv"};
    
    QPointF getQuinas(robovss rob, int l);
};

#endif

