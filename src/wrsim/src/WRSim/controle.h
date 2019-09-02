#ifndef CONTROLE_H
#define CONTROLE_H

#include <QObject>
#include "grafico/grafico.h"
#include "fisica.h"
#include "objetos/bola.h"
#include "objetos/robovss.h"
#include "interface.h"


class Controle: public QObject{
Q_OBJECT
public:
    Controle();

public slots:
    void mostra();

private:
    grafico *_grafico;
    fisica *_fisica;
    Interface *_interface;

    // VIAS
    robovss *robo;
    bola *_bola;
    probe *_probe;
    unsigned long long *tempo; // dois tempos de 10 minutos ou dois tempo de 600000000 microsegundos
};

#endif // CONTROLE_H
