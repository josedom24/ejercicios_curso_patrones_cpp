#pragma once
#include "Subsistemas.hpp"

// ----------------------------------------
// Clase Fachada: interfaz simplificada
// ----------------------------------------
class GestorTareas {
private:
    ValidadorTareas validador_;
    AlmacenTareas almacen_;
    Notificador notificador_;
    RegistroHistorico historico_;   // NUEVO miembro

public:
    // Operación de alto nivel: creación de tarea
    void crear_tarea(const std::string& nombre) {
        std::cout << "=== Creación de tarea ===\n";
        if (!validador_.validar_creacion(nombre)) {
            return;
        }
        int id = almacen_.guardar(nombre);
        notificador_.enviar("Nueva tarea creada con id " + std::to_string(id));
        historico_.registrar("Tarea creada: " + nombre); // NUEVA tarea
    }

    // Operación de alto nivel: completar una tarea
    void completar_tarea(int id) {
        std::cout << "=== Completando tarea ===\n";
        if (!validador_.validar_completado(id)) {
            return;
        }
        almacen_.completar(id);
        notificador_.enviar("La tarea " + std::to_string(id) + " ha sido completada.");
    }

    // Operación de alto nivel: resumen del sistema
    void mostrar_resumen() const {
        std::cout << "=== Resumen del sistema ===\n";
        std::cout << "Total de tareas: " << almacen_.total() << "\n";
        notificador_.enviar("Resumen consultado.");
    }
};