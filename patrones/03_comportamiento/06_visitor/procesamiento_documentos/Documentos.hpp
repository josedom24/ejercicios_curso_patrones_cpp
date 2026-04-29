#pragma once
#include <string>

// Declaración anticipada
class Visitante;

// ----------------------------------------
// Interfaz base del documento
// ----------------------------------------
class Documento {
public:
    virtual ~Documento() = default;
    virtual void accept(Visitante& v) = 0;
};

// ----------------------------------------
// Documento concreto: Factura
// ----------------------------------------
class Factura : public Documento {
private:
    std::string cliente;
    double importe;

public:
    Factura(std::string cliente, double importe);

    void accept(Visitante& v) override;

    // Métodos específicos
    const std::string& getCliente() const;
    double getImporte() const;
};

// ----------------------------------------
// Documento concreto: Informe
// ----------------------------------------
class Informe : public Documento {
private:
    std::string titulo;
    int paginas;

public:
    Informe(std::string titulo, int paginas);

    void accept(Visitante& v) override;

    // Métodos específicos
    const std::string& getTitulo() const;
    int getPaginas() const;
};