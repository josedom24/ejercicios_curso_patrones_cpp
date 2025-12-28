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
        "{\"usuario\": \"admin\", \"clave\": \"1234\"}"
    );
    sol2->mostrar();

    std::cout << "\n=== Builder SIN Director (fluido) ===\n";

    auto sol3 =
        ConstructorSolicitudFluido{}
            .metodo("PUT")
            .url("https://api.ejemplo.com/usuario/42")
            .cabecera("Authorization", "Bearer token123")
            .cuerpo(R"({"nombre": "Juan"})")
            .construir();

    sol3->mostrar();

    return 0;
}