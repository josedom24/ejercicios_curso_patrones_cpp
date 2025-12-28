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

// Construye una cadena: Autenticación -> Permisos -> Contenido -> Formato
inline std::unique_ptr<Manejador> construir_cadena_con_contenido() {
    auto autenticacion = std::make_unique<ValidadorAutenticacion>();
    auto permisos      = std::make_unique<ValidadorPermisos>();
    auto contenido     = std::make_unique<ValidadorContenido>();
    auto formato       = std::make_unique<ValidadorFormato>();

    contenido->establecer_siguiente(std::move(formato)); 
    permisos->establecer_siguiente(std::move(contenido));   
    autenticacion->establecer_siguiente(std::move(permisos));

    return autenticacion;
}