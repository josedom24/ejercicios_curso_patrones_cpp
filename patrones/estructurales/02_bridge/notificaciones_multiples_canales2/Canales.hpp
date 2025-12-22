#pragma once
#include <iostream>
#include <memory>
#include <string>

// ----------------------------------------
// Implementador: interfaz del canal
// ----------------------------------------

class CanalNotificacion {
public:
    virtual ~CanalNotificacion() = default;

    virtual void enviar(const std::string& mensaje) const = 0;
};


// ----------------------------------------
// Implementador concreto: EMAIL
// ----------------------------------------

class CanalEmail : public CanalNotificacion {
public:
    void enviar(const std::string& mensaje) const override {
        std::cout << "[EMAIL] Enviando mensaje: " << mensaje << "\n";
    }
};


// ----------------------------------------
// Implementador concreto: SMS
// ----------------------------------------

class CanalSMS : public CanalNotificacion {
public:
    void enviar(const std::string& mensaje) const override {
        std::cout << "[SMS] Enviando mensaje corto: " << mensaje << "\n";
    }
};

// ----------------------------------------
// Implementador concreto: PUSH
// ----------------------------------------

class CanalPush : public CanalNotificacion {
public:
    void enviar(const std::string& mensaje) const override {
        std::cout << "[PUSH] Notificación enviada: " << mensaje << "\n";
    }
};