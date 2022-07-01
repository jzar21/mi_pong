#ifndef PELOTA_H
#define PELOTA_H
#include <cmath>

class Pelota{
private:
    float radio, p_x, p_y, dx, dy;
    void AjustarPosiciones(float, float);
public:
    Pelota();
    Pelota(float, float, float, float, float);
    void SetRadio(float);
    void SetDX(float);
    void Mover(void);
    void Mover(float, float);
    void RebotaBordes(float, float);
    float GetRadio(void) const;
    float GetPosX(void) const;    
    float GetPosY(void) const;   
    float GetDX(void) const;
};
#endif