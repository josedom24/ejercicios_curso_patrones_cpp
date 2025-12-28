#include <iostream>
#include "Proxy.hpp"

void cliente(ServicioDatos& servicio) {
    std::cout << servicio.obtener_datos("perfil") << "\n";
    std::cout << servicio.obtener_datos("estadisticas") << "\n";

    // Segunda llamada repetida: vendrá de la caché
    std::cout << servicio.obtener_datos("perfil") << "\n";
}

int main() {
    ProxyServicioDatosLogger proxyLogger;
    ProxyServicioDatos proxyAdmin("admin");

    std::cout << "--- Usando Proxy Logger ---\n";
    cliente(proxyLogger);

    std::cout << "\n--- Usando Proxy con control de acceso ---\n";
    cliente(proxyAdmin);

    return 0;
}