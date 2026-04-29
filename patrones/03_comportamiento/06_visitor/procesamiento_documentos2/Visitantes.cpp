#include <iostream>
#include "Visitantes.hpp"

// ----------------------------------------
// VisitanteMostrar
// ----------------------------------------
void VisitanteMostrar::visitar(Factura& f) {
    std::cout << "[Mostrar] Factura\n";
    std::cout << "Cliente: " << f.getCliente() << "\n";
    std::cout << "Importe: " << f.getImporte() << "\n";
}

void VisitanteMostrar::visitar(Informe& i) {
    std::cout << "[Mostrar] Informe\n";
    std::cout << "Título: " << i.getTitulo() << "\n";
    std::cout << "Páginas: " << i.getPaginas() << "\n";
}

// ----------------------------------------
// VisitanteValidar
// ----------------------------------------
void VisitanteValidar::visitar(Factura& f) {
    std::cout << "[Validar] Factura...\n";

    if (f.getImporte() <= 0) {
        std::cout << "Error: importe inválido\n";
    }
}

void VisitanteValidar::visitar(Informe& i) {
    std::cout << "[Validar] Informe...\n";

    if (i.getPaginas() <= 0) {
        std::cout << "Error: número de páginas inválido\n";
    }
}


// ----------------------------------------
// VisitanteExportar
// ----------------------------------------
void VisitanteExportar::visitar(Factura& f) {
    std::cout << "{ \"tipo\": \"factura\", \"cliente\": \""
              << f.getCliente()
              << "\", \"importe\": "
              << f.getImporte()
              << " }\n";
}

void VisitanteExportar::visitar(Informe& i) {
    std::cout << "{ \"tipo\": \"informe\", \"titulo\": \""
              << i.getTitulo()
              << "\", \"paginas\": "
              << i.getPaginas()
              << " }\n";
}