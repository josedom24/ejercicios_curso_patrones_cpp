#include "Cadena.hpp"

void cliente(const Manejador& manejador) {
    manejador.manejar("token-invalido");
    manejador.manejar("sin-permisos");
    manejador.manejar("");
    manejador.manejar("solicitud-correcta");
}

int main() {
    auto cadena = construir_cadena_basica();
    cliente(*cadena);
    return 0;
}