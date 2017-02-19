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

#include "fisica.h"

fisica::fisica(robovss *r, unsigned long long *t, bola *b, probe *p){
    robo = r;
    _bola = b;
    tempo = t;
    _probe = p;
    tempoAnterior = 0;

    // inicialização de ponteiros
    interseccao = new QPointF();
    intersecVel = new QPointF();

}

void fisica::roda(){

    // este loop vai fazer a fisica para cada robô separadamente
    for(int k = 0; k < robovss::nRobos; k++){

        // movimenta o robo ----------------------------------------------------

        // rotação
        tempAng = robo[k].getAng() + robo[k].getVelAng()*deltaT();

        // move para frente e para trás
        tempY = robo[k].getY() + cos(robo[k].getAng()*cte::PI/180)*robo[k].getVel()*deltaT();
        tempX = robo[k].getX() - sin(robo[k].getAng()*cte::PI/180)*robo[k].getVel()*deltaT();

        tempRobo = robo[k];
        tempRobo.setAng(tempAng);
        tempRobo.setX(tempX);
        tempRobo.setY(tempY);
        // checa se o robo pode se mover
        // se pode ele realmente se move


        /* COMEÇO
         * Colisao do robô com o campo
         *
         * precisa ser otimizado
         * substituir todos os getQuinas() por um ponteiro, para não ter que fazer as operações todas as vezes
         * nas laterais internas dos gols pode dar bug pois não coloquei isso:
         * && (tQuinRobTemp[i].x() - tQuinRob[i].x() < 0) && (tQuinRobTemp[i].y() - tQuinRob[i].y() < 0)
         * se der bug mesmo, arrumar isso
         */

        bool move = true;

        for(int i = 0; i < 4; i++){
            tQuinRobTemp[i] = getQuinas(tempRobo, i);
            tQuinRob[i] = getQuinas(k,i);
        }

            // faz os testes para todas as quinas dos robôs
        for(int i = 0; i < 4; i++){
             // checa se o robo bateu na parte superior do campo
            if((tQuinRobTemp[i].y() < 25) && (tQuinRob[i].y() - tQuinRobTemp[i].y() > 0)){
                move = false;
            }


             // checa se o robo bateu na parte inferior do campo
            else if((tQuinRobTemp[i].y() > 1325) && (tQuinRob[i].y() - tQuinRobTemp[i].y() < 0)){
                move = false;
            }

             // checa se o robo bateu no fundo do gol esquerdo
            else if((tQuinRobTemp[i].x() < 0) && (tQuinRob[i].x() - tQuinRobTemp[i].x() > 0)){
                move = false;
            }

            // checa se o robo bateu no fundo do gol direito
            else if((tQuinRobTemp[i].x() > 1700) && (tQuinRob[i].x() - tQuinRobTemp[i].x() < 0)){
                move = false;
            }


            //DIAGONAL
            // canto superior esquerdo
            else if(JRS(QLineF(100,100, 170, 25),QPointF(getQuinas(tempRobo,i))) <= 0){
                move = false;
            }
            // canto superior direito
            else if(JRS(QLineF(1600,100, 1530, 25),QPointF(getQuinas(tempRobo,i))) >= 0){
                move = false;
            }
            // canto inferior direito
            else if(JRS(QLineF(1600,1255, 1530, 1325),QPointF(getQuinas(tempRobo,i))) <= 0){
                move = false;
            }
            // canto inferior esquerdo
            else if(JRS(QLineF(100,1255, 170, 1325),QPointF(getQuinas(tempRobo,i))) >= 0){
                move = false;
            }

            // parede esquerda acima do gol
            else if((tQuinRobTemp[i].x() < 100) && (tQuinRobTemp[i].y() > 25) && (tQuinRobTemp[i].y() <= 475) && (tQuinRob[i].x() - tQuinRobTemp[i].x() > 0)){
                move = false;
            }
            // parede esquerda abaixo do gol
            else if((tQuinRobTemp[i].x() < 100) && (tQuinRobTemp[i].y() >= 875) && (tQuinRobTemp[i].y() < 1325) && (tQuinRob[i].x() - tQuinRobTemp[i].x() > 0)){
                move = false;
            }

            // parede direita acima do gol
            else if((tQuinRobTemp[i].x() > 1600) && (tQuinRobTemp[i].y() > 25) && (tQuinRobTemp[i].y() <= 475) && (tQuinRob[i].x() - tQuinRobTemp[i].x() < 0)){
               move = false;
            }

            // parede direita abaixo do gol
            else if((tQuinRobTemp[i].x() > 1600) && (tQuinRobTemp[i].y() >= 875) && (tQuinRobTemp[i].y() < 1325) && (tQuinRob[i].x() - tQuinRobTemp[i].x() < 0)){
               move = false;
            }

            //parte de cima gol esquerdo
            else if((tQuinRobTemp[i].y() < 475) && (tQuinRobTemp[i].x() < 100) ){
                move = false;
            }

            //parte de baixo gol esquerdo
            else if((tQuinRobTemp[i].y() > 875) && (tQuinRobTemp[i].x() < 100) ){
                move = false;
            }

            //parte de cima gol direito
            else if((tQuinRobTemp[i].y() < 475) && (tQuinRobTemp[i].x() > 1600) ){
                move = false;
            }

            //parte de baixo gol direito
            else if((tQuinRobTemp[i].y() > 875) && (tQuinRobTemp[i].x() > 1600) ){
                move = false;
            }

        }

        // colisão com as quinas dos gols

        // uso produto escalar para saber se as coordenadas da quina estão dentro do retângulo do robô ou não
        // o ponto M esta dentro do retângulo ABCD se: (0<AM⋅AB<AB⋅AB) &&(0<AM⋅AD<AD⋅AD)

        // gol esquerdo, quina superior
        if(estaDentro(tQuinRobTemp, QPointF(100,475))){
            move = false;
        }

        // gol esquerdo, quina inferior
        if(estaDentro(tQuinRobTemp, QPointF(100,875))){
            move = false;
        } 

        // gol direito, quina inferior
        if(estaDentro(tQuinRobTemp, QPointF(1600,875))){
            move = false;
        } 
       
        // gol direito, quina superior
        if(estaDentro(tQuinRobTemp, QPointF(1600,475))){
            move = false;
        }
       
        /* FIM
        * Colisão do robô com o campo
        *
        */

        /* INICIO
         * Colisão do robô com outros robôs
         *
         * Primeiro checo se há algum robô na área de perigo do robo[k], se houver eu checo se alguma das quinas do robô k e n 
         * estão dentro um do outro, se sim, eles colidiram
         */
        for(int n = 0; n < robovss::nRobos; n++){
            if(n != k){
                // checo se o robô n está na área de perigo do robô k
                if(dist(robo[k].getX(),robo[k].getY(),robo[n].getX(),robo[n].getY()) <= 2*robovss::largura/cte::raiz2){
                    qDebug() << "Área de perigo"; 
                    for(int q0 = 0; q0 < 4; q0++){
                        tQuinRobN[q0] = getQuinas(n, q0);
                    }
                    // checo se alguma das quinas do robô k está dentro do robô n
                    for(int q1 = 0; q1 < 4; q1++){
                        if(estaDentro(tQuinRobN, tQuinRobTemp[q1])){
                            move = false;
                        }
                    }
                    // checo se alguma das quinas do robô n está dentro do robô k
                    for(int q1 = 0; q1 < 4; q1++){
                        if(estaDentro(tQuinRobTemp, tQuinRobN[q1])){
                            move = false;
                        }
                    }
                }
            }
        }      

        /*
         * FIM
         * Colisão do robô com outros robôs
         *
         */

        if(move){

        // realmente move o robo
        robo[k].setAng(tempAng);
        robo[k].setX(tempX);
        robo[k].setY(tempY);

        }

        // checa se a bola está na área de perigo
        if(dist(robo[k].getX(),robo[k].getY(),_bola->getX(), _bola->getY()) < bola::raio + robovss::largura/cte::raiz2){

            // faz um jeito cabrera de descobrir em que ponto do robo a bola está encostada
            // todo o código desta parte foi feito para a colisão de uma bola com um robo

            // encontra todos as quinas do robo
            for(int i = 0; i < 4; i++){
                tempQuinas[i] = getQuinas(k, i);
            }

            // com as quinas encontra todos os lados do robo
            for(int i = 0; i < 4; i++){
                if (i != 3){
                    tempLados[i].setP1(tempQuinas[i]);
                    tempLados[i].setP2(tempQuinas[i+1]);
                }
                else{
                    tempLados[i].setP1(tempQuinas[3]);
                    tempLados[i].setP2(tempQuinas[0]);
                }
            }

            // encontro uma reta entre o centro da bola e do robo
            tempRetaEntreCentros.setP1(QPointF(_bola->getX(), _bola->getY()));
            tempRetaEntreCentros.setP2(QPointF(robo[k].getX(), robo[k].getY()));

            // encontro o lado do robo que a reta entre centros cruza
            ladoColidido = 10; //para saber quando nenhum lado colidiu, o valor vai ser 10
            for(int i = 0; i < 4; i++){
                if(tempRetaEntreCentros.intersect(tempLados[i], interseccao) == 1){
                    ladoColidido = i;
                }
            }

            // gira o lado que está mais próximo da bola em 90 graus, com o eixo em P1
            tempReta = tempLados[ladoColidido].normalVector();

            // translada a reta até que seu P1 coincida com o centro da bola
            tempReta.translate(_bola->getX() - tempReta.p1().x(), _bola->getY() - tempReta.p1().y());

            // deixa o P2 da reta para o lado do robo e não ao contrário (se P1 está mais próximo do robo q P2, length = -length)
            if(dist(tempReta.p1(), QPointF(robo[k].getX(), robo[k].getY())) <
                    dist(tempReta.p2(), QPointF(robo[k].getX(), robo[k].getY()))){
                tempReta.setLength(-tempReta.length());
            }
            // deixo a reta do tamanho do raio da bola, então checo se ela está cruzando com o robo
            // se estiver eu encontrei o ponto de colisão
            tempReta.setLength(_bola->raio);

            if(tempReta.intersect(tempLados[ladoColidido], interseccao) == 1){
                // daqui pra baixo o robo fucking bateu na bola e sei onde que ela bateu
                
                // checo se a bola colidiu com a quina do robo, se sim a velocidade do ponto de colisão é a da quina q colidiu, se não faz normal
                // CÓDIGO NÃO IMPLEMENTADO AINDA

                // fucking geometry para calcular a velocidade do ponto de colisão do robô com a bola
                raioChute.setP1(*interseccao);
                raioChute.setP2(QPointF(robo[k].getX(), robo[k].getY()));

                velLin = robo[k].getVelAng() * raioChute.length();

                // velChute é a velocidade resultante do ponto de colisão, normal ao lado do robô, considerando apenas rotação
                velChute.setP1(*interseccao);
                velChute.setLength(velLin * sin((raioChute.angleTo(tempRetaEntreCentros) - 90)*180/cte::PI));
                velChute.setAngle(tempReta.angle() + 180); // unidade [grau*mm/ms]
                velChute.setLength(velChute.length() * cte::PI/180); // unidade [mm/ms]

                // velocidade do ponto de colisão, considerando translação e rotação do robô
                velPtoColisao.setP1(*interseccao);
                velPtoColisao.setP2(QPointF(velChute.x2() + robo[k].getVelX(), velChute.y2() + robo[k].getVelY()));

                /*
                 * COMEÇO
                 * LÓGICA PARA ENCONTRAR A VELOCIDADE RESULTANTE DA BOLA
                 */

                //Tento primeiro descobrir se o robô está batendo na bola

                // encontro um vetor diretor unitário no sentido pontoDeColisão -> centro da bola
                vetDiretor.setPoints(*interseccao, QPointF(_bola->getX(), _bola->getY()));
                vetDiretor = vetDiretor.unitVector();
                // movo ele à origem
                tempPoint.setX(vetDiretor.dx());
                tempPoint.setY(vetDiretor.dy());
                vetDiretor.setP2(tempPoint);
                vetDiretor.setP1(QPointF(0,0));

                // encontro a projeção dos vetores velocidades do ponto de intersecção e da bola sobre o vetDiretor centrado na origem
                projVelPtoColisao = vetDiretor;
                projVelPtoColisao.setLength(produtoEscalar(velPtoColisao,vetDiretor));
                projVelBola = vetDiretor;
                projVelBola.setLength(produtoEscalar(QLineF(QPointF(0, 0), QPointF(_bola->getVelX(), _bola->getVelY())), vetDiretor));

                /*
             * COMEÇO
             * CONDIÇÕES PARA SABER SE A BOLA COLIDIU MESMO OU NÃO
             */

                // inicio as variaveis com false
                colisao = false;
                flagColisao5 = false;

                // se nenhum está se movendo em direção ao outro, ou se afastando, não colidiu
                if((projVelBola.length() == 0) && (projVelPtoColisao.length() == 0)){
                    colisao = false;
                }

                // se apenas um deles está se movendo em direção ao outro, ou se afastando, colidiu
                else if((projVelBola.length() == 0) || (projVelPtoColisao.length() == 0)){
                    colisao = true;
                }

                // se os dois estiverem se movendo um em direção ao outro, bateram mesmo
                else if(((vetDiretor.angleTo(projVelPtoColisao) < 90) && (vetDiretor.angleTo(projVelBola) > 90))){
                    colisao = true;
                }

                // se os dois estiverem se movendo em direções contrárias, não colidiram
                else if(((vetDiretor.angleTo(projVelPtoColisao) > 90) && (vetDiretor.angleTo(projVelBola) < 90))){
                    colisao = false;
                }

                // checo se os dois se movem na mesma direção do vetor diretor
                else if(((vetDiretor.angleTo(projVelPtoColisao) < 90) && (vetDiretor.angleTo(projVelBola) < 90))){
                    // se o robo se move mais rápido que a bola, bateu
                    if(projVelPtoColisao.length() > projVelBola.length()){
                        colisao = true;
                        flagColisao5 = true;
                    }
                    else{
                        colisao = false;
                    }
                }

                // checo se os dois se movem na direção contrária à do vetor diretor
                else if(((vetDiretor.angleTo(projVelPtoColisao) > 90) && (vetDiretor.angleTo(projVelBola) > 90))){
                    // se a bola se move mais rápido que o robo, bateu
                    if(projVelBola.length() > projVelPtoColisao.length()){
                        colisao = true;
                    }
                    else{
                        colisao = false;
                    }
                }


                /*
             * CONDIÇÕES PARA SABER SE A BOLA COLIDIU MESMO OU NÃO
             * FIM
             */


                // aqui eu realmente começo a tratar a colisão
                if(colisao){
                    // basicamente qualquer caso de colisão, menos o em que o robo e a bola se movem na mesma direção, e o robo é mais rápido
                    if(!flagColisao5){
                        // o algoritmo é o seguinte: eu pego e subtraio a vel do robo, da bola, pego essa vel resultante e coloco na bola e trato como se o robo estivesse parado

                        // velocidade da bola, tomando por referencial o ponto de colisão no robô
                        velRelativa.setP1(QPointF(0, 0));
                        velRelativa.setP2(QPointF(_bola->getVelX() - velPtoColisao.dx(), _bola->getVelY() - velPtoColisao.dy()));

                        velRelativa.translate(*interseccao);

                        velRelativa.setLength(-velRelativa.length());

                        // relembrando: temp reta é uma reta que vai do centro da bola até o ponto de colisão no robo
                        // eu vou aproveitar que ela é ortogonal ao lado do robo para encontrar o ponto do lado do robo que a vel colide
                        tempReta.translate(velRelativa.x2() - tempReta.x1(), velRelativa.y2() - tempReta.y1());

                        tempReta.intersect(tempLados[ladoColidido], intersecVel);

                        tempVelRelativa.setP1(*intersecVel);
                        tempVelRelativa.setP2(velRelativa.p2());

                        temp2VelRelativa.setP1(*interseccao);
                        temp2VelRelativa.setP2(*intersecVel);
                        temp2VelRelativa.setLength(-temp2VelRelativa.length());

                        tempVelRelativa.translate(temp2VelRelativa.p2() - tempVelRelativa.p1());

                        velRelativa.setP2(tempVelRelativa.p2());

                        _bola->setVelX(velRelativa.dx());
                        _bola->setVelY(velRelativa.dy());
                    }

                    else{
                        _bola->setVelX(velPtoColisao.dx());
                        _bola->setVelY(velPtoColisao.dy());
                    }

                }

                /*
             * LÓGICA PARA ENCONTRAR A VELOCIDADE RESULTANTE DA BOLA
             * FIM
             */

            }
        }
    }

    /*
     * BATE A BOLA NA PAREDE SE ELA ENCOSTOU
     * INICIO
     *
     */

    //DIAGONAL

    // canto superior esquerdo
    if(JRS(QLineF(100,100 + _bola->raio,170 + _bola->raio, 25),QPointF(_bola->getX(), _bola->getY())) <= 0){
        if(produtoEscalar(QLineF(0,0,_bola->getVelX(),_bola->getVelY()), QLineF(0,0,-1,-1)) > 0){
            vx = _bola->getVelX();
            _bola->setVelX(-_bola->getVelY());
            _bola->setVelY(-vx);
        }
    }
    // canto superior direito
    if(JRS(QLineF(1600,100 + _bola->raio,1530 - _bola->raio, 25),QPointF(_bola->getX(), _bola->getY())) >= 0){
        if(produtoEscalar(QLineF(0,0,_bola->getVelX(),_bola->getVelY()), QLineF(0,0, 1,-1)) > 0){
            vx = _bola->getVelX();
            _bola->setVelX(_bola->getVelY());
            _bola->setVelY(vx);
        }
    }
    // canto inferior direito
    if(JRS(QLineF(1600,1255 - _bola->raio,1530 - _bola->raio, 1325),QPointF(_bola->getX(), _bola->getY())) <= 0){
        if(produtoEscalar(QLineF(0,0,_bola->getVelX(),_bola->getVelY()), QLineF(0,0, 1,1)) > 0){
            vx = _bola->getVelX();
            _bola->setVelX(-_bola->getVelY());
            _bola->setVelY(-vx);
        }
    }
    // canto inferior esquerdo
    if(JRS(QLineF(100,1255 - _bola->raio,170 + _bola->raio, 1325),QPointF(_bola->getX(), _bola->getY())) >= 0){
        if(produtoEscalar(QLineF(0,0,_bola->getVelX(),_bola->getVelY()), QLineF(0,0, -1,1)) > 0){
            vx = _bola->getVelX();
            _bola->setVelX(_bola->getVelY());
            _bola->setVelY(vx);
        }
    }

    //HORIZONTAL

    // parede esquerda acima do gol
    if((_bola->getX() < _bola->raio + 100) && ((_bola->getY() > 25) && (_bola->getY() <= 475))){
        if(_bola->getVelX() < 0){
            _bola->setVelX(-_bola->getVelX());
        }
    }
    // parede esquerda abaixo do gol
    else if((_bola->getX() < _bola->raio + 100) && ((_bola->getY() >= 875) && (_bola->getY() < 1325))){
        if(_bola->getVelX() < 0){
            _bola->setVelX(-_bola->getVelX());
        }
    }
    // parede esquerda no gol
    else if((_bola->getX() < _bola->raio) && ((_bola->getY() > 475) && (_bola->getY() < 875))){
        if(_bola->getVelX() < 0){
            _bola->setVelX(-_bola->getVelX());
        }
    }
    // parede direita acima do gol
    if((_bola->getX() > 1600 - _bola->raio) && ((_bola->getY() > 25) && (_bola->getY() <= 475))){
        if(_bola->getVelX() > 0){
            _bola->setVelX(-_bola->getVelX());
        }
    }
    // parede direita abaixo do gol
    else if((_bola->getX() > 1600 - _bola->raio) && ((_bola->getY() >= 875) && (_bola->getY() < 1325))){
        if(_bola->getVelX() > 0){
            _bola->setVelX(-_bola->getVelX());
        }
    }
    // parede direita no gol
    else if((_bola->getX() > 1700 - _bola->raio) && ((_bola->getY() > 475) && (_bola->getY() < 875))){
        if(_bola->getVelX() > 0){
            _bola->setVelX(-_bola->getVelX());
        }
    }

    //VERTICAL

    // parte de cima do campo
    if(_bola->getY() < _bola->raio + 25){
        if(_bola->getVelY() < 0){
            _bola->setVelY(-_bola->getVelY());
        }
    }
    // parte de baixo do campo
    else if(_bola->getY() > 1325 - _bola->raio){
        if(_bola->getVelY() > 0){
            _bola->setVelY(-_bola->getVelY());
        }
    }
    //parte de cima gol esquerdo
    else if((_bola->getY() < 475) && (_bola->getX() < 100)){
        if(_bola->getVelY() < 0){
            _bola->setVelY(-_bola->getVelY());
        }
    }
    //parte de baixo gol esquerdo
    else if((_bola->getY() > 875) && (_bola->getX() < 100)){
        if(_bola->getVelY() > 0){
            _bola->setVelY(-_bola->getVelY());
        }
    }
    //parte de cima gol direito
    else if((_bola->getY() < 475) && (_bola->getX() > 1600)){
        if(_bola->getVelY() < 0){
            _bola->setVelY(-_bola->getVelY());
        }
    }
    //parte de baixo gol esquerdo
    else if((_bola->getY() > 875) && (_bola->getX() > 1600)){
        if(_bola->getVelY() > 0){
            _bola->setVelY(-_bola->getVelY());
        }
    }


    /*
     * BATE A BOLA NA PAREDE
     * FIM
     *
     */


    // move bola
    _bola->setX(_bola->getX() + _bola->getVelX()*deltaT());
    _bola->setY(_bola->getY() + _bola->getVelY()*deltaT());

    // diminui a velocidade da bola
    if(std::abs(_bola->getVelX()) > 0.0003){ // faz ela não ficar desacelerando infinitamente
        if(_bola->getVelX() > 0){
            _bola->setVelX(_bola->getVelX() - std::abs(_bola->getVelX())*_bola->perda);
        }
        else{
            _bola->setVelX(_bola->getVelX() + std::abs(_bola->getVelX())*_bola->perda);
        }
    }
    else{
        _bola->setVelX(0);
    }

    if(std::abs(_bola->getVelY()) > 0.0003){// faz ela não ficar desacelerando infinitamente
        if(_bola->getVelY() > 0){
            _bola->setVelY(_bola->getVelY() - std::abs(_bola->getVelY())*_bola->perda);
        }
        else{
            _bola->setVelY(_bola->getVelY() + std::abs(_bola->getVelY())*_bola->perda);
        }
    }
    else{
        _bola->setVelY(0);
    }

    //    qDebug() << "velChute = " << velChute.length();
    //    qDebug() << "raioChute = " << raioChute.length();
    //    qDebug() << "velLin = " << velLin;
    //    qDebug() << "sin = " << sin(raioChute.angleTo(tempLados[ladoColidido]));
    //    qDebug() << "sin x velLin = " << velLin * sin(raioChute.angleTo(tempLados[ladoColidido]));
    //    qDebug() << "ang Robo = " << robo[k].getAng();

    //    qDebug() << "vel robo = " << robo[0].getVel();
    //    qDebug() << "velAng robo = " << robo[k].getVelAng();
    //    qDebug() << "velx bola = " << bola->getVelX();
    //    qDebug() << "vely bola = " << bola->getVelY();

    //    qDebug() << "bola Y = " << bola->getY();

    //    qDebug() << "tempo " << *tempo << " ms";

    //    if(colisao) qDebug() << "Colidiu!!!";
    //    else qDebug() << "sem colisão";

    qDebug() << "tempo " << *tempo << " ms";


    tempoAnterior = *tempo;
}

QPointF fisica::getQuinas(int rob, int l){ // 0 - top dir; 1 - bai dir; 2 - bai esq; 3 - top esq
    QPointF quina;
    if(l == 0){
        quina.setY(robo[rob].getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (robo[rob].getAng() + 45))));
        quina.setX(robo[rob].getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (robo[rob].getAng() + 45))));
    }
    if(l == 1){
        quina.setY(robo[rob].getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (robo[rob].getAng() + 135))));
        quina.setX(robo[rob].getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (robo[rob].getAng() + 135))));
    }
    if(l == 2){
        quina.setY(robo[rob].getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (robo[rob].getAng() + 225))));
        quina.setX(robo[rob].getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (robo[rob].getAng() + 225))));
    }
    if(l == 3){
        quina.setY(robo[rob].getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (robo[rob].getAng() - 45))));
        quina.setX(robo[rob].getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (robo[rob].getAng() - 45))));
    }
    return quina;
}

QPointF fisica::getQuinas(robovss rob, int l){ // 0 - top dir; 1 - bai dir; 2 - bai esq; 3 - top esq
    QPointF quina;
    if(l == 0){
        quina.setY(rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() + 45))));
        quina.setX(rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() + 45))));
    }
    if(l == 1){
        quina.setY(rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() + 135))));
        quina.setX(rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() + 135))));
    }
    if(l == 2){
        quina.setY(rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() + 225))));
        quina.setX(rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() + 225))));
    }
    if(l == 3){
        quina.setY(rob.getY() - ((robovss::largura/cte::raiz2) * cos(cte::PI/180 * (rob.getAng() - 45))));
        quina.setX(rob.getX() + ((robovss::largura/cte::raiz2) * sin(cte::PI/180 * (rob.getAng() - 45))));
    }
    return quina;
}

double fisica::deltaT(){
    return (double)(*tempo - tempoAnterior);
}

double fisica::dist(double x1,double y1,double x2,double y2){
    return abs(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

double fisica::dist(QPointF p1, QPointF p2){
    return abs(sqrt(pow(p2.x() - p1.x(), 2) + pow(p2.y() - p1.y(), 2)));
}

double fisica::produtoEscalar(QLineF A, QLineF v){
    return ((A.dx() * v.dx()) + (A.dy() * v.dy()));
}

void fisica::colocaProbe(QPointF qpoint, int np){
    _probe[np].setX(qpoint.x());
    _probe[np].setY(qpoint.y());
}

// algoritmo para descobrir se um ponto está à direita ou esquerda de uma linha, considerando-se p1 da linha como a parte de baixo
//dela
// se a saída desta função for negativa, o ponto está à esquerda, se for positiva está à direita e se for nula está nela
int fisica::JRS(QLineF linha, QPointF ponto){
    return ((linha.x1() - ponto.x()) * (linha.y2() - ponto.y()) - ((linha.x2() - ponto.x()) * (linha.y1() - ponto.y())));
}


// uso produto escalar para saber se as coordenadas da quina estão dentro do retângulo do robô ou não
// o ponto M esta dentro do retângulo ABCD se: (0<AM⋅AB<AB⋅AB) &&(0<AM⋅AD<AD⋅AD)
bool fisica::estaDentro(QPointF quadrado[4], QPointF ponto){
    if((produtoEscalar(QLineF(quadrado[0], quadrado[1]), QLineF(quadrado[0], ponto)) > 0)
      && (produtoEscalar(QLineF(quadrado[0], quadrado[1]), QLineF(quadrado[0], ponto)) 
      < produtoEscalar(QLineF(quadrado[0], quadrado[1]), QLineF(quadrado[0], quadrado[1]))) 
      && (produtoEscalar(QLineF(quadrado[0],quadrado[3]), QLineF(quadrado[0], ponto)) > 0) 
      && (produtoEscalar(QLineF(quadrado[0], ponto), QLineF(quadrado[0], quadrado[3])) 
      < produtoEscalar(QLineF(quadrado[0], quadrado[3]), QLineF(quadrado[0], quadrado[3])))){
        return true;
    } 
    else{
        return false;
    }
}   
