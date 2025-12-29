#pragma once
#include "Elementos.hpp"

// ----------------------------------------
// Interfaz Visitante
// ----------------------------------------
class Visitante {
public:
    virtual ~Visitante() = default;

    virtual void visitar(ElementoA&) = 0;
    virtual void visitar(ElementoB&) = 0;
};

// ----------------------------------------
// Visitante concreto: Mostrar información
// ----------------------------------------
class VisitanteMostrar : public Visitante {
public:
    void visitar(ElementoA&) override;
    void visitar(ElementoB&) override;
};

// ----------------------------------------
// Visitante concreto: Validar
// ----------------------------------------
class VisitanteValidar : public Visitante {
public:
    void visitar(ElementoA&) override;
    void visitar(ElementoB&) override;
};