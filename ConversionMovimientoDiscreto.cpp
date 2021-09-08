#include <iostream>

# define PI 3.14159265358979323846  /* pi */

#include "ConversionMovimientoDiscreto.h"

using namespace std;

//Constructor
ConversionMovimientoDiscreto::ConversionMovimientoDiscreto(float x, float z) : x(x), z(z) {}

//Getters and Setter
float ConversionMovimientoDiscreto::getX() const {
    return x;
}

void ConversionMovimientoDiscreto::setX(float x) {
    ConversionMovimientoDiscreto::x = x;
}

float ConversionMovimientoDiscreto::getZ() const {
    return z;
}

void ConversionMovimientoDiscreto::setZ(float z) {
    ConversionMovimientoDiscreto::z = z;
}

/**
 * Funcion que calcula el angilo en radianes.
 * @param x float que es homologo al eje y
 * @param z float que es homologo al eje x
 * @return float con el angulo en radianes corregido por angulo de cuadrante
 */
float ConversionMovimientoDiscreto::calcularAngulo() {


    if (this->x >= 0 && this->z <= 0) { //Primer Cuadrante
        return (float) (atan2(abs(this->x), abs(this->z)) / (PI / 180));
    } else if (this->x >= 0 && this->z >= 0) { //Segundo Cuadrante
        return (float) ((PI - atan2(abs(this->x), abs(this->z))) / (PI / 180));
    } else if ((this->x <= 0 && this->z >= 0)) { //Tercer Cuadrante
        return (float) (((atan2(abs(this->x), abs(this->z)) + PI)) / (PI / 180));
    } else if (this->x <= 0 && this->z <= 0) { //Cuarto Cuadrane
        return (float) (((2 * PI) - atan2(abs(this->x), abs(this->z))) / (PI / 180));
    } else {
        return 0;
    }
}

/**
 * Funcion que recibe como parametros los dos ejes del Joystick y devuelve el modulo redondeado con dos decimales.
 * @param x float que es homologo al eje y
 * @param z float que es homologo al eje x
 * @return float con el modulo con dominio entre 0 y 1.
 */
float ConversionMovimientoDiscreto::calcularModulo() {
    float modulo;
    //Calculo el modulo con pitagoras
    modulo = (float) sqrt(pow(this->x, 2) + pow(this->z, 2));
    //Redondeo el valor del modulo
    modulo *= 10;
    modulo = round(modulo);
    return modulo / 10;
}


/**
 * COMPLETAR!!!!!
 * @param angulo
 * @param magnitud
 * @return struct movimiento con los valores float rueda izquierda y derecha
 */

Movimiento ConversionMovimientoDiscreto::devolverMovimientoDiscretizado() {
    float angulo = calcularAngulo();
    float magnitud = calcularModulo();

    Movimiento rueda = {0, 0};

    Movimiento array[12] = {{-0.05, 0.05},   //0 Giro en el lugar Izquierda
                            {0.05,  0},       //1 Amortiguacion Giro Derecha
                            {0.1,   0.05},    //2 Giro Suave Derecha
                            {0.1,   0.1},     //3 Avance Frontal
                            {0.05,  0.1},     //4 Giro Suave Izquierda
                            {0,     0.05},    //5 Amortiguacion Giro Izquierda
                            {0.05,  -0.05},    //6 Giro en el lugar derecha
                            {-0.05, 0},       //7 Amortiguacion giro Atras Derecha
                            {-0.1,  -0.05},    //8 Giro Suave atras Derecha
                            {-0.1,  -0.1},    //9 Retroceso
                            {-0.05, -0.1},    //10 Giro Suave atras izquierda
                            {0,     -0.05}};  //11 Amortiguacion giro atras izquierda

    //Movimientos hacia adelante

    if (angulo >= 67.5 && angulo <= 112.5) { //Movimiento frontal
        rueda.izquierda = (magnitud * array[3].izquierda) * 10;
        rueda.derecha = (magnitud * array[3].derecha) * 10;
        return rueda;

    } else if (angulo >= 27.5 && angulo <= 67.5) { //Giro suave derecha
        rueda.izquierda = (magnitud * array[2].izquierda) * 10;
        rueda.derecha = (magnitud * array[2].derecha) * 10;
        return rueda;

    } else if (angulo >= 112.5 && angulo <= 162.5) {//Giro Suave Izquirda
        rueda.izquierda = (magnitud * array[4].izquierda) * 10;
        rueda.derecha = (magnitud * array[4].derecha) * 10;
        return rueda;

    } else if (angulo >= 17.5 && angulo <= 27.5) { //Giro Amortiguado Derecha
        rueda.izquierda = (magnitud * array[1].izquierda) * 10;
        rueda.derecha = (magnitud * array[1].derecha) * 10;
        return rueda;

    } else if (angulo >= 162.5 && angulo <= 152.5) { //Giro Amortiguado Izquierda
        rueda.izquierda = (magnitud * array[5].izquierda) * 10;
        rueda.derecha = (magnitud * array[5].derecha) * 10;
        return rueda;
    } else if ((angulo >= 342.5 && angulo <= 360) || (angulo >= 0 && angulo <= 17.5)) { //Giro en el lugar derecha
        rueda.izquierda = (magnitud * array[6].izquierda) * 10;
        rueda.derecha = (magnitud * array[6].derecha) * 10;
        return rueda;
    } else if (angulo >= 152.5 && angulo <= 197.5) { //Giro en el lugar izquierda
        rueda.izquierda = (magnitud * array[0].izquierda) * 10;
        rueda.derecha = (magnitud * array[0].derecha) * 10;
        return rueda;

        //Movimientos hacia atras
    } else if (angulo >= 332.5 && angulo <= 342.5) { //Amortiguacion giro atras derecha
        rueda.izquierda = (magnitud * array[7].izquierda) * 10;
        rueda.derecha = (magnitud * array[7].derecha) * 10;
        return rueda;
    } else if (angulo >= 197.5 && angulo <= 207.5) { //Amortiguacion giro atras IZQUIERDA
        rueda.izquierda = (magnitud * array[11].izquierda) * 10;
        rueda.derecha = (magnitud * array[11].derecha) * 10;
        return rueda;
    } else if (angulo >= 292.5 && angulo <= 332.5) { //Giro Suave atras derecha
        rueda.izquierda = (magnitud * array[8].izquierda) * 10;
        rueda.derecha = (magnitud * array[8].derecha) * 10;
        return rueda;
    } else if (angulo >= 207.5 && angulo <= 247.5) { //Giro Suvae atras izquierda
        rueda.izquierda = (magnitud * array[10].izquierda) * 10;
        rueda.derecha = (magnitud * array[10].derecha) * 10;
        return rueda;
    } else if (angulo >= 247.5 && angulo <= 292.5) { //Retroceso
        rueda.izquierda = (magnitud * array[9].izquierda) * 10;
        rueda.derecha = (magnitud * array[9].derecha) * 10;
        return rueda;
    }
    return rueda;
}

ostream &operator<<(ostream &os, const ConversionMovimientoDiscreto &discreto) {
    os << "x: " << discreto.x << " z: " << discreto.z;

    return os;
}








