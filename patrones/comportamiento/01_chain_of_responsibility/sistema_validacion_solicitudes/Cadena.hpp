#pragma once
#include "Manejadores.hpp"

// Construye una cadena: Autenticación -> Permisos -> Formato
inline std::unique_ptr<Manejador> construir_cadena_basica() {
    auto autenticacion = std::make_unique<ValidadorAutenticacion>();
    auto permisos      = std::make_unique<ValidadorPermisos>();
    auto formato       = std::make_unique<ValidadorFormato>();

    permisos->establecer_siguiente(std::move(formato));
    autenticacion->establecer_siguiente(std::move(permisos));

    return autenticacion;
}