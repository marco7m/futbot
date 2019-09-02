#ifndef GRAFICOENTRADA_H
#define GRAFICOENTRADA_H

#include <QGraphicsPixmapItem>
#include "../objetos/robovss.h"
#include "../objetos/bola.h"
#include "../interface.h"
#include "src/controlsystem/moverobots.h"

class graficoentrada: public QGraphicsPixmapItem{
public:
    graficoentrada(Interface interface);
//    graficoentrada(bola *b, robovss *r, QGraphicsItem *parent = 0); 
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

private:
    robovss *robo;
    bola *_bola;
    Interface interface;
    int team_control;
    int id_control;
    bool mirror;
};
#endif // GRAFICOENTRADA_H
