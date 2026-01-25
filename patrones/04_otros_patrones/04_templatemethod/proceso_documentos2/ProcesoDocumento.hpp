#pragma once
#include <functional>
#include <string>

class ProcesoDocumento {
private:
    std::function<std::string()> leer_;
    std::function<void(const std::string&)> procesar_;

public:
    ProcesoDocumento(std::function<std::string()> leer,
                     std::function<void(const std::string&)> procesar);

    void ejecutar() const;

private:
    void abrir() const;
    void cerrar() const;
};