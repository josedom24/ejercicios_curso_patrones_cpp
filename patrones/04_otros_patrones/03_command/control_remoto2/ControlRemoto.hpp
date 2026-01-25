#pragma once
#include <functional>
#include <iostream>
#include <utility>

// ----------------------------------------
// Invocador moderno: almacena comportamientos
// ----------------------------------------

class ControlRemoto {
private:
    std::function<void()> accion_;

public:
    void asignar_accion(std::function<void()> f) {
        accion_ = std::move(f);
    }

    void pulsar_boton() const {
        if (accion_) {
            accion_();
        } else {
            std::cout << "ControlRemoto: no hay acción asignada.\n";
        }
    }
};