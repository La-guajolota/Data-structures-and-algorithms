#include "HP_EMA.h"

void EMA_init(FILTRO_EMA *filt, float beta){

    EMA_setbeta(filt,beta);//Seteamos el valor de beta
    filt->out = 0.0f; //Limmpiamos a salida del filtro
    filt->inp = 0.0f; //Limmpiamos la entrada del filtro

}

void EMA_setbeta(FILTRO_EMA *filt, float beta){

    //Clampeams beta de 0 a 1
    if(beta > 1.0f){
        beta = 1.0f;
    }
    if(beta < 0.0f){
        beta = 0.0f;
    }
    
    filt->beta = beta;//Seteamos el valor del coeficiente
}

float EMA_update(FILTRO_EMA *filt, float inp){
    /*
        ECUACION INDIFERENCIA DEL FILTRO EMA
        Yn= 0.5*(2-b)*(Xn-X(n-1)) + (1-b)*Y(n-1)
    */

   filt->out = 0.5f*(2.0f-filt->beta)*(inp - filt->inp) + (1.0f-filt->beta)*filt->out;
   filt->inp = inp; 

   return filt->out;
}