#ifndef CIRCULO_H
#define CIRCULO_H
#include <cmath>

class Circulo{
private:
    float radio, p_x, p_y, dx, dy;
    void AjustarPosiciones(float ancho, float alto);
public:
    Circulo();
    Circulo(float radio, float x, float y, float vx, float vy);
    void SetRadio(float);
    void SetDX(float);
    void SetDY(float);    
    void SetPosX(float);
    void SetPosY(float);

    float GetRadio(void) const;
    float GetPosX(void) const;    
    float GetPosY(void) const;   
    float GetDX(void) const;
    float GetDY(void) const;
    
    void Mover(void);
    void Mover(float ancho, float alto);
    void RebotaBordes(float ancho, float alto);
};
#endif