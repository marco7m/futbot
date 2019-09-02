//  ********************************************
//  ESTE ARQUIVO NÃO ESTÁ NO FUTBOT.PRO         *
//  MANTIVE ELE AQUI PARA FUTURA IMPLEMENTAÇÃO *
//  ********************************************

#include <math.h>
#include "gsconnect.h"
#include "interface.h"

gsconnect::gsconnect(interface inter): Actuator(QString("localhost")){

Actuator::connect(QString("localhost"), 20);

/*** 'setSpeed'
          ** Description: Sets a player speed
          ** Receives:    [teamNum]   The team number
                          [playerNum] The team number
                          [x]         The x speed component
                          [y]         The y speed component
                          [theta]     The angular speed
          ** Returns:     Nothing
          ***/
Actuator::virtual void setSpeed(uint8 teamNum, uint8 playerNum, float x, float y, float theta){
    inter.setVel(teamNum, playerNum, math.sqrt(x*x + y*y);
}


Sensor sensor = new Sensor();

/*** 'connect' function
          ** Description: Connects to the server
          ** Receives:    [address] The server address
                          [port]    The server port
          ** Returns:     'true' if the connection was established, 'false' otherwise
          ***/
        bool connect(const QString& address, uint16 port);

/*** Teams handling functions
          ** Description: Handles the teams
          ** Receives:    [teamNum]  The team number
                          [teamName] The team name
          ** Returns:     Nothing
          ***/
        void addTeam(uint8 teamNum, const QString& teamName);
        void delTeam(uint8 teamNum);

/*** Balls handling functions
          ** Description: Handles the balls
          ** Receives:    [ballNum] The ball number
          ** Returns:     Nothing
          ***/
        void addBall(uint8 ballNum);
        void delBall(uint8 ballNum);

        /*** 'setBallPosition' function
          ** Description: Sets the ball position
          ** Receives:    [ballNum]  The ball number
                          [position] The ball position
          ** Returns:     Nothing
          ***/
        void setBallPosition(uint8 ballNum, const Position& position);

        /*** 'setBallVelocity' function
          ** Description: Sets the ball velocity
          ** Receives:    [ballNum]  The ball number
                          [velocity] The ball velocity
          ** Returns:     Nothing
          ***/
        void setBallVelocity(uint8 ballNum, const Velocity& velocity);

/*** Players handling functions
          ** Description: Handles the teams players
          ** Receives:    [teamNum]   The team number
                          [playerNum] The player number
          ** Returns:     Nothing
          ***/
        void addPlayer(uint8 teamNum, uint8 playerNum);
        void delPlayer(uint8 teamNum, uint8 playerNum);

        /*** 'setPlayerPosition' function
          ** Description: Sets the player position
          ** Receives:    [teamNum]   The team number
                          [playerNum] The player number
                          [position]  The player position
          ** Returns:     Nothing
          ***/
        void setPlayerPosition(uint8 teamNum, uint8 playerNum, const Position& position);

        /*** 'setPlayerOrientation' function
          ** Description: Sets the player orientation
          ** Receives:    [teamNum]     The team number
                          [playerNum]   The player number
                          [orientation] The player orientation
          ** Returns:     Nothing
          ***/
        void setPlayerOrientation(uint8 teamNum, uint8 playerNum, const Angle& orientation);

        /*** 'setPlayerVelocity' function
          ** Description: Sets the player velocity
          ** Receives:    [teamNum]   The team number
                          [playerNum] The player number
                          [velocity]  The player velocity
          ** Returns:     Nothing
          ***/
        void setPlayerVelocity(uint8 teamNum, uint8 playerNum, const Velocity& velocity);

        /*** 'setPlayerAngularSpeed' function
          ** Description: Sets the player angular speed
          ** Receives:    [teamNum]      The team number
                          [playerNum]    The player number
                          [angularSpeed] The player angular speed
          ** Returns:     Nothing
          ***/
        void setPlayerAngularSpeed(uint8 teamNum, uint8 playerNum, const AngularSpeed& angularSpeed);

/*** Field handling functions
          ** Description: Handles field info
          ***/
        void setFieldTopRightCorner(const Position& position);
        void setFieldTopLeftCorner(const Position& position);
        void setFieldBottomLeftCorner(const Position& position);
        void setFieldBottomRightCorner(const Position& position);
        void setFieldCenter(const Position& position);

        void setLeftGoalPosts(const Position& leftPost, const Position& rightPost);
        void setRightGoalPosts(const Position& leftPost, const Position& rightPost);

        void setGoalArea(float length, float width, float roundedRadius);
        void setGoalDepth(float depth);

        void setLeftPenaltyMark(const Position& position);
        void setRightPenaltyMark(const Position& position);

        void setFieldCenterRadius(float centerRadius);




} 


