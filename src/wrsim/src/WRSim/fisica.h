#ifndef FISICA_H
#define FISICA_H

#include <QPointF>
#include <QLineF>
#include <cmath>

#include "objetos/bola.h"
#include "objetos/robovss.h"
#include "cte.h"
#include "objetos/probe.h"

#include <QDebug>

class fisica{

public:
    fisica(robovss *r, unsigned long long *t, bola *b, probe *p = 0);
    fisica();
    void roda();

    void colocaProbe(QPointF qpoint, int np);

    bool estaDentro(QPointF quadrado[4], QPointF ponto);
    bool JRS(QLineF linha, QPointF ponto);
private:
    robovss *robo;
    bola *_bola;
    probe *_probe;

    unsigned long long *tempo;
    unsigned long long tempoAnterior;

    //funções
    QPointF getQuinas(int rob, int l);
    QPointF getQuinas(robovss rob, int l);
    double deltaT();
    double dist(double x1,double y1,double x2,double y2);
    double dist(QPointF p1, QPointF p2);
    double produtoEscalar(QLineF A, QLineF v);
    int lineSide(QLineF linha, QPointF ponto);

    //var temp para testar colisão antes de mover o robo
    double tempAng;
    double tempX;
    double tempY;
    robovss tempRobo;

    //var temp para encontrar ponto de colisão do robo e a velocidade do pondo de colisão no robô
    QPointF tQuinRobTemp[4];
    QPointF tQuinRobN[4];
    QPointF tQuinRob[4];
    QPointF tempQuinas[4];
    QLineF tempLados[4];
    QLineF tempRetaEntreCentros;
    QLineF tempReta; // usei duas vezes, pode ser fonte de bug, mas vamos ver neh, na segunda vez é uma reta paralela ao lado q bateu, olha o código
    QPointF *interseccao; // só eh utilizado pela lógica na segunda vez q aparece no código
    int ladoColidido;
    int quinaColidida;
    double velLin;
    QLineF raioChute;
    QLineF velChute;
    QLineF velPtoColisao;

    //var temp para econtrar a velocidade resultante da bola
    QLineF vetDiretor;
    QLineF projVelPtoColisao;
    QLineF projVelBola;
    bool colisao;
    bool flagColisao5;
    QPointF tempPoint;
    QLineF velResBola;
    QLineF velRelativa;
    QPointF *intersecVel;
    QLineF tempVelRelativa;
    QLineF temp2VelRelativa;

    //var temp de colisão nas quinas
    double vx;
};

#endif // FISICA_H
