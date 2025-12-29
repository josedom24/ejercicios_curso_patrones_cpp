#include <iostream>
#include "Elementos.hpp"
#include "Visitantes.hpp"

// ----------------------------------------
// Implementación de accept (double dispatch)
// ----------------------------------------
void ElementoA::accept(Visitante& v) {
    v.visitar(*this);
}

void ElementoB::accept(Visitante& v) {
    v.visitar(*this);
}

// ----------------------------------------
// Lógica propia de los elementos
// ----------------------------------------
void ElementoA::operacion_especifica_A() const {
    std::cout << "ElementoA: realizando su lógica interna.\n";
}

void ElementoB::operacion_especifica_B() const {
    std::cout << "ElementoB: realizando su lógica interna.\n";
}