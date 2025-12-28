#include "Elementos.hpp"

int main() {
    // Crear directorio raíz
    auto raiz = std::make_unique<Directorio>("home");

    // Añadir archivos a la raíz
    raiz->agregar(std::make_unique<Archivo>("notas.txt"));
    raiz->agregar(std::make_unique<Archivo>("foto.png"));

    // Crear subdirectorio
    auto documentos = std::make_unique<Directorio>("documentos");
    documentos->agregar(std::make_unique<Archivo>("cv.pdf"));
    documentos->agregar(std::make_unique<Archivo>("proyecto.docx"));

    // Insertar subdirectorio en la raíz
    raiz->agregar(std::move(documentos));

    // Mostrar estructura completa
    raiz->mostrar();

    return 0;
}