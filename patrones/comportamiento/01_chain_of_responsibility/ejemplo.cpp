#include <iostream>
#include <memory>
#include <string>

// ----------------------------------------
// Interfaz base del manejador
// ----------------------------------------
class Manejador {
public:
    virtual ~Manejador() = default;

    void establecer_siguiente(std::unique_ptr<Manejador> siguiente) {
        siguiente_ = std::move(siguiente);
    }

    void manejar(const std::string& peticion) const {
        if (!procesar(peticion) && siguiente_) {
            siguiente_->manejar(peticion);
        }
    }

protected:
    virtual bool procesar(const std::string& peticion) const = 0;

private:
    std::unique_ptr<Manejador> siguiente_;
};

// ----------------------------------------
// Manejador concreto A
// ----------------------------------------
class ManejadorConcretoA : public Manejador {
protected:
    bool procesar(const std::string& peticion) const override {
        if (peticion == "A") {
            std::cout << "ManejadorConcretoA procesó la petición.\n";
            return true;
        }
        return false;
    }
};

// Manejador concreto B
class ManejadorConcretoB : public Manejador {
protected:
    bool procesar(const std::string& peticion) const override {
        if (peticion == "B") {
            std::cout << "ManejadorConcretoB procesó la petición.\n";
            return true;
        }
        return false;
    }
};

// ----------------------------------------
// Código cliente
// ----------------------------------------
void cliente(const Manejador& manejador) {
    for (const auto& valor : {"A", "B", "C"}) {
        std::cout << "Enviando petición: " << valor << "\n";
        manejador.manejar(valor);
    }
}

int main() {
    // Construcción de la cadena
    auto manejadorA = std::make_unique<ManejadorConcretoA>();
    auto manejadorB = std::make_unique<ManejadorConcretoB>();

    // Encadenamiento: A -> B
    manejadorA->establecer_siguiente(std::move(manejadorB));

    // Uso del cliente
    cliente(*manejadorA);

    return 0;
}