#include "feedforward.h"

FeedForward::FeedForward(NeuralNetwork* iaa, NeuralNetwork* iab, Interface inter){
    ia_a = iaa;
    ia_b = iab;
    interface = inter;
}

void FeedForward::ia_match(){
    //======================  ENTRADA DE DADOS IA_A =========================
    int i = 0;
    for(int t = 0; t < 2; t++){
        for(int id = 0; id < 3; id++){
            ia_a->input.ptr[i] = interface.getPosX(t,id);
            i++;
            ia_a->input.ptr[i] = interface.getPosXQuina(t,id,0);
            i++;
            ia_a->input.ptr[i] = interface.getPosXQuina(t,id,1);
            i++;
            ia_a->input.ptr[i] = interface.getPosXQuina(t,id,2);
            i++;
            ia_a->input.ptr[i] = interface.getPosXQuina(t,id,3);
            i++;
            ia_a->input.ptr[i] = interface.getPosY(t,id);
            i++;
            ia_a->input.ptr[i] = interface.getPosYQuina(t,id,0);
            i++;
            ia_a->input.ptr[i] = interface.getPosYQuina(t,id,1);
            i++;
            ia_a->input.ptr[i] = interface.getPosYQuina(t,id,2);
            i++;
            ia_a->input.ptr[i] = interface.getPosYQuina(t,id,3);
            i++;
            ia_a->input.ptr[i] = interface.getVelX(t,id);
            i++;
            ia_a->input.ptr[i] = interface.getVelY(t,id);
            i++;
            ia_a->input.ptr[i] = interface.getVelAng(t,id);
            i++;
            ia_a->input.ptr[i] = interface.getVel(t,id);
            i++;
        }
    } 
    ia_a->input.ptr[i] = interface.getPosBolaX();
    i++;
    ia_a->input.ptr[i] = interface.getPosBolaY();
    i++;
    ia_a->input.ptr[i] = interface.getVelBolaX();
    i++;
    ia_a->input.ptr[i] = interface.getVelBolaY();
    i = 0;


    // aplica as entradas na rede neural
    ia_a->feed();


    
    //======================  ENTRADA DE DADOS IA_B =========================
    for(int t = 1; t >= 0; t--){
        for(int id = 0; id < 3; id++){
            ia_b->input.ptr[i] = interface.getPosX(t,id,true);
            i++;
            ia_b->input.ptr[i] = interface.getPosXQuina(t,id,0,true);
            i++;
            ia_b->input.ptr[i] = interface.getPosXQuina(t,id,1,true);
            i++;
            ia_b->input.ptr[i] = interface.getPosXQuina(t,id,2,true);
            i++;
            ia_b->input.ptr[i] = interface.getPosXQuina(t,id,3,true);
            i++;
            ia_b->input.ptr[i] = interface.getPosY(t,id,true);
            i++;
            ia_b->input.ptr[i] = interface.getPosYQuina(t,id,0,true);
            i++;
            ia_b->input.ptr[i] = interface.getPosYQuina(t,id,1,true);
            i++;
            ia_b->input.ptr[i] = interface.getPosYQuina(t,id,2,true);
            i++;
            ia_b->input.ptr[i] = interface.getPosYQuina(t,id,3,true);
            i++;
            ia_b->input.ptr[i] = interface.getVelX(t,id,true);
            i++;
            ia_b->input.ptr[i] = interface.getVelY(t,id,true);
            i++;
            ia_b->input.ptr[i] = interface.getVelAng(t,id,true);
            i++;
            ia_b->input.ptr[i] = interface.getVel(t,id,true);
            i++;
        }
    } 
    ia_b->input.ptr[i] = interface.getPosBolaX(true);
    i++;
    ia_b->input.ptr[i] = interface.getPosBolaY(true);
    i++;
    ia_b->input.ptr[i] = interface.getVelBolaX(true);
    i++;
    ia_b->input.ptr[i] = interface.getVelBolaY(true);
    i = 0;


    // aplica as entradas na rede neural
    ia_b->feed();


    // APLICA AS SAIDAS DAS REDES NEURAIS

    // saida dos dados da rede neural A
    interface.setVel(0,0,ia_a->output.ptr[0]);
    interface.setVelAng(0,0,ia_a->output.ptr[1]);
    interface.setVel(0,1,ia_a->output.ptr[2]);
    interface.setVelAng(0,1,ia_a->output.ptr[3]);
    interface.setVel(0,2,ia_a->output.ptr[4]);
    interface.setVelAng(0,2,ia_a->output.ptr[5]);



    // saida dos dados da rede neural B
    interface.setVel(1,0,ia_b->output.ptr[0],true);
    interface.setVelAng(1,0,ia_b->output.ptr[1],true);
    interface.setVel(1,1,ia_b->output.ptr[2],true);
    interface.setVelAng(1,1,ia_b->output.ptr[3],true);
    interface.setVel(1,2,ia_b->output.ptr[4],true);
    interface.setVelAng(1,2,ia_b->output.ptr[5],true);

}
