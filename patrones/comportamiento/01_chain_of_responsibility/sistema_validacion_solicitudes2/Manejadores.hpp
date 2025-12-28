#pragma once
#include <iostream>
#include <memory>
#include <string>

// ----------------------------------------
// Interfaz base del manejador
// ----------------------------------------
class Manejador {
public:
    virtual ~Manejador() = default;

    void establecer_siguiente(std::unique_ptr<Manejador> siguiente) {
        siguiente_ = std::move(siguiente);
    }

    void manejar(const std::string& solicitud) const {
        if (!procesar(solicitud) && siguiente_) {
            siguiente_->manejar(solicitud);
        }
    }

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
    bool procesar(const std::string& solicitud) const override {
        if (solicitud == "token-invalido") {
            std::cout << "Autenticación fallida.\n";
            return true;
        }
        return false;
    }
};

class ValidadorPermisos : public Manejador {
protected:
    bool procesar(const std::string& solicitud) const override {
        if (solicitud == "sin-permisos") {
            std::cout << "Permisos insuficientes.\n";
            return true;
        }
        return false;
    }
};

class ValidadorFormato : public Manejador {
protected:
    bool procesar(const std::string& solicitud) const override {
        if (solicitud.empty()) {
            std::cout << "Formato inválido: solicitud vacía.\n";
            return true;
        }
        return false;
    }
};

// ----------------------------------------
// Nuevo Manejadores concretos
// Validador que comprueba contenido prohibido
// ----------------------------------------

class ValidadorContenido : public Manejador {
protected:
    bool procesar(const std::string& solicitud) const override {
        if (solicitud.find("prohibido") != std::string::npos) {
            std::cout << "Contenido prohibido detectado.\n";
            return true;
        }
        return false;
    }
};