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

// ----------------------------------------
// VisitanteExportar
// ----------------------------------------

void VisitanteExportar::visitar(ElementoA&) {
    std::cout << "[Exportar] Exportando ElementoA en formato JSON.\n";
}

void VisitanteExportar::visitar(ElementoB&) {
    std::cout << "[Exportar] Exportando ElementoB en formato JSON.\n";
}