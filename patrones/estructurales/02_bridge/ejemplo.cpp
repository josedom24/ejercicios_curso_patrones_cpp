#include <iostream>
#include <memory>
#include <string>

// ----------------------------------------
// Interfaz del Implementador
// ----------------------------------------
class Implementador {
public:
    virtual ~Implementador() = default;

    // Operación de bajo nivel que la abstracción utilizará
    virtual void operacion_implementacion(const std::string& contexto) const = 0;
};

// Implementador concreto A
class ImplementadorConcretoA : public Implementador {
public:
    void operacion_implementacion(const std::string& contexto) const override {
        std::cout << "[Implementador A] Procesando contexto: " << contexto << "\n";
    }
};

// Implementador concreto B
class ImplementadorConcretoB : public Implementador {
public:
    void operacion_implementacion(const std::string& contexto) const override {
        std::cout << "[Implementador B] Manejo alternativo de: " << contexto << "\n";
    }
};

// ----------------------------------------
// Abstracción
// ----------------------------------------
class Abstraccion {
protected:
    std::unique_ptr<Implementador> impl_;  // Bridge

public:
    explicit Abstraccion(std::unique_ptr<Implementador> impl)
        : impl_(std::move(impl)) {}

    virtual ~Abstraccion() = default;

    // Permite cambiar la implementación en tiempo de ejecución, si se desea
    void cambiar_implementador(std::unique_ptr<Implementador> nuevo_impl) {
        impl_ = std::move(nuevo_impl);
    }

    // Operación de alto nivel
    virtual void operacion(const std::string& datos) const = 0;
};

// Abstracción refinada A
class AbstraccionRefinadaA : public Abstraccion {
public:
    using Abstraccion::Abstraccion; // hereda el constructor

    void operacion(const std::string& datos) const override {
        std::cout << "[Abstracción A] Preparando datos...\n";
        std::string contexto = "A:" + datos;
        impl_->operacion_implementacion(contexto);
    }
};

// Abstracción refinada B
class AbstraccionRefinadaB : public Abstraccion {
public:
    using Abstraccion::Abstraccion; // hereda el constructor

    void operacion(const std::string& datos) const override {
        std::cout << "[Abstracción B] Validando y transformando datos...\n";
        std::string contexto = "B<" + datos + ">";
        impl_->operacion_implementacion(contexto);
    }
};

// ----------------------------------------
// Código cliente
// ----------------------------------------
int main() {
    // Abstracción A con Implementador A
    AbstraccionRefinadaA objetoA{
        std::make_unique<ImplementadorConcretoA>()
    };
    objetoA.operacion("petición 1");

    // Abstracción B con Implementador B
    AbstraccionRefinadaB objetoB{
        std::make_unique<ImplementadorConcretoB>()
    };
    objetoB.operacion("petición 2");

    // Cambiar implementación en tiempo de ejecución
    objetoB.cambiar_implementador(std::make_unique<ImplementadorConcretoA>());
    objetoB.operacion("petición 3 (reconfigurada)");

    return 0;
}