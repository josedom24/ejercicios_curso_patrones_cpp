#include <iostream>
#include <memory>

// ----------------------------------------
// Declaraciones anticipadas
// ----------------------------------------
class Estado;

// ----------------------------------------
// Contexto (solo declaración de métodos)
// ----------------------------------------
class Contexto {
public:
    explicit Contexto(std::unique_ptr<Estado> estado_inicial);

    void cambiar_estado(std::unique_ptr<Estado> nuevo_estado);
    void accion();

private:
    std::unique_ptr<Estado> estado;
};

// ----------------------------------------
// Interfaz base del estado
// ----------------------------------------
class Estado {
public:
    virtual ~Estado() = default;
    virtual void accion(Contexto& contexto) = 0;
};

// ----------------------------------------
// Declaraciones anticipadas de estados
// ----------------------------------------
class EstadoConcretoA;
class EstadoConcretoB;

// ----------------------------------------
// Estado concreto A
// ----------------------------------------
class EstadoConcretoA : public Estado {
public:
    void accion(Contexto& contexto) override;
};

// ----------------------------------------
// Estado concreto B
// ----------------------------------------
class EstadoConcretoB : public Estado {
public:
    void accion(Contexto& contexto) override;
};

// ----------------------------------------
// Implementación de Contexto
// ----------------------------------------
Contexto::Contexto(std::unique_ptr<Estado> estado_inicial)
    : estado(std::move(estado_inicial)) {}

void Contexto::cambiar_estado(std::unique_ptr<Estado> nuevo_estado) {
    estado = std::move(nuevo_estado);
}

void Contexto::accion() {
    estado->accion(*this);
}

// ----------------------------------------
// Implementaciones de estados
// ----------------------------------------
void EstadoConcretoA::accion(Contexto& contexto) {
    std::cout << "Estado A: ejecutando acción...\n";
    std::cout << "Transición de A → B.\n";
    contexto.cambiar_estado(std::make_unique<EstadoConcretoB>());
}

void EstadoConcretoB::accion(Contexto& contexto) {
    std::cout << "Estado B: ejecutando acción...\n";
    std::cout << "Transición de B → A.\n";
    contexto.cambiar_estado(std::make_unique<EstadoConcretoA>());
}

// ----------------------------------------
// Cliente
// ----------------------------------------
int main() {
    Contexto contexto(std::make_unique<EstadoConcretoA>());

    contexto.accion(); // A → B
    contexto.accion(); // B → A
    contexto.accion(); // A → B
}
