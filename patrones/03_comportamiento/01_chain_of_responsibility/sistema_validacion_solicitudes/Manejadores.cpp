#include <iostream>
#include "Manejadores.hpp"

// ----------------------------------------
// Implementación de Manejador
// ----------------------------------------
void Manejador::establecer_siguiente(std::unique_ptr<Manejador> siguiente) {
    siguiente_ = std::move(siguiente);
}

void Manejador::manejar(const std::string& solicitud) const {
    if (!procesar(solicitud) && siguiente_) {
        siguiente_->manejar(solicitud);
    }
}

// ----------------------------------------
// Manejadores concretos
// ----------------------------------------
bool ValidadorAutenticacion::procesar(const std::string& solicitud) const {
    if (solicitud == "token-invalido") {
        std::cout << "Autenticación fallida.\n";
        return true;
    }
    return false;
}

bool ValidadorPermisos::procesar(const std::string& solicitud) const {
    if (solicitud == "sin-permisos") {
        std::cout << "Permisos insuficientes.\n";
        return true;
    }
    return false;
}

bool ValidadorFormato::procesar(const std::string& solicitud) const {
    if (solicitud.empty()) {
        std::cout << "Formato inválido: solicitud vacía.\n";
        return true;
    }
    return false;
}