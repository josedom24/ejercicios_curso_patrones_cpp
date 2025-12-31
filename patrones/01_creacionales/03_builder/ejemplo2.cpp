#include <iostream>
#include <memory>
#include <string>

// =====================================================
//                 Producto
// =====================================================

class Producto {
public:
    Producto(const std::string& a, const std::string& b)
        : parteA_(a), parteB_(b) {}

    void mostrar() const {
        std::cout << "Producto: A=" << parteA_
                  << ", B=" << parteB_ << "\n";
    }

private:
    std::string parteA_;
    std::string parteB_;
};

// =====================================================
//                 Builder concreto (fluido)
// =====================================================

class ConstructorFluido {
public:
    ConstructorFluido& parteA(const std::string& valor) {
        parteA_ = valor;
        return *this;
    }

    ConstructorFluido& parteB(const std::string& valor) {
        parteB_ = valor;
        return *this;
    }

    std::unique_ptr<Producto> construir() const {
        return std::make_unique<Producto>(parteA_, parteB_);
    }

private:
    std::string parteA_ = "A por defecto";
    std::string parteB_ = "B por defecto";
};

// =====================================================
//                     Cliente
// =====================================================

int main() {
    auto p = ConstructorFluido{}
                .parteA("A personalizada")
                .parteB("B personalizada")
                .construir();

    p->mostrar();
}
