/***
 * Warthog Robotics
 * University of Sao Paulo (USP) at Sao Carlos
 * http://www.warthog.sc.usp.br/
 *
 * This file is part of WRSim project.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***/

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
    fisica(robovss *r, unsigned long long *t, bola *b, probe *p);
    void roda();

    void colocaProbe(QPointF qpoint, int np);
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
    int JRS(QLineF linha, QPointF ponto);
    int lineSide(QLineF linha, QPointF ponto);
    bool estaDentro(QPointF quadrado[4], QPointF ponto);

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
