#include "Formas.hpp"

// Función cliente que recibe cualquier forma y la clona
void cliente(const Forma& prototipo) {
    auto copia = prototipo.clonar();
    copia->dibujar();
}

int main() {
    Rectangulo rect(120, 60);
    Circulo circ(40);
    Triangulo tri(50, 80); // NUEVO


    cliente(rect);   // Clona y dibuja un rectángulo
    cliente(circ);   // Clona y dibuja un círculo
    cliente(tri);    // Clona y dibuja un triángulo NUEVO
    return 0;
}