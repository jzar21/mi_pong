#ifndef CIRCULO_H
#define CIRCULO_H
#include <cmath>

class Circulo{
private:
    float radio, p_x, p_y, dx, dy;
    //hace que el circulo no pase del ancho ni del alto
    void AjustarPosiciones(float ancho, float alto);
public:
    Circulo();
    Circulo(float radio, float x, float y, float vx, float vy);

    void SetRadio(float el_radio);
    void SetDX(float dx);
    void SetDY(float dy);    
    void SetPosX(float x);
    void SetPosY(float y);

    float GetRadio(void) const;
    float GetPosX(void) const;    
    float GetPosY(void) const;   
    float GetDX(void) const;
    float GetDY(void) const;
    
    //incrementa p_x y p_y en dx y dy
    void Mover(void);
    //incrementa p_x y p_y en dx y dy asegurandose de que no sobrepasa el ancho ni el alto
    void Mover(float ancho, float alto);
    //cambia dy si la pelota llega al alto o al alcho
    void RebotaBordes(float ancho, float alto);
};
#endif