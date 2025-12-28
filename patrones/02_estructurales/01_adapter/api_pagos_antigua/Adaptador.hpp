#pragma once
#include <memory>
#include "Procesador.hpp"
#include "ApiAntigua.hpp"

// ----------------------------------------
// Adaptador (Adapter)
// ----------------------------------------
class AdaptadorPago : public ProcesadorPago {
private:
    std::unique_ptr<ApiPagoAntigua> api_;

public:
    explicit AdaptadorPago(std::unique_ptr<ApiPagoAntigua> api)
        : api_(std::move(api)) {}

    void pagar(double cantidad) const override {
        // Traducción de la interfaz moderna a la antigua
        api_->enviar_pago(cantidad);
    }
};