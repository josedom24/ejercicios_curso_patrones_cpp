#include <iostream>
#include "ProcesosConcretos.hpp"

int main() {
    auto procTexto = crear_proceso_texto();
    auto procCSV   = crear_proceso_csv();
    auto procJSON  = crear_proceso_json();
    auto procXML   = crear_proceso_xml(); // NUEVO

    std::cout << "=== Proceso Texto ===\n";
    procTexto.ejecutar();

    std::cout << "\n=== Proceso CSV ===\n";
    procCSV.ejecutar();

    std::cout << "\n=== Proceso JSON ===\n";
    procJSON.ejecutar();

    std::cout << "\n=== Proceso XML ===\n"; // NUEVO
    procXML.ejecutar();

    return 0;
}