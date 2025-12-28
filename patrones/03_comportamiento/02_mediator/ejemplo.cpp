#include <iostream>
#include <memory>
#include <string>

// ------------------------------------------------------
// Interfaz del Mediador
// ------------------------------------------------------
class InterfazMediador {
public:
    virtual ~InterfazMediador() = default;

    virtual void notificar(const std::string& emisor,
                           const std::string& evento) = 0;
};

// ------------------------------------------------------
// Clase base Colega
// ------------------------------------------------------
class Colega {
public:
    virtual ~Colega() = default;

    void establecer_mediador(std::weak_ptr<InterfazMediador> mediador) {
        mediador_ = mediador;
    }

protected:
    void notificar_mediador(const std::string& evento) {
        if (auto m = mediador_.lock()) {
            m->notificar(nombre(), evento);
        }
    }

    virtual std::string nombre() const = 0;

private:
    std::weak_ptr<InterfazMediador> mediador_;
};

// ------------------------------------------------------
// Colega concreto A
// ------------------------------------------------------
class ColegaConcretoA : public Colega {
public:
    void accionA() {
        std::cout << "A realiza accionA().\n";
        notificar_mediador("accionA");
    }

    void reaccionar() {
        std::cout << "A reacciona a orden del mediador.\n";
    }

private:
    std::string nombre() const override {
        return "ColegaA";
    }
};

// ------------------------------------------------------
// Colega concreto B
// ------------------------------------------------------
class ColegaConcretoB : public Colega {
public:
    void accionB() {
        std::cout << "B realiza accionB().\n";
        notificar_mediador("accionB");
    }

    void reaccionar() {
        std::cout << "B reacciona a orden del mediador.\n";
    }

private:
    std::string nombre() const override {
        return "ColegaB";
    }
};

// ------------------------------------------------------
// Mediador concreto
// ------------------------------------------------------
class MediadorConcreto : public InterfazMediador {
public:
    void registrar_colegaA(std::shared_ptr<ColegaConcretoA> a) {
        colegaA_ = std::move(a);
    }

    void registrar_colegaB(std::shared_ptr<ColegaConcretoB> b) {
        colegaB_ = std::move(b);
    }

    void notificar(const std::string& emisor,
                   const std::string& evento) override
    {
        std::cout << "[Mediador] Evento '" << evento
                  << "' recibido de " << emisor << ".\n";

        if (emisor == "ColegaA" && evento == "accionA") {
            if (colegaB_) {
                std::cout << "[Mediador] -> Indicando a B que reaccione.\n";
                colegaB_->reaccionar();
            }
        }
        else if (emisor == "ColegaB" && evento == "accionB") {
            if (colegaA_) {
                std::cout << "[Mediador] -> Indicando a A que reaccione.\n";
                colegaA_->reaccionar();
            }
        }
    }

private:
    std::shared_ptr<ColegaConcretoA> colegaA_;
    std::shared_ptr<ColegaConcretoB> colegaB_;
};

// ------------------------------------------------------
// Código cliente
// ------------------------------------------------------
int main() {
    auto mediador = std::make_shared<MediadorConcreto>();

    auto colegaA = std::make_shared<ColegaConcretoA>();
    auto colegaB = std::make_shared<ColegaConcretoB>();

    colegaA->establecer_mediador(mediador);
    colegaB->establecer_mediador(mediador);

    mediador->registrar_colegaA(colegaA);
    mediador->registrar_colegaB(colegaB);

    // Interacciones
    colegaA->accionA();
    std::cout << "\n";
    colegaB->accionB();

    return 0;
}
