#include "Formas.hpp"

// Función cliente que recibe cualquier forma y la clona
void cliente(const Forma& prototipo) {
    auto copia = prototipo.clonar();
    copia->dibujar();
}

int main() {
    Rectangulo rect(120, 60);
    Circulo circ(40);

    cliente(rect);   // Clona y dibuja un rectángulo
    cliente(circ);   // Clona y dibuja un círculo

    return 0;
}