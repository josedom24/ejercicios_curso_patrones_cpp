#include <iostream>
#include "Editor.hpp"
#include "Historial.hpp"

int main() {
    Editor editor("Hola");
    Historial historial;

    editor.mostrar();
    historial.guardar(editor.crear_memento());

    editor.escribir(", mundo");
    editor.cambiar_formato("Courier", 14, "Azul");
    editor.mostrar();

    // Guardamos estado avanzado
    auto m_formato = editor.crear_memento_formato();

    // Cambiamos todo
    editor.escribir("!!!");
    editor.cambiar_formato("Times", 18, "Rojo");
    editor.mostrar();

    // Restauramos estado avanzado
    std::cout << "\nRestaurando estado con formato...\n";
    editor.restaurar(*m_formato);
    editor.mostrar();

    return 0;
}