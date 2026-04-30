#pragma once
#include <iostream>

// ----------------------------------------
// Receptor: dispositivos reales
// ----------------------------------------

class Luz {
public:
    void encender() const {
        std::cout << "Luz: encendida\n";
    }
    void apagar() const {
        std::cout << "Luz: apagada\n";
    }
};

class Persiana {
public:
    void subir() const {
        std::cout << "Persiana: subida\n";
    }
    void bajar() const {
        std::cout << "Persiana: bajada\n";
    }
};

class Ventilador {
public:
    void activar() const {
        std::cout << "Ventilador: activado\n";
    }
    void desactivar() const {
        std::cout << "Ventilador: desactivado\n";
    }
};