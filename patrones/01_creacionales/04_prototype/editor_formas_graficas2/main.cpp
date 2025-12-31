#include "Formas.hpp"

// Función cliente que recibe cualquier forma y la clona
void cliente(const Forma& prototipo) {
    auto copia = prototipo.clonar();
    copia->dibujar();
}

int main() {
    Rectangulo rect(120, 60);
    Circulo circ(40);
    RectanguloConEstilo rectEstilado(100, 50, "rojo"); // NUEVO


    cliente(rect);   // Clona y dibuja un rectángulo
    cliente(circ);   // Clona y dibuja un círculo
    cliente(rectEstilado);   // Clona y dibuja un rectángulo con estilo NUEVO
    return 0;
}