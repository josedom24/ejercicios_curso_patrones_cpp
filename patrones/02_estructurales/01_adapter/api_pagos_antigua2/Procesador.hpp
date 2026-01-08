#pragma once
#include <iostream>

// ----------------------------------------
// Interfaz moderna (Target)
// ----------------------------------------
class ProcesadorPago {
public:
    virtual ~ProcesadorPago() = default;
    virtual void pagar(double cantidad) const = 0;
};