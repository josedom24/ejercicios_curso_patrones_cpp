#pragma once
#include <memory>
#include "Builder.hpp"

// ======================================================
//                   Director
// ======================================================

class DirectorSolicitud {
public:
    explicit DirectorSolicitud(ConstructorSolicitud& builder)
        : builder_(builder) {}

    // Construcción mínima: GET sin cuerpo
    std::unique_ptr<SolicitudHTTP> construir_get_simple(const std::string& url) {
        builder_.reiniciar();
        builder_.establecer_metodo("GET");
        builder_.establecer_url(url);
        return builder_.obtener_solicitud();
    }

    // Construcción completa: POST con JSON
    std::unique_ptr<SolicitudHTTP>
    construir_post_json(const std::string& url,
                        const std::string& cuerpo_json) {
        builder_.reiniciar();
        builder_.establecer_metodo("POST");
        builder_.establecer_url(url);
        builder_.agregar_cabecera("Content-Type", "application/json");
        builder_.establecer_cuerpo(cuerpo_json);
        return builder_.obtener_solicitud();
    }

private:
    ConstructorSolicitud& builder_;
};