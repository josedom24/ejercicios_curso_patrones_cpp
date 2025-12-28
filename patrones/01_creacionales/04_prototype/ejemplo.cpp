#include <iostream>
#include <memory>
#include <string>

// ----------------------------------------
// Interfaz base del prototipo
// ----------------------------------------
class Prototipo {
public:
    virtual ~Prototipo() = default;

    // Método de clonación
    virtual std::unique_ptr<Prototipo> clone() const = 0;

    virtual void mostrar() const = 0;
};

// ----------------------------------------
// Prototipo concreto A (copia superficial)
// ----------------------------------------
class PrototipoConcretoA : public Prototipo {
public:
    PrototipoConcretoA(std::string nombre, int valor)
        : nombre_(std::move(nombre)), valor_(valor) {}

    std::unique_ptr<Prototipo> clone() const override {
        return std::make_unique<PrototipoConcretoA>(*this); // copia superficial
    }

    void mostrar() const override {
        std::cout << "PrototipoConcretoA { nombre = " << nombre_
                  << ", valor = " << valor_ << " }\n";
    }

private:
    std::string nombre_;
    int valor_;
};

// ----------------------------------------
// Prototipo concreto B (copia profunda)
// ----------------------------------------
class PrototipoConcretoB : public Prototipo {
public:
    PrototipoConcretoB(std::string etiqueta, std::unique_ptr<int> dato)
        : etiqueta_(std::move(etiqueta)), dato_(std::move(dato)) {}

    // Clonación profunda: duplicamos el recurso dinámico
    std::unique_ptr<Prototipo> clone() const override {
        return std::make_unique<PrototipoConcretoB>(
            etiqueta_, std::make_unique<int>(*dato_));
    }

    void mostrar() const override {
        std::cout << "PrototipoConcretoB { etiqueta = " << etiqueta_
                  << ", dato = " << *dato_ << " }\n";
    }

private:
    std::string etiqueta_;
    std::unique_ptr<int> dato_; // requiere copia profunda
};

// ----------------------------------------
// Función cliente
// ----------------------------------------
void cliente(const Prototipo& prototipo) {
    auto copia = prototipo.clone();
    copia->mostrar();
}

int main() {
    PrototipoConcretoA protA("Ejemplo A", 42);
    PrototipoConcretoB protB("Ejemplo B", std::make_unique<int>(100));

    cliente(protA);
    cliente(protB);

    return 0;
}