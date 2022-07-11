#ifndef PARAMETROS_H
#define PARAMETROS_H

//variables de pantalla
const int ancho = 1000;
const int largo = 600;
 
//variables de juego
const float v_barra = 10.0f;
const int P_MAX = 5;
const int V_MIN = -40;
const int V_MAX = 40;
const float ACELELARION_PELOTA = 1.003f;
const int t_pelota = 10;
const int alto_barra = 110;
const int ancho_barra = 20;
const int posy_ini = largo / 2 - alto_barra;
const int posx_ini_izd = ancho_barra;
const int posx_ini_dch = ancho - 2 * ancho_barra;


const int P_X_TXT = ancho / 2;
const int P_Y_TXT = 10;
const int TAM_LETRA = 40;

#endif