#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <string>

// ----------------------------------------
// Interfaz base del observador
// ----------------------------------------
class Observador {
public:
    virtual ~Observador() = default;
    virtual void actualizar(int nueva_temperatura) = 0;
};

// ----------------------------------------
// Observador que muestra la temperatura en pantalla
// ----------------------------------------
class ObservadorPantalla : public Observador {
public:
    void actualizar(int nueva_temperatura) override {
        std::cout << "[Pantalla] Temperatura actual: "
                  << nueva_temperatura << "°C\n";
    }
};

// ----------------------------------------
// Observador que registra la temperatura en un archivo
// ----------------------------------------
class ObservadorArchivo : public Observador {
private:
    std::ofstream archivo_;

public:
    explicit ObservadorArchivo(const std::string& ruta)
        : archivo_(ruta, std::ios::app) {}

    void actualizar(int nueva_temperatura) override {
        if (archivo_.is_open()) {
            archivo_ << "[Archivo] Temperatura: "
                     << nueva_temperatura << "°C\n";
        }
    }
};

// ----------------------------------------
// Observador que lanza una alerta si la temperatura supera un umbral
// ----------------------------------------
class ObservadorAlerta : public Observador {
private:
    int umbral_;

public:
    explicit ObservadorAlerta(int umbral) : umbral_(umbral) {}

    void actualizar(int nueva_temperatura) override {
        if (nueva_temperatura > umbral_) {
            std::cout << "[ALERTA] Temperatura crítica: "
                      << nueva_temperatura << "°C\n";
        }
    }
};