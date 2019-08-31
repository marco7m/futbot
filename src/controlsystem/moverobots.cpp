#include "moverobots.h"

void MoveRobots::hide_all_but_one(Interface interface){
    
    // posiciona os robôs
    interface.setPosX(0,0,0.25);
    interface.setPosY(0,0,0.5);
    interface.setAng(0,0,0.25);
    interface.setVel(0,0,0.5);
    interface.setVelAng(0,0,0.5);

    interface.setPosX(0,1,0.0);
    interface.setPosY(0,1,0.0);
    interface.setAng(0,1,0.0);
    interface.setVel(0,1,0.5);
    interface.setVelAng(0,1,0.5);

    interface.setPosX(0,2,0.0);
    interface.setPosY(0,2,0.0);
    interface.setAng(0,2,0.0);
    interface.setVel(0,2,0.5);
    interface.setVelAng(0,2,0.5);

    interface.setPosX(1,0,0.0);
    interface.setPosY(1,0,0.0);
    interface.setAng(1,0,0.0);
    interface.setVel(1,0,0.5);
    interface.setVelAng(1,0,0.5);

    interface.setPosX(1,1,0.0);
    interface.setPosY(1,1,0.0);
    interface.setAng(1,1,0.0);
    interface.setVel(1,1,0.0);
    interface.setVelAng(1,1,0.5);

    interface.setPosX(1,2,0.0);
    interface.setPosY(1,2,0.0);
    interface.setAng(1,2,0.0);
    interface.setVel(1,2,0.5);
    interface.setVelAng(1,2,0.5);

    // posiciona a bola
    interface.setPosBolaX(0.0);
    interface.setPosBolaY(0.0);
    interface.setVelBolaX(0.5);
    interface.setVelBolaY(0.5);

}

void MoveRobots::hide_robot(Interface interface, uint8_t team, uint8_t id){
    interface.setPosX(team,id,0.0);
    interface.setPosY(team,id,0.0);
    interface.setAng(team,id,0.0);
    interface.setVel(team,id,0.5);
    interface.setVelAng(team,id,0.5);
}

void MoveRobots::default_position(Interface interface){
    
    // posiciona os robôs
    interface.setPosX(0,0,0.25);
    interface.setPosY(0,0,0.5);
    interface.setAng(0,0,0.25);
    interface.setVel(0,0,0.5);
    interface.setVelAng(0,0,0.5);

    interface.setPosX(0,1,0.25);
    interface.setPosY(0,1,0.25);
    interface.setAng(0,1,0.25);
    interface.setVel(0,1,0.5);
    interface.setVelAng(0,1,0.5);

    interface.setPosX(0,2,0.25);
    interface.setPosY(0,2,0.75);
    interface.setAng(0,2,0.25);
    interface.setVel(0,2,0.5);
    interface.setVelAng(0,2,0.5);

    interface.setPosX(1,0,0.75);
    interface.setPosY(1,0,0.5);
    interface.setAng(1,0,0.75);
    interface.setVel(1,0,0.5);
    interface.setVelAng(1,0,0.5);

    interface.setPosX(1,1,0.75);
    interface.setPosY(1,1,0.25);
    interface.setAng(1,1,0.75);
    interface.setVel(1,1,0.5);
    interface.setVelAng(1,1,0.5);

    interface.setPosX(1,2,0.75);
    interface.setPosY(1,2,0.75);
    interface.setAng(1,2,0.75);
    interface.setVel(1,2,0.5);
    interface.setVelAng(1,2,0.5);

    // posiciona a bola
    interface.setPosBolaX(0.5);
    interface.setPosBolaY(0.5);
    interface.setVelBolaX(0.5);
    interface.setVelBolaY(0.5);
}
