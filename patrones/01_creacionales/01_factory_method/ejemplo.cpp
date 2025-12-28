#include <iostream>
#include <memory>

// ----------------------------------------
// Interfaz base del producto
// ----------------------------------------
class Producto {
public:
    virtual ~Producto() = default;
    virtual void operar() const = 0;
};

// Producto concreto A
class ProductoConcretoA : public Producto {
public:
    void operar() const override {
        std::cout << "Operación del ProductoConcretoA.\n";
    }
};

// Producto concreto B
class ProductoConcretoB : public Producto {
public:
    void operar() const override {
        std::cout << "Operación del ProductoConcretoB.\n";
    }
};

// ----------------------------------------
// Interfaz base del creador
// ----------------------------------------
class Creador {
public:
    virtual ~Creador() = default;

    // Factory Method
    virtual std::unique_ptr<Producto> crear_producto() const = 0;

    // Operación que utiliza el producto
    void ejecutar() const {
        auto producto = crear_producto();
        producto->operar();
    }
};

// Creador concreto A
class CreadorConcretoA : public Creador {
public:
    std::unique_ptr<Producto> crear_producto() const override {
        return std::make_unique<ProductoConcretoA>();
    }
};

// Creador concreto B
class CreadorConcretoB : public Creador {
public:
    std::unique_ptr<Producto> crear_producto() const override {
        return std::make_unique<ProductoConcretoB>();
    }
};

// ----------------------------------------
// Función cliente
// ----------------------------------------
void cliente(const Creador& creador) {
    creador.ejecutar();
}

int main() {
    CreadorConcretoA fabricaA;
    CreadorConcretoB fabricaB;

    cliente(fabricaA);
    cliente(fabricaB);

    return 0;
}