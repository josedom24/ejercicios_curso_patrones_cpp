#include "Director.hpp"
#include <iostream>

int main() {
    std::cout << "=== Builder CON Director ===\n";

    ConstructorSolicitudConcreto ctor;
    DirectorSolicitud director(ctor);

    // Solicitud GET simple (sin timeout)
    auto sol1 = director.construir_get_simple("https://ejemplo.com");
    sol1->mostrar();

    // Solicitud POST con JSON y timeout (NUEVO)
    ctor.reiniciar();
    ctor.establecer_metodo("POST");
    ctor.establecer_url("https://api.ejemplo.com/datos");
    ctor.agregar_cabecera("Content-Type", "application/json");
    ctor.establecer_cuerpo("{\"dato\": 123}");
    ctor.establecer_timeout(5000);               // ← NUEVO
    auto sol_timeout = ctor.obtener_solicitud();
    sol_timeout->mostrar();

    std::cout << "\n=== Builder SIN Director (fluido) ===\n";

    // Solicitud PUT con timeout (NUEVO)
    auto sol2 =
        ConstructorSolicitudFluido{}
            .metodo("PUT")
            .url("https://api.ejemplo.com/usuario/42")
            .cabecera("Authorization", "Bearer token123")
            .cuerpo("{\"nombre\": \"Juan\"}")
            .timeout(3000)                       // ← NUEVO
            .construir();

    sol2->mostrar();

    return 0;
}