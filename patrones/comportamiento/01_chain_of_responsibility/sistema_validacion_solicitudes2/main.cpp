#include "Cadena.hpp"

void cliente(const Manejador& manejador) {
    manejador.manejar("token-invalido");
    manejador.manejar("sin-permisos");
    manejador.manejar("texto con palabra prohibido dentro");
    manejador.manejar("");
    manejador.manejar("solicitud-correcta");
}

int main() {
    auto cadena = construir_cadena_con_contenido();
    cliente(*cadena);
    return 0;
}
