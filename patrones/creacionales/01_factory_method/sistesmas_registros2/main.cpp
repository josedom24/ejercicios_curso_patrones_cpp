#include "Creadores.hpp"

void cliente(const CreadorLogger& fabrica) {
    fabrica.registrar("Mensaje de prueba");
}

int main() {
    CreadorLoggerConsola fabricaConsola;
    CreadorLoggerArchivo fabricaArchivo("log.txt");
    CreadorLoggerRed fabricaRed;
    CreadorLoggerBD fabricaBD;         // <-- NUEVO

    cliente(fabricaConsola);
    cliente(fabricaArchivo);
    cliente(fabricaRed);
    cliente(fabricaBD);                // <-- NUEVO

    return 0;
}