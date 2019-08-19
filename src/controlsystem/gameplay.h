#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "src/wrsim/src/WRSim/objetos/robovss.h"
#include "src/wrsim/src/WRSim/objetos/bola.h"
#include "src/wrsim/src/WRSim/fisica.h"
#include "src/wrsim/src/WRSim/grafico/grafico.h"
#include "src/controlsystem/referee.h"
#include "src/neuralnetwork/neuralnetwork.h"
#include "src/controlsystem/moverobots.h"
#include "src/controlsystem/feedforward.h"
#include "src/wrsim/src/WRSim/interface.h"
#include "src/utils/csv.h"

#include <iostream>
#include <QObject>
#include <QTimer>
#include <vector>
#include <string>

class GamePlay: public QObject{
Q_OBJECT
public:
    GamePlay();
    ~GamePlay();

    void get_fit_move_point(NeuralNetwork* _neural_network_a, NeuralNetwork* _neural_network_b, double play_time);
    void fast_mode(std::vector<std::vector<double> > team_a, std::vector<std::vector<double> > team_b, double play_time);
    void watch_mode(std::vector<std::vector<double> > team_a, std::vector<std::vector<double> > team_b);
    void manual_mode(bool save_game_preview = false);
    void save_manual_mode(double total_save_time);
    void play_saved_game();

public slots:
    void slot_watch_mode();
    void slot_manual_mode();
    void slot_save_manual_mode();
    void slot_play_saved_game();

private:
    robovss* _robo = nullptr;
    bola* _bola = nullptr;
    unsigned long long* _tempo = nullptr;
    Referee* _referee = nullptr;
    Interface* _interface = nullptr;
    fisica* _fisica = nullptr;
    grafico* _grafico = nullptr;
    QTimer* _timer = nullptr;
    FeedForward* _feedforward = nullptr;

    NeuralNetwork* _neural_network_a = nullptr;
    NeuralNetwork* _neural_network_b = nullptr;

    //save_manual_mode variables
    unsigned long long total_save_time;
    std::vector<std::vector<double> > data_all_input;
    std::vector<std::vector<double> > data_all_output;

    //play_saved_game variables
    std::vector<std::vector<double> > loaded_game;
    void clear_all_pointers();



};

#endif
