#pragma once
#include <memory>
#include <string>

// ----------------------------------------
// Interfaz base del manejador
// ----------------------------------------
class Manejador {
public:
    virtual ~Manejador() = default;

    void establecer_siguiente(std::unique_ptr<Manejador> siguiente);
    void manejar(const std::string& solicitud) const;

protected:
    virtual bool procesar(const std::string& solicitud) const = 0;

private:
    std::unique_ptr<Manejador> siguiente_;
};

// ----------------------------------------
// Manejadores concretos
// ----------------------------------------
class ValidadorAutenticacion : public Manejador {
protected:
    bool procesar(const std::string& solicitud) const override;
};

class ValidadorPermisos : public Manejador {
protected:
    bool procesar(const std::string& solicitud) const override;
};

class ValidadorFormato : public Manejador {
protected:
    bool procesar(const std::string& solicitud) const override;
};