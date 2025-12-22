#pragma once
#include <iostream>

// ----------------------------------------
// Clase adaptada (Adaptee): API antigua
// ----------------------------------------
class ApiPagoAntigua {
public:
    void enviar_pago(double monto) const {
        std::cout << "[API antigua] Pago enviado por valor de " << monto << " euros.\n";
    }
};