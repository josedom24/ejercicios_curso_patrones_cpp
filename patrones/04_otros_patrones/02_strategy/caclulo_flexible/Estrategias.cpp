#include "Estrategias.hpp"

// ----------------------------------------
// Implementación de estrategias
// ----------------------------------------
EstrategiaCalculo estrategia_suma() {
    return [](int a, int b) {
        return a + b;
    };
}

EstrategiaCalculo estrategia_producto() {
    return [](int a, int b) {
        return a * b;
    };
}

EstrategiaCalculo estrategia_potencia() {
    return [](int a, int b) {
        int resultado = 1;
        for (int i = 0; i < b; ++i) {
            resultado *= a;
        }
        return resultado;
    };
}