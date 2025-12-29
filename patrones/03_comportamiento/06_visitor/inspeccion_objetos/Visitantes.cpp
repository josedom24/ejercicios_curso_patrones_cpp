#include <iostream>
#include "Visitantes.hpp"

// ----------------------------------------
// VisitanteMostrar
// ----------------------------------------
void VisitanteMostrar::visitar(ElementoA& e) {
    std::cout << "[Mostrar] Información de ElementoA → ";
    e.operacion_especifica_A();
}

void VisitanteMostrar::visitar(ElementoB& e) {
    std::cout << "[Mostrar] Información de ElementoB → ";
    e.operacion_especifica_B();
}

// ----------------------------------------
// VisitanteValidar
// ----------------------------------------
void VisitanteValidar::visitar(ElementoA&) {
    std::cout << "[Validar] Comprobando ElementoA...\n";
}

void VisitanteValidar::visitar(ElementoB&) {
    std::cout << "[Validar] Comprobando ElementoB...\n";
}