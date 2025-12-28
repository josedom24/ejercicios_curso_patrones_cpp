#pragma once
#include <iostream>
#include <memory>
#include <string>

// ----------------------------------------
// Interfaz base del prototipo: Forma
// ----------------------------------------
class Forma {
public:
    virtual ~Forma() = default;
    virtual std::unique_ptr<Forma> clonar() const = 0;
    virtual void dibujar() const = 0;
};

// ----------------------------------------
// Prototipo concreto: Rectángulo
// ----------------------------------------
class Rectangulo : public Forma {
private:
    int ancho_;
    int alto_;

public:
    Rectangulo(int ancho, int alto)
        : ancho_(ancho), alto_(alto) {}

    std::unique_ptr<Forma> clonar() const override {
        // Copia superficial (suficiente para tipos primitivos)
        return std::make_unique<Rectangulo>(*this);
    }

    void dibujar() const override {
        std::cout << "Rectángulo [" << ancho_
                  << "x" << alto_ << "]\n";
    }
};

// ----------------------------------------
// Prototipo concreto: Círculo
// ----------------------------------------
class Circulo : public Forma {
private:
    int radio_;

public:
    explicit Circulo(int radio)
        : radio_(radio) {}

    std::unique_ptr<Forma> clonar() const override {
        return std::make_unique<Circulo>(*this);
    }

    void dibujar() const override {
        std::cout << "Círculo (radio=" << radio_ << ")\n";
    }
};


// ----------------------------------------
// Prototipo concreto: Triángulo
// ----------------------------------------

class Triangulo : public Forma {
private:
    int base_;
    int altura_;

public:
    Triangulo(int base, int altura)
        : base_(base), altura_(altura) {}

    std::unique_ptr<Forma> clonar() const override {
        return std::make_unique<Triangulo>(*this);
    }

    void dibujar() const override {
        std::cout << "Triángulo (base=" << base_
                  << ", altura=" << altura_ << ")\n";
    }
};