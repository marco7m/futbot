
#ifndef INTERFACE_H
#define INTERFACE_H

#include "objetos/robovss.h"
#include "objetos/bola.h"

class Interface{
public:
    Interface(robovss *r, bola *b);
    Interface();

    double getPosX(quint8 time, quint8 idRobo);
    void setPosX(quint8 time, quint8 idRobo, double posx);
    double getPosY(quint8 time, quint8 idRobo);
    void setPosY(quint8 time, quint8 idRobo, double posy);
    double getAng(quint8 time, quint8 idRobo);
    void setAng(quint8 time, quint8 idRobo, double ang);
    double getVel(quint8 time, quint8 idRobo);
    void setVel(quint8 time, quint8 idRobo, double vel);
    double getVelX(quint8 time, quint8 idRobo);
    double getVelY(quint8 time, quint8 idRobo);
    double getVelAng(quint8 time, quint8 idRobo);
    void setVelAng(quint8 time, quint8 idRobo, double velAng);
    double getPosBolaX();
    void setPosBolaX(double posbx);
    double getPosBolaY();
    void setPosBolaY(double posby);
    double getVelBolaX();
    void setVelBolaX(double velbx);
    double getVelBolaY();
    void setVelBolaY(double velby);
    double getPosXQuina(quint8 time, quint8 idRobo, int quina);
    double getPosYQuina(quint8 time, quint8 idRobo, int quina);


private:
    robovss *_robo;
    bola *_bola;
    int encontraRobo(quint8 time, quint8 idRobo);
    double normaliza(double max, double min, double atual);
    double desnormaliza(double max, double min, double val_normalizado);
    double getQuinaX(robovss rob, int l);
    double getQuinaY(robovss rob, int l);

    // Seto aqui os parâmetros de contorno do robô real, unidades:
    static constexpr double MAX_VEL_ROBO = 1;      // [mm]/[ms]
    static constexpr double MIN_VEL_ROBO = -1;     // [mm]/[ms]
    static constexpr double MAX_VEL_BOLA = 3;      // [mm]/[ms]
    static constexpr double MIN_VEL_BOLA = -3;      // [mm]/[ms]
    static constexpr double MAX_VEL_ANG_ROBO = 1;
    static constexpr double MIN_VEL_ANG_ROBO = -1; 
    static constexpr double MAX_POS_X = 1700;          // maior X possível
    static constexpr double MIN_POS_X = 0;             // menor X possível
    static constexpr double MAX_POS_Y = 1325;          // maior Y possível
    static constexpr double MIN_POS_Y = 25;            // menor Y possível
    static constexpr double MIN_ANG = 0;                // [graus] angulo 0 -> robo para cima; angulo aumenta no sentido horário
    static constexpr double MAX_ANG = 360;

}; 
#endif
