#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// ----------------------------------------
// Interfaz base del componente
// ----------------------------------------
class Elemento {
public:
    virtual ~Elemento() = default;
    virtual void mostrar(int indentacion = 0) const = 0;
};

// ----------------------------------------
// Componente hoja: Archivo
// ----------------------------------------
class Archivo : public Elemento {
private:
    std::string nombre_;

public:
    explicit Archivo(std::string nombre)
        : nombre_(std::move(nombre)) {}

    void mostrar(int indentacion = 0) const override {
        std::cout << std::string(indentacion, ' ')
                  << "- " << nombre_ << "\n";
    }
};

// ----------------------------------------
// Componente compuesto: Directorio
// ----------------------------------------
class Directorio : public Elemento {
private:
    std::string nombre_;
    std::vector<std::unique_ptr<Elemento>> hijos_;

public:
    explicit Directorio(std::string nombre)
        : nombre_(std::move(nombre)) {}

    // Añadir un elemento hijo
    void agregar(std::unique_ptr<Elemento> elemento) {
        hijos_.push_back(std::move(elemento));
    }

    void mostrar(int indentacion = 0) const override {
        std::cout << std::string(indentacion, ' ')
                  << "+ " << nombre_ << "/\n";

        for (const auto& hijo : hijos_) {
            hijo->mostrar(indentacion + 2); // recursión
        }
    }
};

// ----------------------------------------
// Nuevo tipo de hoja: Enlace simbólico
// ----------------------------------------
class Enlace : public Elemento {
private:
    std::string nombre_;
    const Elemento* objetivo_;  // no posee, solo referencia

public:
    Enlace(std::string nombre, const Elemento* objetivo)
        : nombre_(std::move(nombre)), objetivo_(objetivo) {}

    void mostrar(int indentacion = 0) const override {
        std::cout << std::string(indentacion, ' ')
                  << "- " << nombre_
                  << " -> (enlace a otro elemento)\n";
    }
};