#include "Markdown.hpp"
#include <iostream>

int main() {
    // Línea 1: Título
    std::unique_ptr<Markdown> titulo =
        std::make_unique<TextoMarkdown>("Patrón Decorator");

    titulo = std::make_unique<TituloMarkdown>(std::move(titulo), 1);

    // Línea 2: Texto con formato
    std::unique_ptr<Markdown> texto =
        std::make_unique<TextoMarkdown>("Ejemplo en C++ moderno");

    texto = std::make_unique<NegritaMarkdown>(std::move(texto));
    texto = std::make_unique<CursivaMarkdown>(std::move(texto));
    texto = std::make_unique<ListaMarkdown>(std::move(texto));

    // Salida Markdown
    std::cout << titulo->render() << "\n";
    std::cout << texto->render() << "\n";
}
