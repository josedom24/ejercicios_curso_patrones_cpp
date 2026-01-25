#pragma once
#include "ProcesoDocumento.hpp"

// Funciones factoría que configuran distintos procesos
ProcesoDocumento crear_proceso_texto();
ProcesoDocumento crear_proceso_csv();
ProcesoDocumento crear_proceso_json();
// NUEVO
ProcesoDocumento crear_proceso_xml();