#include <iostream>

using namespace std;

#include "MovimientoDiscreto.hpp"

int main() {

    MovimientoDiscreto movimiento1;

    movimiento1.realizarMovimientoDiscreto((-0.1564 * 0.6), (0.9876 * 0.6));

    cout << "Rueda izquierda: " << movimiento1.getRueda().izquierda << " Rueda derecha: "
         << movimiento1.getRueda().derecha << endl;

    return 0;
}
