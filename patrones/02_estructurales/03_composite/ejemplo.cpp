#include <iostream>
#include <memory>
#include <vector>

// ----------------------------------------
// Interfaz base del componente
// ----------------------------------------
class Componente {
public:
    virtual ~Componente() = default;
    virtual void operar() const = 0;
};

// ----------------------------------------
// Componente hoja
// ----------------------------------------
class Hoja : public Componente {
private:
    std::string nombre_;

public:
    explicit Hoja(std::string nombre)
        : nombre_(std::move(nombre)) {}

    void operar() const override {
        std::cout << "Hoja: " << nombre_ << "\n";
    }
};

// ----------------------------------------
// Componente compuesto
// ----------------------------------------
class Compuesto : public Componente {
private:
    std::string nombre_;
    std::vector<std::unique_ptr<Componente>> hijos_;

public:
    explicit Compuesto(std::string nombre)
        : nombre_(std::move(nombre)) {}

    void agregar(std::unique_ptr<Componente> componente) {
        hijos_.push_back(std::move(componente));
    }

    void operar() const override {
        std::cout << "Compuesto: " << nombre_ << "\n";
        for (const auto& hijo : hijos_) {
            hijo->operar();  // llamada recursiva
        }
    }
};

// ----------------------------------------
// Función cliente
// ----------------------------------------
void cliente(const Componente& componente) {
    componente.operar();
}

// ----------------------------------------
// Ejecución demostrativa
// ----------------------------------------
int main() {
    auto raiz = std::make_unique<Compuesto>("Raíz");

    raiz->agregar(std::make_unique<Hoja>("Hoja A"));
    raiz->agregar(std::make_unique<Hoja>("Hoja B"));

    auto subarbol = std::make_unique<Compuesto>("Subárbol 1");
    subarbol->agregar(std::make_unique<Hoja>("Hoja 1.1"));
    subarbol->agregar(std::make_unique<Hoja>("Hoja 1.2"));

    raiz->agregar(std::move(subarbol));

    cliente(*raiz);

    return 0;
}