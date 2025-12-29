#include <iostream>
#include <vector>
#include <memory>
#include "Visitantes.hpp"

// El cliente opera solo con Elemento y Visitante
void cliente(Elemento& elem, Visitante& visitante) {
    elem.accept(visitante);
}

int main() {
    std::vector<std::unique_ptr<Elemento>> elementos;
    elementos.push_back(std::make_unique<ElementoA>());
    elementos.push_back(std::make_unique<ElementoB>());

    VisitanteMostrar mostrar;
    VisitanteValidar validar;
    VisitanteExportar exportar; //NUEVO

    for (auto& e : elementos) {
        cliente(*e, mostrar);
    }

    std::cout << "\n--- Validando ---\n";

    for (auto& e : elementos) {
        cliente(*e, validar);
    }

    std::cout << "\n--- Exportando ---\n";
    for (auto& e : elementos) {
        cliente(*e, exportar);
    }

    return 0;
}