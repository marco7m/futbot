#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QTimer>
#include <iostream>
#include "../wrsim/src/WRSim/grafico/grafico.h"
#include "../wrsim/src/WRSim/fisica.h"
#include "../wrsim/src/WRSim/objetos/bola.h"
#include "../wrsim/src/WRSim/objetos/robovss.h"
#include "../utils/my_ptr.h"
#include "../neuralnetwork/neuralnetwork.h"
#include "../wrsim/src/WRSim/interface.h"
#include "referee.h"

class Game: public QObject{
Q_OBJECT
public:
    Game();
    ~Game();
    double run_and_get_fitness();
    void watch_game();
    void manual_mode();

public slots:
    void mostra();

private:
    // flags
    bool has_graphic;
    bool has_ai;

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
    double_ptr output{2};

    NeuralNetwork neural_network{input, output, "data/nn_save_data.csv"};
};

#endif
