#ifndef INTERFACE_H
#define INTERFACE_H

#include "objetos/robovss.h"
#include "objetos/bola.h"

// para obter os valores reais, time = 0; para obter os valores espelhados, time = 1.
class Interface{
public:
    Interface(robovss *r, bola *b);
    Interface();

    double getPosX(quint8 time, quint8 idRobo, bool espelhar = false);
    void setPosX(quint8 time, quint8 idRobo, double posx, bool espelhar = false);
    double getPosY(quint8 time, quint8 idRobo, bool espelhar = false);
    void setPosY(quint8 time, quint8 idRobo, double posy, bool espelhar = false);
    double getAng(quint8 time, quint8 idRobo);
    void setAng(quint8 time, quint8 idRobo, double ang);
    double getVel(quint8 time, quint8 idRobo, bool espelhar = false);
    void setVel(quint8 time, quint8 idRobo, double vel, bool espelhar = false);
    double getVelX(quint8 time, quint8 idRobo, bool espelhar = false);
    double getVelY(quint8 time, quint8 idRobo, bool espelhar = false);
    double getVelAng(quint8 time, quint8 idRobo, bool espelhar = false);
    void setVelAng(quint8 time, quint8 idRobo, double velAng, bool espelhar = false);
    double getPosBolaX(bool espelhar = false);
    void setPosBolaX(double posbx);
    double getPosBolaY(bool espelhar = false);
    void setPosBolaY(double posby);
    double getVelBolaX(bool espelhar = false);
    void setVelBolaX(double velbx);
    double getVelBolaY(bool espelhar = false);
    void setVelBolaY(double velby);
    double getPosXQuina(quint8 time, quint8 idRobo, int quina, bool espelhar = false);
    double getPosYQuina(quint8 time, quint8 idRobo, int quina, bool espelhar = false);

    double get_denormalized_pos_bola_x();

    // non "pure" functions
    // getDirComponent: return the component of an unitary vector pointing in the direction the robot is pointing to
    double getDirComponentX(quint8 time, quint8 idRobo, bool espelhar = false);
    double getDirComponentY(quint8 time, quint8 idRobo, bool espelhar = false);


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
