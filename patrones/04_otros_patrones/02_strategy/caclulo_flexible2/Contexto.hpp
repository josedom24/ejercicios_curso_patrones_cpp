#pragma once
#include <utility>
#include "Estrategias.hpp"

class ContextoCalculo {
private:
    EstrategiaCalculo estrategia_;

public:
    explicit ContextoCalculo(EstrategiaCalculo estrategia)
        : estrategia_(std::move(estrategia)) {}

    void establecer_estrategia(EstrategiaCalculo nueva) {
        estrategia_ = std::move(nueva);
    }

    int ejecutar(int a, int b) const {
        return estrategia_(a, b);
    }
};