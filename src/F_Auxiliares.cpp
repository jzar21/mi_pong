#include "F_Auxiliares.h"                                    
#include "raylib.h"


bool Igual(float a, float b){
    return fabsf(a - b) <= DIFF;
}

bool Colision(const Rectangulo &r, const Pelota &p){
    Vector2 punto = {p.GetPosX(), p.GetPosY()};
    Rectangle rec = {r.GetPosX(), r.GetPosY(), r.GetAncho(), r.GetLargo()};

    return CheckCollisionPointRec(punto, rec);                                        
}

char Direccion(){
    char dir = ' ';
    if (IsKeyDown(KEY_UP))
        dir = 'U';
    if (IsKeyDown(KEY_DOWN))
        dir = 'D';
    if (IsKeyDown(KEY_LEFT))
        dir = 'L';
    if (IsKeyDown(KEY_RIGHT))
        dir = 'R';
    return dir;
}

char Direccion2(){
    char dir = ' ';
    
    if (IsKeyDown(KEY_W))
        dir = 'U';
    if(IsKeyDown(KEY_S))
        dir = 'D';
    if(IsKeyDown(KEY_A))
        dir = 'L';
    if(IsKeyDown(KEY_D))
        dir = 'R';
    return dir;
}