#pragma once
#include <string>
#include <memory>
#include <iostream>
#include "Memento.hpp"

// ------------------------------------------------------------
// Clase Originador: Editor
// ------------------------------------------------------------
class Editor {
private:
    std::string texto_;

public:
    explicit Editor(std::string inicial = "")
        : texto_(std::move(inicial)) {}

    void escribir(const std::string& nuevo) {
        texto_ += nuevo;
    }

    void mostrar() const {
        std::cout << "Contenido actual: \"" << texto_ << "\"\n";
    }

    // Crear memento
    std::unique_ptr<Memento> crear_memento() const {
        return std::unique_ptr<Memento>(new Memento(texto_));
    }

    // Restaurar desde un memento
    void restaurar(const Memento& m) {
        texto_ = m.estado_;
    }
};