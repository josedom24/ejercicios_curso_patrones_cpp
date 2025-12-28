#include <iostream>
#include "Editor.hpp"
#include "Historial.hpp"

int main() {
    Editor editor("Hola");
    Historial historial;

    editor.mostrar();
    historial.guardar(editor.crear_memento());

    editor.escribir(", mundo");
    editor.mostrar();
    historial.guardar(editor.crear_memento());

    editor.escribir("!!!");
    editor.mostrar();

    // --- Undo ---
    std::cout << "\nDeshaciendo...\n";
    if (const Memento* m = historial.ultimo()) {
        editor.restaurar(*m);
        historial.deshacer_ultimo();
    }
    editor.mostrar();

    std::cout << "\nDeshaciendo...\n";
    if (const Memento* m = historial.ultimo()) {
        editor.restaurar(*m);
        historial.deshacer_ultimo();
    }
    editor.mostrar();

    return 0;
}