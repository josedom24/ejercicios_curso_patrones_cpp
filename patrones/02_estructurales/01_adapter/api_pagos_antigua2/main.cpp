#include <memory>
#include "Adaptador.hpp"
#include "AdaptadorBanco.hpp"

void cliente(const ProcesadorPago& procesador) {
    procesador.pagar(42.50);
}

int main() {
    auto api_antigua = std::make_unique<ApiPagoAntigua>();
    auto adaptador_antiguo = std::make_unique<AdaptadorPago>(std::move(api_antigua));

    auto api_banco = std::make_unique<ApiPagoBanco>();
    auto adaptador_banco = std::make_unique<AdaptadorPagoBanco>(
        "ES9820385778983000760236", 
        std::move(api_banco)
    );

    cliente(*adaptador_antiguo); // API antigua adaptada
    cliente(*adaptador_banco);   // Nueva API bancaria adaptada

    return 0;
}