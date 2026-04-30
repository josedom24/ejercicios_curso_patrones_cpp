#include "Logger.hpp"

// ----------------------------
// Funciones que utilizan el logger
// ----------------------------

void inicializar() {
    SingletonLogger::instance().log("Iniciando el sistema...");
}

void procesar() {
    SingletonLogger::instance().warning("El rendimiento está por debajo del esperado.");
}

void finalizar() {
    SingletonLogger::instance().error("Finalización inesperada detectada.");
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