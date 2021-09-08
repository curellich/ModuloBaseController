
#ifndef CONVERSIONAMOVIMIENTODISCRETO_CONVERSIONMOVIMIENTODISCRETO_H
#define CONVERSIONAMOVIMIENTODISCRETO_CONVERSIONMOVIMIENTODISCRETO_H


#include <ostream>

struct Movimiento {
    float izquierda;
    float derecha;
};

class ConversionMovimientoDiscreto {
private:
    float x;
    float z;

public:

    ConversionMovimientoDiscreto(float x, float z);

    float getX() const;

    void setX(float x);

    float getZ() const;

    void setZ(float z);

    float calcularAngulo();

    float calcularModulo();

    Movimiento devolverMovimientoDiscretizado();

    friend std::ostream &operator<<(std::ostream &os, const ConversionMovimientoDiscreto &discreto);
};


#endif //CONVERSIONAMOVIMIENTODISCRETO_CONVERSIONMOVIMIENTODISCRETO_H
