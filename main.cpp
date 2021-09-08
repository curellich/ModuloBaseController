#include <iostream>

using namespace std;

#include "ConversionMovimientoDiscreto.h"

int main() {

    ConversionMovimientoDiscreto movimiento1((0.6691 * 0.7), (0.7431 * 0.7));

    cout << movimiento1 << endl;

    cout<<"Angulo: "<<movimiento1.calcularAngulo();
    cout<<" Modulo: "<<movimiento1.calcularModulo() << endl;

    cout << "Rueda izquierda: " << movimiento1.devolverMovimientoDiscretizado().izquierda << " Rueda Derecha: "
         << movimiento1.devolverMovimientoDiscretizado().derecha << endl;
    return 0;
}
