#pragma once
#include "Mediador.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <utility>

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

    std::string nombre() const override {
        return id_;
    }

    void recibir(const std::string& emisor,
                 const std::string& mensaje) override
    {
        std::cout << "[" << id_ << "] recibe: "
                  << mensaje << " (de " << emisor << ")\n";
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

    std::string nombre() const override {
        return id_;
    }

    void recibir(const std::string& emisor,
                 const std::string& mensaje) override
    {
        std::cout << "[ADMIN " << id_ << "] recibe: "
                  << mensaje << " (de " << emisor << ")\n";
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

    std::string nombre() const override {
        return id_;
    }

    void recibir(const std::string& emisor,
                 const std::string& mensaje) override
    {
        std::cout << "[Premium " << id_
                  << "] recibe mensaje PRIORITARIO: "
                  << mensaje << " (de " << emisor << ")\n";
    }

private:
    std::string id_;
};