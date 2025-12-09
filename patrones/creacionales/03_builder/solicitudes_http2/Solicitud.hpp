#pragma once
#include <string>
#include <map>
#include <iostream>

// ======================================================
//             Producto: SolicitudHTTP (INMUTABLE)
// ======================================================

class SolicitudHTTP {
public:
    using Cabeceras = std::map<std::string, std::string>;

    // --- Métodos de acceso ---
    const std::string& metodo()    const noexcept { return metodo_; }
    const std::string& url()       const noexcept { return url_; }
    const Cabeceras&   cabeceras() const noexcept { return cabeceras_; }
    const std::string& cuerpo()    const noexcept { return cuerpo_; }
    int timeout_ms() const noexcept { return timeout_ms_; }  // NUEVO

    void mostrar() const {
        std::cout << "SolicitudHTTP {\n"
                  << "  Método: " << metodo_ << "\n"
                  << "  URL:    " << url_ << "\n"
                  << "  Cabeceras:\n";
        for (const auto& par : cabeceras_) {
            std::cout << "    - " << par.first << ": " << par.second << "\n";
        }
        std::cout << "  Cuerpo: " << cuerpo_ << "\n}\n";
    }

    // ======================================================
    //     Fábrica estática moderna (sin make_unique posible)
    // ======================================================
    static std::unique_ptr<SolicitudHTTP> crear(
        const std::string& metodo,
        const std::string& url,
        const Cabeceras& cab,
        const std::string& cuerpo,
        int timeout_ms = 0                // NUEVO  
        )   
    {
        /*
         * Por qué usamos `new` aquí:
         * -----------------------------------------
         * El constructor de SolicitudHTTP es privado
         * porque el patrón Builder exige que solo los
         * builders autorizados puedan crear instancias.
         *
         * std::make_unique NO puede usarse porque intenta
         * construir el objeto dentro de <memory>, que NO es
         * amigo de la clase; por tanto, no puede llamar al
         * constructor privado.
         *
         * En cambio, este método estático SÍ forma parte de
         * la propia clase, por lo que puede usar `new` para
         * invocar al constructor privado.
         *
         * El usuario final nunca usa `new` ni gestiona memoria:
         * la instancia se devuelve siempre envuelta en
         * std::unique_ptr, respetando RAII y C++ moderno.
         */
        return std::unique_ptr<SolicitudHTTP>(
            new SolicitudHTTP(metodo, url, cab, cuerpo, timeout_ms)  // NUEVO
        );
    }

private:
    // --- Atributos inmutables ---
    const std::string metodo_;
    const std::string url_;
    const Cabeceras   cabeceras_;
    const std::string cuerpo_;
    const int timeout_ms_ = 0;   // NUEVO

    // Constructor privado: solo accesible desde la fábrica y friends
    SolicitudHTTP(const std::string& metodo,
                  const std::string& url,
                  const Cabeceras& cab,
                  const std::string& cuerpo,
                  int timeout_ms)               // NUEVO
        : metodo_(metodo),
          url_(url),
          cabeceras_(cab),
          cuerpo_(cuerpo),
          timeout_ms_(timeout_ms)              // NUEVO
    {}

    friend class ConstructorSolicitud;
    friend class ConstructorSolicitudConcreto;
    friend class ConstructorSolicitudFluido;
};
