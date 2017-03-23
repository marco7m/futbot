#ifndef CONTROLE_H
#define CONTROLE_H

#include <QObject>
#include "grafico/grafico.h"
#include "fisica.h"
#include "objetos/bola.h"
#include "objetos/robovss.h"
#include "interface.h"


class ControleWRSim: public QObject{
Q_OBJECT
public:
    ControleWRSim();
    ~ControleWRSim();

public slots:
    void mostra();

private:
    grafico *_grafico;
    fisica *_fisica;
    interface *_interface;
    
    // timer
    QTimer *_timer;

    // VIAS
    robovss *_robo;
    bola *_bola;
    probe *_probe;
    unsigned long long *_tempo; // dois _tempos de 10 minutos ou dois _tempo de 600000000 microsegundos
};

#endif // CONTROLE_H
