#pragma once
#include <functional>
#include <iostream>
#include <utility>

// ----------------------------------------
// Invocador moderno: almacena comportamientos
// ----------------------------------------

class ControlRemoto {
private:
    std::function<void()> boton1_;
    std::function<void()> boton2_;

public:
    void asignar_boton1(std::function<void()> f) {
        boton1_ = std::move(f);
    }

    void asignar_boton2(std::function<void()> f) {
        boton2_ = std::move(f);
    }

    void pulsar_boton1() const {
        if (boton1_) {
            boton1_();
        } else {
            std::cout << "Botón 1: sin acción asignada.\n";
        }
    }

    void pulsar_boton2() const {
        if (boton2_) {
            boton2_();
        } else {
            std::cout << "Botón 2: sin acción asignada.\n";
        }
    }
};