#ifndef MOVEROBOTS_H
#define MOVEROBOTS_H

#include "src/wrsim/src/WRSim/interface.h"

class MoveRobots{
public:
    static void default_position(Interface i);
    static void hide_all_but_one(Interface i);
    static void hide_robot(Interface i,uint8_t team, uint8_t id);
        



};

#endif
