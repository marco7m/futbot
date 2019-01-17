// Esse headcontroller faz o jogador jogar com outros robos parados

#ifndef ONEPLAYERALONE_H
#define ONEPLAYERALONE_H

#include <QPointF>
#include <QObject>
#include <vector>
#include "../wrsim/src/WRSim/grafico/grafico.h"
#include "../wrsim/src/WRSim/fisica.h"
#include "../wrsim/src/WRSim/objetos/bola.h"
#include "../wrsim/src/WRSim/objetos/robovss.h"

class OnePlayerAlone: public QObject{
Q_OBJECT
public:
    OnePlayerAlone();
    ~OnePlayerAlone();

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
    unsigned long long *_tempo; // dois tempos de 10 minutos ou dois tempo de 600000000 microsegundos
};

#endif
