#include "Logger.hpp"

// ----------------------------
// Funciones que utilizan el logger
// ----------------------------

void inicializar(ILogger& logger) {
    logger.log("Iniciando el sistema...");
}

void procesar(ILogger& logger) {
    logger.warning("El rendimiento está por debajo del esperado.");
}

void finalizar(ILogger& logger) {
    logger.error("Finalización inesperada detectada.");
}

// ----------------------------
// Punto central del programa
// ----------------------------

int main() {
    // Única instancia del logger, gestionada explícitamente
    ConsoleLogger logger;

    inicializar(logger);
    procesar(logger);
    finalizar(logger);

    return 0;
}