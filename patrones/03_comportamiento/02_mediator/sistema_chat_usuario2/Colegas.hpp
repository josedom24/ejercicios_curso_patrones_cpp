#pragma once
#include "Mediador.hpp"
#include <iostream>
#include <memory>
#include <string>

// ----------------------------------------
// Clase base: Usuario (Colega)
// ----------------------------------------
class Usuario : public InterfazUsuario {
public:
    virtual ~Usuario() = default;

    void establecer_mediador(std::weak_ptr<InterfazMediador> mediador) {
        mediador_ = mediador;
    }

    void enviar(const std::string& mensaje) {
        if (auto m = mediador_.lock()) {
            m->notificar(nombre(), mensaje);
        }
    }

protected:
    virtual std::string nombre() const = 0;

private:
    std::weak_ptr<InterfazMediador> mediador_;
};

// ----------------------------------------
// Usuario Regular
// ----------------------------------------
class UsuarioRegular : public Usuario {
public:
    explicit UsuarioRegular(std::string id)
        : id_(std::move(id)) {}

    void recibir(const std::string& emisor,
                 const std::string& mensaje) override
    {
        if (emisor != id_) {
            std::cout << "[" << id_ << "] recibe: "
                      << mensaje << " (de " << emisor << ")\n";
        }
    }

protected:
    std::string nombre() const override {
        return id_;
    }

private:
    std::string id_;
};

// ----------------------------------------
// Usuario Administrador
// ----------------------------------------
class UsuarioAdministrador : public Usuario {
public:
    explicit UsuarioAdministrador(std::string id)
        : id_(std::move(id)) {}

    void recibir(const std::string& emisor,
                 const std::string& mensaje) override
    {
        if (emisor != id_) {
            std::cout << "[ADMIN " << id_ << "] recibe: "
                      << mensaje << " (de " << emisor << ")\n";
        }
    }

protected:
    std::string nombre() const override {
        return id_;
    }

private:
    std::string id_;
};


// ----------------------------------------
// Usuario Premium
// ----------------------------------------
class UsuarioPremium : public Usuario {
public:
    explicit UsuarioPremium(std::string id)
        : id_(std::move(id)) {}

    void recibir(const std::string& emisor,
                 const std::string& mensaje) override
    {
        if (emisor != id_) {
            std::cout << "[Premium " << id_
                      << "] recibe mensaje PRIORITARIO: "
                      << mensaje << " (de " << emisor << ")\n";
        }
    }

protected:
    std::string nombre() const override {
        return id_;
    }

private:
    std::string id_;
};