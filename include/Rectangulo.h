#ifndef RECTANGULO_H
#define RECTANGULO_H
#include <cmath>


class Rectangulo{
private:
    //pos_x y pos_y son la posicion de la esquina superior izda
    float largo, ancho, pos_x, pos_y, dx, dy;
    //ajusta el rectangulo para que no se salga de la pantalla
    void AjustarPosicion(float ancho, float alto);
public:
    Rectangulo();
    Rectangulo(float largo, float ancho, float _pos_x, float _pos_y, float dx, float dy);

    void SetAncho(float el_ancho);
    void SetLargo(float el_largo);
    void SetPosX(float x);
    void SetPosY(float y);
    void SetDX(float dx);
    void SetDY(float dy);

    float GetLargo(void)const;
    float GetAncho(void)const;
    float GetPosX(void)const;
    float GetPosY(void)const;
    float GetDX(void) const;    
    float GetDY(void) const;

    //incrementa pos_x y pos_y en dx y dy
    void Mover(void);
    //incrementa pos_x y pos_y en dx y dy asegurandose de que no sobrepasa el ancho ni el alto
    void Mover(float ancho, float alto);
    //incrementa pos_x y pos_y en dx y dy asegurandose de que no sobrepasa el ancho ni el alto
    //usando las flechas
    void MoverFlechas(char c, float ancho, float alto);
};


#endif