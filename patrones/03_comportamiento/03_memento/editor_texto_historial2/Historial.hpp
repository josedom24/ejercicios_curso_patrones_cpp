#pragma once
#include <vector>
#include <memory>
#include "Memento.hpp"

// ------------------------------------------------------------
// Clase Cuidador: Historial de estados
// ------------------------------------------------------------
class Historial {
private:
    std::vector<std::unique_ptr<Memento>> historial_;

public:
    void guardar(std::unique_ptr<Memento> m) {
        historial_.push_back(std::move(m));
    }

    const Memento* ultimo() const {
        if (historial_.empty()) return nullptr;
        return historial_.back().get();
    }

    void deshacer_ultimo() {
        if (!historial_.empty())
            historial_.pop_back();
    }
};