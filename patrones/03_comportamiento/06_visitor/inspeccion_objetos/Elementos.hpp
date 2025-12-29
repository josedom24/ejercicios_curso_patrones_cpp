#pragma once

// Declaración anticipada
class Visitante;

// ----------------------------------------
// Interfaz base del elemento
// ----------------------------------------
class Elemento {
public:
    virtual ~Elemento() = default;
    virtual void accept(Visitante& v) = 0;
};

// ----------------------------------------
// Elemento concreto A
// ----------------------------------------
class ElementoA : public Elemento {
public:
    void accept(Visitante& v) override;
    void operacion_especifica_A() const;
};

// ----------------------------------------
// Elemento concreto B
// ----------------------------------------
class ElementoB : public Elemento {
public:
    void accept(Visitante& v) override;
    void operacion_especifica_B() const;
};