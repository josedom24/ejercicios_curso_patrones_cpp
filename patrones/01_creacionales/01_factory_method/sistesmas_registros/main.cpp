#include "Creadores.hpp"

void cliente(const CreadorLogger& fabrica) {
    fabrica.registrar("Mensaje de prueba");
}

int main() {
    CreadorLoggerConsola fabricaConsola;
    CreadorLoggerArchivo fabricaArchivo("log.txt");
    CreadorLoggerRed fabricaRed;

    cliente(fabricaConsola);
    cliente(fabricaArchivo);
    cliente(fabricaRed);

    return 0;
}