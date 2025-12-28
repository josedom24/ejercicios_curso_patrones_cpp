#include <iostream>
#include <memory>
#include <string>

// ----------------------------------------
// Interfaz común (Sujeto)
// ----------------------------------------
class ISujeto {
public:
    virtual ~ISujeto() = default;
    virtual void realizar_operacion(const std::string& usuario) = 0;
};

// ----------------------------------------
// Objeto Real
// ----------------------------------------
class ObjetoReal : public ISujeto {
public:
    void realizar_operacion(const std::string& usuario) override {
        std::cout << "ObjetoReal: ejecutando operación para '" 
                  << usuario << "'.\n";
    }
};

// ----------------------------------------
// Proxy
// ----------------------------------------
class Proxy : public ISujeto {
private:
    std::unique_ptr<ObjetoReal> objeto_real_;

    bool comprobar_acceso(const std::string& usuario) const {
        std::cout << "Proxy: comprobando acceso para '" 
                  << usuario << "'...\n";
        return usuario == "admin";
    }

    void registrar_acceso(const std::string& usuario) const {
        std::cout << "Proxy: registrando uso del servicio por '" 
                  << usuario << "'.\n";
    }

public:
    void realizar_operacion(const std::string& usuario) override {
        if (!objeto_real_) {
            std::cout << "Proxy: inicializando ObjetoReal bajo demanda...\n";
            objeto_real_ = std::make_unique<ObjetoReal>();
        }

        if (comprobar_acceso(usuario)) {
            registrar_acceso(usuario);
            objeto_real_->realizar_operacion(usuario);
        } else {
            std::cout << "Proxy: acceso denegado a '" 
                      << usuario << "'.\n";
        }
    }
};

// ----------------------------------------
// Código cliente
// ----------------------------------------
void cliente(ISujeto& servicio, const std::string& usuario) {
    std::cout << "Cliente: intentando usar el servicio como '" 
              << usuario << "'.\n";
    servicio.realizar_operacion(usuario);
    std::cout << "----------------------------------------\n";
}

// ----------------------------------------
// main
// ----------------------------------------
int main() {
    Proxy servicio_proxy;

    cliente(servicio_proxy, "invitado");
    cliente(servicio_proxy, "admin");

    return 0;
}