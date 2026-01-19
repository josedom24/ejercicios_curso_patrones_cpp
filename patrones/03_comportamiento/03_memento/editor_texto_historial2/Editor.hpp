#pragma once
#include <string>
#include <memory>
#include <iostream>

#include "Memento.hpp"
#include "MementoFormato.hpp"

// ------------------------------------------------------------
// Clase Originador: Editor
// ------------------------------------------------------------
class Editor {
private:
    // Estado base
    std::string texto_;

    // Estado adicional (formato)
    std::string fuente_ = "Arial";
    int tamaño_ = 12;
    std::string color_ = "Negro";

public:
    // Constructor base (USADO EN main.cpp)
    explicit Editor(std::string inicial = "")
        : texto_(std::move(inicial)) {}

    // --------------------------------------------------------
    // Operaciones del editor
    // --------------------------------------------------------
    void escribir(const std::string& nuevo) {
        texto_ += nuevo;
    }

    void cambiar_formato(std::string fuente, int tamaño, std::string color) {
        fuente_ = std::move(fuente);
        tamaño_ = tamaño;
        color_ = std::move(color);
    }

    void mostrar() const {
        std::cout << "Texto: \"" << texto_ << "\"\n"
                  << "Formato: " << fuente_
                  << ", " << tamaño_
                  << ", " << color_ << "\n";
    }

    // --------------------------------------------------------
    // Memento básico (texto)
    // --------------------------------------------------------
    std::unique_ptr<Memento> crear_memento() const {
        return std::unique_ptr<Memento>(new Memento(texto_));
    }

    void restaurar(const Memento& m) {
        texto_ = m.estado_;
    }

    // --------------------------------------------------------
    // Memento avanzado (texto + formato)
    // --------------------------------------------------------
    std::unique_ptr<MementoFormato> crear_memento_formato() const {
        return std::unique_ptr<MementoFormato>(
            new MementoFormato(texto_, fuente_, tamaño_, color_));
    }

    void restaurar(const MementoFormato& m) {
        texto_  = m.texto_;
        fuente_ = m.fuente_;
        tamaño_ = m.tamaño_;
        color_  = m.color_;
    }
};
