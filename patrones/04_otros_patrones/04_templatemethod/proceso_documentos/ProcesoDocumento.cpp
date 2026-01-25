#include "ProcesoDocumento.hpp"
#include <iostream>
#include <utility>

ProcesoDocumento::ProcesoDocumento(
    std::function<std::string()> leer,
    std::function<void(const std::string&)> procesar)
    : leer_(std::move(leer)),
      procesar_(std::move(procesar)) {}

void ProcesoDocumento::ejecutar() const {
    abrir();
    auto contenido = leer_();
    procesar_(contenido);
    cerrar();
}

void ProcesoDocumento::abrir() const {
    std::cout << "[ProcesoDocumento] Abriendo documento...\n";
}

void ProcesoDocumento::cerrar() const {
    std::cout << "[ProcesoDocumento] Cerrando documento.\n";
}