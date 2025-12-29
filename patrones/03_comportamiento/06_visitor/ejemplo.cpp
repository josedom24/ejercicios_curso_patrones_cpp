#include <iostream>
#include <memory>
#include <vector>

// ----------------------------------------
// Interfaz base del Visitante
// ----------------------------------------
class ElementoA;
class ElementoB;

class Visitante {
public:
    virtual ~Visitante() = default;
    virtual void visitar(ElementoA& elem) = 0;
    virtual void visitar(ElementoB& elem) = 0;
};

// ----------------------------------------
// Interfaz base del Elemento
// ----------------------------------------
class Elemento {
public:
    virtual ~Elemento() = default;
    virtual void accept(Visitante& v) = 0;
};

// ----------------------------------------
// Elementos concretos
// ----------------------------------------
class ElementoA : public Elemento {
public:
    void accept(Visitante& v) override {
        v.visitar(*this); // double dispatch
    }

    void accion_especifica_A() const {
        std::cout << "Acción específica de ElementoA.\n";
    }
};

class ElementoB : public Elemento {
public:
    void accept(Visitante& v) override {
        v.visitar(*this); // double dispatch
    }

    void accion_especifica_B() const {
        std::cout << "Acción específica de ElementoB.\n";
    }
};

// ----------------------------------------
// Visitantes concretos
// ----------------------------------------
class VisitanteConcreto1 : public Visitante {
public:
    void visitar(ElementoA& elem) override {
        std::cout << "VisitanteConcreto1 procesa ElementoA → ";
        elem.accion_especifica_A();
    }

    void visitar(ElementoB& elem) override {
        std::cout << "VisitanteConcreto1 procesa ElementoB → ";
        elem.accion_especifica_B();
    }
};

class VisitanteConcreto2 : public Visitante {
public:
    void visitar(ElementoA& elem) override {
        std::cout << "VisitanteConcreto2 analiza ElementoA.\n";
    }

    void visitar(ElementoB& elem) override {
        std::cout << "VisitanteConcreto2 analiza ElementoB.\n";
    }
};

// ----------------------------------------
// Código cliente
// ----------------------------------------
int main() {
    std::vector<std::unique_ptr<Elemento>> elementos;
    elementos.push_back(std::make_unique<ElementoA>());
    elementos.push_back(std::make_unique<ElementoB>());

    VisitanteConcreto1 v1;
    VisitanteConcreto2 v2;

    std::cout << "--- Aplicando VisitanteConcreto1 ---\n";
    for (auto& e : elementos) {
        e->accept(v1);
    }

    std::cout << "\n--- Aplicando VisitanteConcreto2 ---\n";
    for (auto& e : elementos) {
        e->accept(v2);
    }

    return 0;
}