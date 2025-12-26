#include <iostream>
#include <string>

// ----------------------------------------
// Subsistemas internos
// ----------------------------------------

class SubsistemaA {
public:
    void inicializar() const {
        std::cout << "[A] Inicializando recursos...\n";
    }
    void procesar() const {
        std::cout << "[A] Procesando datos.\n";
    }
};

class SubsistemaB {
public:
    void cargar_configuracion() const {
        std::cout << "[B] Cargando configuración.\n";
    }
    void validar() const {
        std::cout << "[B] Validando parámetros.\n";
    }
};

class SubsistemaC {
public:
    void ejecutar_tarea() const {
        std::cout << "[C] Ejecutando tarea principal.\n";
    }
    void limpiar() const {
        std::cout << "[C] Limpiando recursos.\n";
    }
};

// ----------------------------------------
// Clase Fachada
// ----------------------------------------

class FachadaSistema {
private:
    SubsistemaA a_;
    SubsistemaB b_;
    SubsistemaC c_;

public:
    FachadaSistema() = default;

    // Operación de alto nivel
    void operacion_principal() const {
        std::cout << "=== Iniciando operación principal ===\n";
        a_.inicializar();
        b_.cargar_configuracion();
        b_.validar();
        a_.procesar();
        c_.ejecutar_tarea();
        c_.limpiar();
        std::cout << "=== Operación completada ===\n";
    }

    // Otra operación simplificada
    void operacion_rapida() const {
        std::cout << "=== Operación rápida ===\n";
        a_.procesar();
        c_.ejecutar_tarea();
    }
};

// ----------------------------------------
// Código cliente
// ----------------------------------------

int main() {
    FachadaSistema sistema;

    sistema.operacion_principal();
    std::cout << "\n";
    sistema.operacion_rapida();

    return 0;
}