#pragma once
#include <memory>
#include "Solicitud.hpp"

// ======================================================
//          Builder abstracto para SolicitudHTTP
// ======================================================

class ConstructorSolicitud {
public:
    virtual ~ConstructorSolicitud() = default;

    virtual void reiniciar() = 0;
    virtual void establecer_metodo(const std::string&) = 0;
    virtual void establecer_url(const std::string&) = 0;
    virtual void agregar_cabecera(const std::string&, const std::string&) = 0;
    virtual void establecer_cuerpo(const std::string&) = 0;
    virtual void establecer_timeout(int) = 0;   // NUEVO

    virtual std::unique_ptr<SolicitudHTTP> obtener_solicitud() = 0;
};

// ======================================================
//        Builder concreto (versión clásica con Director)
// ======================================================

class ConstructorSolicitudConcreto : public ConstructorSolicitud {
public:
    ConstructorSolicitudConcreto() { reiniciar(); }

    void reiniciar() override {
        solicitud_ = std::make_unique<SolicitudHTTP>();
    }

    void establecer_metodo(const std::string& m) override {
        solicitud_->establecer_metodo(m);
    }

    void establecer_url(const std::string& u) override {
        solicitud_->establecer_url(u);
    }

    void agregar_cabecera(const std::string& k,
                          const std::string& v) override {
        solicitud_->agregar_cabecera(k, v);
    }

    void establecer_cuerpo(const std::string& c) override {
        solicitud_->establecer_cuerpo(c);
    }

    //NUEVO

    void establecer_timeout(int ms) override {
        solicitud_->establecer_timeout(ms);
    }

    std::unique_ptr<SolicitudHTTP> obtener_solicitud() override {
        return std::move(solicitud_);
    }

private:
    std::unique_ptr<SolicitudHTTP> solicitud_;
};

// ======================================================
//   Builder fluido (sin Director, típico en C++ moderno)
// ======================================================

class ConstructorSolicitudFluido {
public:
    ConstructorSolicitudFluido& metodo(const std::string& m) {
        solicitud_.establecer_metodo(m);
        return *this;
    }

    ConstructorSolicitudFluido& url(const std::string& u) {
        solicitud_.establecer_url(u);
        return *this;
    }

    ConstructorSolicitudFluido& cabecera(const std::string& k,
                                         const std::string& v) {
        solicitud_.agregar_cabecera(k, v);
        return *this;
    }

    ConstructorSolicitudFluido& cuerpo(const std::string& c) {
        solicitud_.establecer_cuerpo(c);
        return *this;
    }

    //NUEVO

    ConstructorSolicitudFluido& timeout(int ms) {
       solicitud_.establecer_timeout(ms);
        return *this;
    }

    std::unique_ptr<SolicitudHTTP> construir() {
        return std::make_unique<SolicitudHTTP>(solicitud_);
    }

private:
    SolicitudHTTP solicitud_;
};