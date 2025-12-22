#pragma once
#include <iostream>
#include <string>

// ----------------------------------------
// Nueva API incompatible (Adaptee #2)
// ----------------------------------------
class ApiPagoBanco {
public:
    void realizar_transferencia(double cantidad, const std::string& iban_destino) const {
        std::cout << "[Banco] Transferencia de " << cantidad
                  << " euros enviada al IBAN " << iban_destino << ".\n";
    }
};