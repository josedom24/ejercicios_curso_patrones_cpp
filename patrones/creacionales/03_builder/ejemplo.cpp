#include <iostream>
#include <memory>

// =====================================================
//                 Producto
// =====================================================

class Producto {
public:
    void establecer_parteA(const std::string& valor) { parteA_ = valor; }
    void establecer_parteB(const std::string& valor) { parteB_ = valor; }

    void mostrar() const {
        std::cout << "Producto: A=" << parteA_
                  << ", B=" << parteB_ << "\n";
    }

private:
    std::string parteA_;
    std::string parteB_;
};

// =====================================================
//                 Builder abstracto
// =====================================================

class Constructor {
public:
    virtual ~Constructor() = default;

    virtual void reiniciar() = 0;
    virtual void establecer_parteA() = 0;
    virtual void establecer_parteB() = 0;
    virtual std::unique_ptr<Producto> obtener_producto() = 0;
};

// =====================================================
//                 Builder concreto
// =====================================================

class ConstructorConcreto : public Constructor {
public:
    ConstructorConcreto() { reiniciar(); }

    void reiniciar() override {
        producto_ = std::make_unique<Producto>();
    }

    void establecer_parteA() override {
        producto_->establecer_parteA("Valor A estándar");
    }

    void establecer_parteB() override {
        producto_->establecer_parteB("Valor B estándar");
    }

    std::unique_ptr<Producto> obtener_producto() override {
        return std::move(producto_);
    }

private:
    std::unique_ptr<Producto> producto_;
};

// =====================================================
//                     Director
// =====================================================

class Director {
public:
    explicit Director(Constructor& ctor) : ctor_(ctor) {}

    std::unique_ptr<Producto> construir_minimo() {
        ctor_.reiniciar();
        ctor_.establecer_parteA();
        return ctor_.obtener_producto();
    }

    std::unique_ptr<Producto> construir_completo() {
        ctor_.reiniciar();
        ctor_.establecer_parteA();
        ctor_.establecer_parteB();
        return ctor_.obtener_producto();
    }

private:
    Constructor& ctor_;
};

// =====================================================
//                     Cliente
// =====================================================

int main() {
    ConstructorConcreto ctor;
    Director director(ctor);

    auto p1 = director.construir_minimo();
    p1->mostrar();

    auto p2 = director.construir_completo();
    p2->mostrar();
}