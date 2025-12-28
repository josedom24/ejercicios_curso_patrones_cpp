#include <iostream>
#include <memory>
#include <string>
#include <vector>

// ------------------------------------------------------------
// Clase Memento
// ------------------------------------------------------------
class Memento {
private:
    std::string estado_;

    // Solo el Originador puede construir mementos
    friend class Originador;

    explicit Memento(std::string estado)
        : estado_(std::move(estado)) {}

public:
    // No se exponen getters públicos para mantener encapsulación
};

// ------------------------------------------------------------
// Clase Originador (crea y restaura mementos)
// ------------------------------------------------------------
class Originador {
private:
    std::string estado_;

public:
    explicit Originador(std::string estado_inicial)
        : estado_(std::move(estado_inicial)) {}

    void establecer_estado(std::string nuevo_estado) {
        estado_ = std::move(nuevo_estado);
    }

    void mostrar_estado() const {
        std::cout << "Estado actual: " << estado_ << "\n";
    }

    // Crear un memento con el estado actual
    std::unique_ptr<Memento> crear_memento() const {
        return std::unique_ptr<Memento>(new Memento(estado_));
    }

    // Restaurar el estado desde un memento
    void restaurar_desde(const Memento& m) {
        estado_ = m.estado_;
    }
};

// ------------------------------------------------------------
// Clase Cuidador (gestiona los mementos)
// ------------------------------------------------------------
class Cuidador {
private:
    std::vector<std::unique_ptr<Memento>> historial_;

public:
    void guardar(std::unique_ptr<Memento> m) {
        historial_.push_back(std::move(m));
    }

    const Memento* obtener(std::size_t indice) const {
        if (indice < historial_.size())
            return historial_[indice].get();
        return nullptr;
    }
};

// ------------------------------------------------------------
// Código cliente
// ------------------------------------------------------------
int main() {
    Originador originador{"Estado inicial"};
    Cuidador cuidador;

    originador.mostrar_estado();

    // Guardamos un memento
    cuidador.guardar(originador.crear_memento());

    // Cambiamos estado
    originador.establecer_estado("Estado modificado");
    originador.mostrar_estado();

    // Restauramos estado previo
    if (const Memento* m = cuidador.obtener(0)) {
        originador.restaurar_desde(*m);
    }

    originador.mostrar_estado();

    return 0;
}