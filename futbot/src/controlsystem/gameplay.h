#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "wrsim/src/WRSim/objetos/robovss.h"
#include "wrsim/src/WRSim/objetos/bola.h"
#include "wrsim/src/WRSim/fisica.h"
#include "wrsim/src/WRSim/grafico/grafico.h"
#include "controlsystem/referee.h"
#include "neuralnetwork/neuralnetwork.h"

#include <QObject>
#include <QTimer>
#include <QTimer>
#include <vector>

class GamePlay: public QObject{
Q_OBJECT
public:
    GamePlay();
    ~GamePlay();

    void fast_mode(std::vector<std::vector<double> > team_a, std::vector<std::vector<double> > team_b, double play_time);
    void watch_mode(std::vector<std::vector<double> > team_a, std::vector<std::vector<double> > team_b);
    void manual_mode();
    void save_manual_mode(double total_save_time);

public slots:
    void slot_watch_mode();
    void slot_manual_mode();
    void slot_save_manual_mode();

private:
    robovss* _robo = nullptr;
    bola* _bola = nullptr;
    unsigned long long* _tempo = nullptr;
    Referee* _referee = nullptr;
    Interface* _interface = nullptr;
    fisica* _fisica = nullptr;
    grafico* _grafico = nullptr;
    QTimer* _timer = nullptr;

    NeuralNetwork* _neural_network_a = nullptr;
    NeuralNetwork* _neural_network_b = nullptr;

    //save_manual_mode variables
    unsigned long long total_save_time;
    std::vector<std::vector<double> > data_all_input;
    std::vector<std::vector<double> > data_all_output;

    void clear_all_pointers();



};

#endif
