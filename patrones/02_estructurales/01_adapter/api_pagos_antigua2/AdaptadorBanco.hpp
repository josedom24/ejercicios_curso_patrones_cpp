#pragma once
#include <memory>
#include <utility>
#include <string>
#include "Procesador.hpp"
#include "ApiBanco.hpp"

// ----------------------------------------
// Nuevo adaptador para la API bancaria
// ----------------------------------------
class AdaptadorPagoBanco : public ProcesadorPago {
private:
    std::string iban_destino_;
    std::unique_ptr<ApiPagoBanco> api_;

public:
    explicit AdaptadorPagoBanco(std::string iban, std::unique_ptr<ApiPagoBanco> api)
        : iban_destino_(std::move(iban)), api_(std::move(api)) {}

    void pagar(double cantidad) const override {
        // Traducción de la interfaz moderna hacia la interfaz bancaria
        api_->realizar_transferencia(cantidad, iban_destino_);
    }
};