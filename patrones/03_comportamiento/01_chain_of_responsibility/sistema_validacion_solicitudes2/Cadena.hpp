#pragma once
#include <memory>
#include "Manejadores.hpp"

// Construye una cadena: Autenticación -> Permisos -> Formato
std::unique_ptr<Manejador> construir_cadena_basica();

// Construye una cadena: Autenticación -> Permisos -> Contenido -> Formato
std::unique_ptr<Manejador> construir_cadena_con_contenido();
