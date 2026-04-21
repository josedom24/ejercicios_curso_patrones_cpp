#include <iostream>
#include <memory>

// ======================================================
//    Interfaces abstractas de los productos
// ======================================================

// Producto 1
class ProductoA {
public:
    virtual ~ProductoA() = default;
    virtual void operacionA() const = 0;
};

// Producto 2
class ProductoB {
public:
    virtual ~ProductoB() = default;
    virtual void operacionB() const = 0;
};


// ======================================================
//    Productos concretos de la Familia A
// ======================================================

class ProductoA_FamiliaA : public ProductoA {
public:
    void operacionA() const override {
        std::cout << "Ejecutando operación A en ProductoA_FamiliaA\n";
    }
};

class ProductoB_FamiliaA : public ProductoB {
public:
    void operacionB() const override {
        std::cout << "Ejecutando operación B en ProductoB_FamiliaA\n";
    }
};


// ======================================================
//    Productos concretos de la Familia B
// ======================================================

class ProductoA_FamiliaB : public ProductoA {
public:
    void operacionA() const override {
        std::cout << "Ejecutando operación A en ProductoA_FamiliaB\n";
    }
};

class ProductoB_FamiliaB : public ProductoB {
public:
    void operacionB() const override {
        std::cout << "Ejecutando operación B en ProductoB_FamiliaB\n";
    }
};


// ======================================================
//    Fábrica abstracta
// ======================================================

class FabricaAbstracta {
public:
    virtual ~FabricaAbstracta() = default;

    virtual std::unique_ptr<ProductoA> crearProductoA() const = 0;
    virtual std::unique_ptr<ProductoB> crearProductoB() const = 0;
};


// ======================================================
//    Fábricas concretas
// ======================================================

class FabricaFamiliaA : public FabricaAbstracta {
public:
    std::unique_ptr<ProductoA> crearProductoA() const override {
        return std::make_unique<ProductoA_FamiliaA>();
    }

    std::unique_ptr<ProductoB> crearProductoB() const override {
        return std::make_unique<ProductoB_FamiliaA>();
    }
};

class FabricaFamiliaB : public FabricaAbstracta {
public:
    std::unique_ptr<ProductoA> crearProductoA() const override {
        return std::make_unique<ProductoA_FamiliaB>();
    }

    std::unique_ptr<ProductoB> crearProductoB() const override {
        return std::make_unique<ProductoB_FamiliaB>();
    }
};


// ======================================================
//    Código cliente
// ======================================================

void cliente(const FabricaAbstracta& fabrica) {
    auto a = fabrica.crearProductoA();
    auto b = fabrica.crearProductoB();

    a->operacionA();
    b->operacionB();
}

int main() {
    FabricaFamiliaA fabricaA;
    FabricaFamiliaB fabricaB;

    cliente(fabricaA);
    cliente(fabricaB);
}