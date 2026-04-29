#include <iostream>
#include <vector>
#include <memory>
#include "Visitantes.hpp"

// El cliente opera solo con Documento y Visitante
void cliente(Documento& doc, Visitante& visitante) {
    doc.accept(visitante);
}

int main() {
    std::vector<std::unique_ptr<Documento>> documentos;

    documentos.push_back(std::make_unique<Factura>("Cliente A", 1200.50));
    documentos.push_back(std::make_unique<Informe>("Informe anual", 35));

    VisitanteMostrar mostrar;
    VisitanteValidar validar;
    VisitanteExportar exportar; // NUEVO

    for (auto& d : documentos) {
        cliente(*d, mostrar);
    }

    std::cout << "\n--- Validando ---\n";

    for (auto& d : documentos) {
        cliente(*d, validar);
    }

    // NUEVO recorrido
    std::cout << "\n--- Exportando ---\n";
    
    for (auto& d : documentos) {
        cliente(*d, exportar);
    }
    return 0;
}