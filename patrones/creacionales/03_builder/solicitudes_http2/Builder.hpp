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
        metodo_ = "GET";
        url_.clear();
        cabeceras_.clear();
        cuerpo_.clear();
    }

    void establecer_metodo(const std::string& m) override { metodo_ = m; }
    void establecer_url(const std::string& u) override { url_ = u; }

    void agregar_cabecera(const std::string& clave,
                          const std::string& valor) override {
        cabeceras_[clave] = valor;
    }

    void establecer_cuerpo(const std::string& c) override { cuerpo_ = c; }

    std::unique_ptr<SolicitudHTTP> obtener_solicitud() override {
        // La construcción se delega a la fábrica estática
        return SolicitudHTTP::crear(metodo_, url_, cabeceras_, cuerpo_, timeout_ms_);  //NUEVO
    }
    void establecer_timeout(int ms) override { timeout_ms_ = ms; }   // NUEVO

private:
    std::string metodo_;
    std::string url_;
    SolicitudHTTP::Cabeceras cabeceras_;
    std::string cuerpo_;
    int timeout_ms_ = 0;   // NUEVO

};


// ======================================================
//   Builder fluido (sin Director, típico en C++ moderno)
// ======================================================

class ConstructorSolicitudFluido {
public:
    ConstructorSolicitudFluido& metodo(const std::string& m) {
        metodo_ = m;
        return *this;
    }

    ConstructorSolicitudFluido& url(const std::string& u) {
        url_ = u;
        return *this;
    }

    ConstructorSolicitudFluido& cabecera(const std::string& clave,
                                         const std::string& valor) {
        cabeceras_[clave] = valor;
        return *this;
    }

    ConstructorSolicitudFluido& cuerpo(const std::string& c) {
        cuerpo_ = c;
        return *this;
    }
    ConstructorSolicitudFluido& timeout(int ms) {       // NUEVO
        timeout_ms_ = ms;
        return *this;
    }

    // Crea el objeto inmutable desde el builder fluido
    std::unique_ptr<SolicitudHTTP> construir() const {
        return SolicitudHTTP::crear(metodo_, url_, cabeceras_, cuerpo_, timeout_ms_);  // NUEVO
    }

private:
    std::string metodo_ = "GET";
    std::string url_;
    SolicitudHTTP::Cabeceras cabeceras_;
    std::string cuerpo_;
    int timeout_ms_ = 0;  // NUEVO
};
