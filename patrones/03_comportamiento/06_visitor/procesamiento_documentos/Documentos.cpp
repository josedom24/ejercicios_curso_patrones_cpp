#include "Documentos.hpp"
#include "Visitantes.hpp"

// ----------------------------------------
// Constructores
// ----------------------------------------
Factura::Factura(std::string cliente, double importe)
    : cliente(std::move(cliente)), importe(importe) {}

Informe::Informe(std::string titulo, int paginas)
    : titulo(std::move(titulo)), paginas(paginas) {}

// ----------------------------------------
// Double dispatch
// ----------------------------------------
void Factura::accept(Visitante& v) {
    v.visitar(*this);
}

void Informe::accept(Visitante& v) {
    v.visitar(*this);
}

// ----------------------------------------
// Getters
// ----------------------------------------
const std::string& Factura::getCliente() const {
    return cliente;
}

double Factura::getImporte() const {
    return importe;
}

const std::string& Informe::getTitulo() const {
    return titulo;
}

int Informe::getPaginas() const {
    return paginas;
}