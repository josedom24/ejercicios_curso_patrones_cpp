#include "Logger.hpp"

// ----------------------------
// Funciones que utilizan el logger
// ----------------------------

void inicializar() {
    ConsoleLogger::instance().log("Iniciando el sistema...");
}

void procesar() {
    ConsoleLogger::instance().warning("El rendimiento está por debajo del esperado.");
}

void finalizar() {
    ConsoleLogger::instance().error("Finalización inesperada detectada.");
}

// ----------------------------
// Punto de entrada
// ----------------------------

int main() {
    inicializar();
    procesar();
    finalizar();

    return 0;
}