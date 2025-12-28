#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include "Servicio.hpp"

// ----------------------------------------
// Proxy que controla acceso, inicializa el servicio
// bajo demanda y mantiene una pequeña caché
// ----------------------------------------
class ProxyServicioDatos : public ServicioDatos {
private:
    std::unique_ptr<ServicioDatosReal> servicio_real_;
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
            return "[Proxy] Acceso denegado para el usuario '" + usuario_ + "'";
        }

        if (cache_.find(clave) != cache_.end()) {
           return "[Proxy] (Caché) " + cache_[clave];
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