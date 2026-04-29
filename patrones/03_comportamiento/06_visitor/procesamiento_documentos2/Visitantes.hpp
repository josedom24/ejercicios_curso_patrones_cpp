#pragma once
#include "Documentos.hpp"

// ----------------------------------------
// Interfaz Visitante
// ----------------------------------------
class Visitante {
public:
    virtual ~Visitante() = default;

    virtual void visitar(Factura&) = 0;
    virtual void visitar(Informe&) = 0;
};

// ----------------------------------------
// Visitante concreto: Mostrar información
// ----------------------------------------
class VisitanteMostrar : public Visitante {
public:
    void visitar(Factura&) override;
    void visitar(Informe&) override;
};

// ----------------------------------------
// Visitante concreto: Validar
// ----------------------------------------
class VisitanteValidar : public Visitante {
public:
    void visitar(Factura&) override;
    void visitar(Informe&) override;
};


// ----------------------------------------
// NUEVO Visitante concreto: Exportar
// ----------------------------------------
class VisitanteExportar : public Visitante {
public:
    void visitar(Factura&) override;
    void visitar(Informe&) override;
};