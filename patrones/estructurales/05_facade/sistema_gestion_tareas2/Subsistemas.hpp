#pragma once
#include <iostream>
#include <string>
#include <vector>

// ----------------------------------------
// Subsistema A: Validación de tareas
// ----------------------------------------
class ValidadorTareas {
public:
    bool validar_creacion(const std::string& nombre) const {
        if (nombre.empty()) {
            std::cout << "[Validador] Error: el nombre no puede estar vacío.\n";
            return false;
        }
        std::cout << "[Validador] Tarea válida.\n";
        return true;
    }

    bool validar_completado(int id) const {
        std::cout << "[Validador] Validando id " << id << "...\n";
        return id >= 0;
    }
};

// ----------------------------------------
// Subsistema B: Almacenamiento
// ----------------------------------------
class AlmacenTareas {
private:
    std::vector<std::string> tareas_;

public:
    int guardar(const std::string& nombre) {
        tareas_.push_back(nombre);
        std::cout << "[Almacén] Tarea '" << nombre << "' guardada.\n";
        return static_cast<int>(tareas_.size() - 1);
    }

    void completar(int id) {
        if (id >= 0 && id < static_cast<int>(tareas_.size())) {
            std::cout << "[Almacén] Tarea '" << tareas_[id] 
                      << "' marcada como completada.\n";
        }
    }

    std::size_t total() const {
        return tareas_.size();
    }
};

// ----------------------------------------
// Subsistema C: Notificaciones
// ----------------------------------------
class Notificador {
public:
    void enviar(const std::string& mensaje) const {
        std::cout << "[Notificador] Enviando notificación: " 
                  << mensaje << "\n";
    }
};

// ----------------------------------------
// NUEVO subsistema D: Registro Histórico
// ----------------------------------------
class RegistroHistorico {
public:
    void registrar(const std::string& evento) {
        std::cout << "[Histórico] " << evento << "\n";
    }
};