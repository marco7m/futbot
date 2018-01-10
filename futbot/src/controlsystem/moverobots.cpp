#include "moverobots.h"

void MoveRobots::default_position(Interface i){
    // posiciona os robôs
    i.setPosX(0,0,0.25);
    i.setPosY(0,0,0.5);
    i.setAng(0,0,0.25);
    i.setVel(0,0,0.5);
    i.setVelAng(0,0,0.5);

    i.setPosX(0,1,0.25);
    i.setPosY(0,1,0.25);
    i.setAng(0,1,0.25);
    i.setVel(0,1,0.5);
    i.setVelAng(0,1,0.5);

    i.setPosX(0,2,0.25);
    i.setPosY(0,2,0.75);
    i.setAng(0,2,0.25);
    i.setVel(0,2,0.5);
    i.setVelAng(0,2,0.5);

    i.setPosX(1,0,0.75);
    i.setPosY(1,0,0.5);
    i.setAng(1,0,0.75);
    i.setVel(1,0,0.5);
    i.setVelAng(1,0,0.5);

    i.setPosX(1,1,0.75);
    i.setPosY(1,1,0.25);
    i.setAng(1,1,0.75);
    i.setVel(1,1,0.5);
    i.setVelAng(1,1,0.5);

    i.setPosX(1,2,0.75);
    i.setPosY(1,2,0.75);
    i.setAng(1,2,0.75);
    i.setVel(1,2,0.5);
    i.setVelAng(1,2,0.5);

    // posiciona a bola
    i.setPosBolaX(0.5);
    i.setPosBolaY(0.5);
    i.setVelBolaX(0.5);
    i.setVelBolaY(0.5);
}
