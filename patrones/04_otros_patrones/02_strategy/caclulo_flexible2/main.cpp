#include <iostream>
#include "Contexto.hpp"

void cliente(ContextoCalculo& contexto) {
    std::cout << "Resultado: "
              << contexto.ejecutar(3, 4)
              << "\n";
}

int main() {
    // Contexto con estrategia de suma
    ContextoCalculo contexto(estrategia_suma());
    cliente(contexto);

    // Cambiar estrategia a producto
    contexto.establecer_estrategia(estrategia_producto());
    cliente(contexto);

    // Cambiar estrategia a potencia
    contexto.establecer_estrategia(estrategia_potencia());
    cliente(contexto);
    
    // Nueva estrategia
    contexto.establecer_estrategia(estrategia_modulo());
    cliente(contexto);

    return 0;
}