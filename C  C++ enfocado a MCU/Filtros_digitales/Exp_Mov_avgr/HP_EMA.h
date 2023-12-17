/*
    Credit goes for https://www.youtube.com/watch?v=1e_ZB8p5n6s
    From that resource this was based

    ESTO ES UN FILTRO PASA ALTAS DE EXPONENIAL MOVING AVERAGE
                Yn= 0.5*(2-b)*(Xn-X(n-1)) + (1-b)*Y(n-1)
*/

#ifndef HP_EMA_H
#define HP_EMA_H

typedef struct{

    float beta; //Coeficiente de filtrado alfa
    float out; // Salida del filtro
    float inp; // entrada del filtro


}FILTRO_EMA;

void EMA_init(FILTRO_EMA *filt, float beta); //Iniciamos el filtro con un valor de usuario en alppha
void EMA_setalpha(FILTRO_EMA *filt, float beta); //Clampeamos alpha
float EMA_update(FILTRO_EMA *filt, float inp); //Aplicamos el filtro

#endif