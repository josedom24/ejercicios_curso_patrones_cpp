#pragma once
#include <string>

// ------------------------------------------------------------
// Clase Memento (estado encapsulado)
// ------------------------------------------------------------
class Memento {
private:
    std::string estado_;

    // Solo el Editor puede acceder al contenido del memento
    friend class Editor;

    explicit Memento(std::string estado)
        : estado_(std::move(estado)) {}

public:
    // No se expone nada públicamente
};