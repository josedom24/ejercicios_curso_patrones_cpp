#pragma once
#include <string>
#include <map>
#include <iostream>

// ======================================================
//          Producto: SolicitudHTTP (MUTABLE)
// ======================================================

class SolicitudHTTP {
public:
    using Cabeceras = std::map<std::string, std::string>;

    // --- Setters ---
    void establecer_metodo(const std::string& m) { metodo_ = m; }
    void establecer_url(const std::string& u) { url_ = u; }
    void agregar_cabecera(const std::string& k, const std::string& v) {
        cabeceras_[k] = v;
    }
    void establecer_cuerpo(const std::string& c) { cuerpo_ = c; }

    // --- Getters ---
    const std::string& metodo()  { return metodo_; }
    const std::string& url()  { return url_; }
    const Cabeceras& cabeceras()  { return cabeceras_; }
    const std::string& cuerpo()  { return cuerpo_; }

    void mostrar() {
        std::cout << "SolicitudHTTP {\n"
                  << "  Método: " << metodo_ << "\n"
                  << "  URL:    " << url_ << "\n"
                  << "  Cabeceras:\n";
        for (const auto& [k, v] : cabeceras_) {
            std::cout << "    - " << k << ": " << v << "\n";
        }
        std::cout << "  Cuerpo: " << cuerpo_ << "\n}\n";
    }

private:
    std::string metodo_ = "GET";
    std::string url_;
    Cabeceras cabeceras_;
    std::string cuerpo_;
};
