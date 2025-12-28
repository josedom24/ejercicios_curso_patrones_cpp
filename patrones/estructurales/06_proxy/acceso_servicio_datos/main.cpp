#include <iostream>
#include "Proxy.hpp"

void cliente(ServicioDatos& servicio) {
    std::cout << servicio.obtener_datos("perfil") << "\n";
    std::cout << servicio.obtener_datos("estadisticas") << "\n";

    // Segunda llamada repetida: vendrá de la caché
    std::cout << servicio.obtener_datos("perfil") << "\n";
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