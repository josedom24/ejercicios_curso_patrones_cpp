#include "Fachada.hpp"

int main() {
    GestorTareas gestor;

    gestor.crear_tarea("Aprender C++");
    gestor.crear_tarea("Preparar presentación");
    gestor.completar_tarea(0);
    gestor.mostrar_resumen();

    return 0;
}