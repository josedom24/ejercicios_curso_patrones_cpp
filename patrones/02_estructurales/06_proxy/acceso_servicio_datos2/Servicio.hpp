#pragma once
#include <iostream>
#include <string>

// ----------------------------------------
// Interfaz base del servicio
// ----------------------------------------
class ServicioDatos {
public:
    virtual ~ServicioDatos() = default;
    virtual std::string obtener_datos(const std::string& clave) = 0;
};

// ----------------------------------------
// Servicio real, costoso o protegido
// ----------------------------------------
class ServicioDatosReal : public ServicioDatos {
public:
    ServicioDatosReal() {
        std::cout << "[ServicioDatosReal] Inicializando recursos pesados...\n";
    }

    std::string obtener_datos(const std::string& clave) override {
        return "Datos reales para '" + clave + "'";
    }
};
