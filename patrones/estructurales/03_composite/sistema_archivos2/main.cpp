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


    //NUEVO
    auto archivoImportante = std::make_unique<Archivo>("importante.txt");
    auto* ptrArchivoImportante = archivoImportante.get();

    raiz->agregar(std::move(archivoImportante));

    // Crear enlace simbólico al archivo anterior
    raiz->agregar(std::make_unique<Enlace>("link_importante", ptrArchivoImportante));

    // Insertar subdirectorio en la raíz
    raiz->agregar(std::move(documentos));

    // Mostrar estructura completa
    raiz->mostrar();

    return 0;
}