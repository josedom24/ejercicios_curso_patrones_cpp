#pragma once
#include <string>
#include <memory>

// ------------------------------------------------------------
// Memento avanzado: contenido + formato
// ------------------------------------------------------------
class MementoFormato {
private:
    std::string texto_;
    std::string fuente_;
    int tamaño_;
    std::string color_;

    // Solo el Editor puede crear y leer este memento
    friend class Editor;

    MementoFormato(std::string texto,
                   std::string fuente,
                   int tamaño,
                   std::string color)
        : texto_(std::move(texto))
        , fuente_(std::move(fuente))
        , tamaño_(tamaño)
        , color_(std::move(color)) {}

public:
    // Sin interfaz pública
};