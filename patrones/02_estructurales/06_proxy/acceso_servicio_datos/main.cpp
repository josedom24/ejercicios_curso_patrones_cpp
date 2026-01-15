#include <iostream>
#include "Proxy.hpp"

void cliente(ServicioDatos& servicio) {
    try {
        std::cout << servicio.obtener_datos("perfil") << "\n";
        std::cout << servicio.obtener_datos("estadisticas") << "\n";

        // Segunda llamada repetida: vendrá de la caché
        std::cout << servicio.obtener_datos("perfil") << "\n";
    } catch (const std::exception& e) {
        std::cout << "[Cliente] Error: " << e.what() << "\n";
    }
}

int main() {
    ProxyServicioDatos proxyAdmin("admin");
    ProxyServicioDatos proxyInvitado("invitado");

    std::cout << "--- Acceso como 'admin' ---\n";
    cliente(proxyAdmin);

    std::cout << "\n--- Acceso como 'invitado' ---\n";
    cliente(proxyInvitado);

    return 0;
}
