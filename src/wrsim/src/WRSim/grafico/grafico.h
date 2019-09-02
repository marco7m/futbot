#ifndef GRAFICO_H
#define GRAFICO_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "graficoentrada.h"
#include "graficorobovss.h"
#include "../objetos/robovss.h"
#include "graficobola.h"
#include "../objetos/bola.h"
#include "graficoprobe.h"
#include "../objetos/probe.h"
#include "graficocampovss.h"
#include "../interface.h"

class grafico: public QGraphicsView{
public:
    grafico(robovss *r, bola *b, Interface interface, probe *p = 0);
    ~grafico();
    QGraphicsScene *tela;
    graficorobovss *grobo;
    graficobola *gbola;
    graficoprobe *gprobe;
    graficoentrada *gentrada;
    graficocampovss *gcampoVss;
    
    void roda();
private:
    robovss *robo;
    bola *_bola;
    probe *_probe;
    Interface interface;
};

#endif // GRAFICO_H
