#include "Director.hpp"
#include <iostream>

int main() {
    std::cout << "=== Builder CON Director ===\n";

    ConstructorSolicitudConcreto ctor;
    DirectorSolicitud director(ctor);

    auto sol1 = director.construir_get_simple("https://ejemplo.com");
    sol1->mostrar();

    auto sol2 = director.construir_post_json(
        "https://api.ejemplo.com/login",
        R"({"usuario": "admin", "clave": "1234"})"
    );
    sol2->mostrar();


    std::cout << "\n=== Builder SIN Director (fluido) ===\n";

    // El builder fluido devuelve std::unique_ptr<SolicitudHTTP>
    auto sol3 =
        ConstructorSolicitudFluido{}
            .metodo("PUT")
            .url("https://api.ejemplo.com/usuario/42")
            .cabecera("Authorization", "Bearer token123")
            .cuerpo(R"({"nombre": "Juan"})")
            .construir();       // <-- ahora devuelve unique_ptr

    sol3->mostrar();

    return 0;
}
