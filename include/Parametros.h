#ifndef PARAMETROS_H
#define PARAMETROS_H

//variables de pantalla
const int ANCHO_PANTALLA = 1000;
const int ALTO_PANTALLA = 600;
const int FPS = 60; // si se aumentan o disminuyen hay que modificar las velocidades


//variables de juego
    //velocidades
const float VELOCIDAD_BARRA = 10.0f;
const int V_MIN = -40;
const int V_MAX = 40;
const float ACELELARION_PELOTA = 1.002f;

    //numero maximo de partidas
const int PUNTOS_GANADORES = 5;

    //variables de visualizacion
const int TAM_PELOTA = 10;
const int ALTO_BARRA = 110;
const int ANCHO_BARRA = 20;
const int PY_INICIAL = ALTO_PANTALLA / 2 - ALTO_BARRA;
const int PX_INICIAL_IZD = ANCHO_BARRA;
const int PX_INICIAL_DCH = ANCHO_PANTALLA - 2 * ANCHO_BARRA;

//variables de texto
const int P_X_TXT = ANCHO_PANTALLA / 2;
const int P_Y_TXT = 10;
const int TAM_LETRA = 40;

#endif