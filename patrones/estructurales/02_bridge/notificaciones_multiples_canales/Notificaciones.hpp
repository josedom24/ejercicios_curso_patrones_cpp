#pragma once
#include <memory>
#include <string>
#include "Canales.hpp"

// ----------------------------------------
// Abstracción: Notificación
// ----------------------------------------

class Notificacion {
protected:
    std::unique_ptr<CanalNotificacion> canal_;  // El "bridge"

public:
    explicit Notificacion(std::unique_ptr<CanalNotificacion> canal)
        : canal_(std::move(canal)) {}

    virtual ~Notificacion() = default;

    // Permite cambiar el canal en tiempo de ejecución si es necesario
    void cambiar_canal(std::unique_ptr<CanalNotificacion> nuevo_canal) {
        canal_ = std::move(nuevo_canal);
    }

    // Método de alto nivel que delega en la implementación
    virtual void enviar(const std::string& texto) const = 0;
};


// ----------------------------------------
// Abstracción refinada: Alerta
// ----------------------------------------

class NotificacionAlerta : public Notificacion {
public:
    using Notificacion::Notificacion;

    void enviar(const std::string& texto) const override {
        std::string mensaje = "[ALERTA] " + texto;
        canal_->enviar(mensaje);
    }
};


// ----------------------------------------
// Abstracción refinada: Recordatorio
// ----------------------------------------

class NotificacionRecordatorio : public Notificacion {
public:
    using Notificacion::Notificacion;

    void enviar(const std::string& texto) const override {
        std::string mensaje = "[RECORDATORIO] " + texto;
        canal_->enviar(mensaje);
    }
};