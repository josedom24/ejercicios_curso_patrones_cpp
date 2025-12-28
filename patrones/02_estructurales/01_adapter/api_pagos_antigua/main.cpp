#include <memory>
#include "Adaptador.hpp"

void cliente(const ProcesadorPago& procesador) {
    procesador.pagar(42.50);
}

int main() {
    auto api_antigua = std::make_unique<ApiPagoAntigua>();
    auto adaptador = std::make_unique<AdaptadorPago>(std::move(api_antigua));

    cliente(*adaptador);

    return 0;
}