#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include "Servicio.hpp"

// ----------------------------------------
// Proxy con control de acceso, inicialización
// diferida y caché
// ----------------------------------------
class ProxyServicioDatos : public ServicioDatos {
private:
    std::unique_ptr<ServicioDatos> servicio_real_;
    std::unordered_map<std::string, std::string> cache_;
    std::string usuario_;

    bool comprobar_acceso() const {
        return usuario_ == "admin";
    }

public:
    explicit ProxyServicioDatos(std::string usuario)
        : usuario_(std::move(usuario)) {}

    std::string obtener_datos(const std::string& clave) override {
        std::cout << "[Proxy] Solicitud para '" << clave << "'.\n";

        if (!comprobar_acceso()) {
            throw std::runtime_error(
                "Acceso denegado para el usuario '" + usuario_ + "'"
            );
        }

        if (auto it = cache_.find(clave); it != cache_.end()) {
            return "[Proxy] (Caché) " + it->second;
        }

        if (!servicio_real_) {
            std::cout << "[Proxy] Creando ServicioDatosReal bajo demanda...\n";
            servicio_real_ = std::make_unique<ServicioDatosReal>();
        }

        auto resultado = servicio_real_->obtener_datos(clave);
        cache_[clave] = resultado;

        return resultado;
    }
};
