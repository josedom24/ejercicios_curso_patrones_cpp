#include "Creadores.hpp"

void cliente(const CreadorLogger& fabrica) {
    auto logger = fabrica.crear_logger();   // creación delegada
    logger->log("Mensaje de prueba");        // uso explícito del producto
}

int main() {
    CreadorLoggerConsola fabricaConsola;
    CreadorLoggerArchivo fabricaArchivo("log.txt");
    CreadorLoggerRed fabricaRed;
    CreadorLoggerBD fabricaBD;  //NUEVO

    cliente(fabricaConsola);
    cliente(fabricaArchivo);
    cliente(fabricaRed);
    cliente(fabricaBD); //NUEVO

    return 0;
}