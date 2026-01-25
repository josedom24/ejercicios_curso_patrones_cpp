#include "ProcesosConcretos.hpp"
#include <iostream>
#include <sstream>

ProcesoDocumento crear_proceso_texto() {
    return ProcesoDocumento(
        []() {
            std::cout << "[Texto] Leyendo texto...\n";
            return std::string("Ejemplo de texto plano.");
        },
        [](const std::string& contenido) {
            std::cout << "[Texto] Procesando contenido: "
                      << contenido << "\n";
        }
    );
}

ProcesoDocumento crear_proceso_csv() {
    return ProcesoDocumento(
        []() {
            std::cout << "[CSV] Leyendo línea CSV...\n";
            return std::string("10,20,30");
        },
        [](const std::string& linea) {
            std::cout << "[CSV] Procesando valores: ";
            std::stringstream ss(linea);
            std::string valor;
            while (std::getline(ss, valor, ',')) {
                std::cout << valor << " ";
            }
            std::cout << "\n";
        }
    );
}

ProcesoDocumento crear_proceso_json() {
    return ProcesoDocumento(
        []() {
            std::cout << "[JSON] Simulando lectura...\n";
            return std::string("{\"clave\":\"valor\"}");
        },
        [](const std::string& contenido) {
            std::cout << "[JSON] Procesando JSON: "
                      << contenido << "\n";
        }
    );
}