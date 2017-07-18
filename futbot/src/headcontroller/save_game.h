// Esse headcontroller faz o jogador jogar com outros robos parados

#ifndef SAVEGAME_H
#define SAVEGAME_H

#include <QPointF>
#include <QObject>
#include <vector>
#include "../wrsim/src/WRSim/grafico/grafico.h"
#include "../wrsim/src/WRSim/fisica.h"
#include "../wrsim/src/WRSim/objetos/bola.h"
#include "../wrsim/src/WRSim/objetos/robovss.h"
#include "../wrsim/src/WRSim/interface.h"


class SaveGame: public QObject{
Q_OBJECT
public:
    SaveGame();
    ~SaveGame();

public slots:
    void mostra();

private:
    grafico *_grafico;
    fisica *_fisica;
    QTimer *_timer;
    // VIAS
    robovss* _robo;
    bola *_bola;
    probe *_probe;
    Interface *interface;
    unsigned long long *_tempo; // dois tempos de 10 minutos ou dois tempo de 600000000 microsegundos

    // flag
    bool continua;

    // variaveis para armazenar os dados
    std::vector<std::vector<double> > input_data;
    std::vector<std::vector<double> > output_data;

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
