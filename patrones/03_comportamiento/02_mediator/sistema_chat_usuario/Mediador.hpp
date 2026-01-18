#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// ----------------------------------------
// Interfaz del Mediador
// ----------------------------------------
class InterfazMediador {
public:
    virtual ~InterfazMediador() = default;

    virtual void notificar(const std::string& emisor,
                           const std::string& mensaje) = 0;
};

// ----------------------------------------
// Interfaz mínima del Colega
// ----------------------------------------
class InterfazUsuario {
public:
    virtual ~InterfazUsuario() = default;

    virtual std::string nombre() const = 0;
    virtual void recibir(const std::string& emisor,
                         const std::string& mensaje) = 0;
};

// ----------------------------------------
// Mediador Concreto
// ----------------------------------------
class MediadorConcreto : public InterfazMediador {
public:
    void registrar_usuario(const std::shared_ptr<InterfazUsuario>& usuario) {
        usuarios_.push_back(usuario);
    }

    void notificar(const std::string& emisor,
                   const std::string& mensaje) override
    {
        std::cout << "[Mediador] " << emisor
                  << " envía mensaje: " << mensaje << "\n";

        for (auto& u : usuarios_) {
            if (u && u->nombre() != emisor) {
                u->recibir(emisor, mensaje);
            }
        }
    }

private:
    std::vector<std::shared_ptr<InterfazUsuario>> usuarios_;
};