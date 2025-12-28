#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <string>

// ----------------------------------------
// Interfaz base del producto: Logger
// ----------------------------------------
class Logger {
public:
    virtual ~Logger() = default;
    virtual void log(const std::string& mensaje) = 0;
};

// ----------------------------------------
// Productos concretos
// ----------------------------------------

// Logger que escribe en consola
class LoggerConsola : public Logger {
public:
    void log(const std::string& mensaje) override {
        std::cout << "[Consola] " << mensaje << "\n";
    }
};

// Logger que escribe en un archivo
class LoggerArchivo : public Logger {
private:
    std::ofstream archivo_;

public:
    explicit LoggerArchivo(const std::string& ruta)
        : archivo_(ruta, std::ios::app) {}

    void log(const std::string& mensaje) override {
        if (archivo_.is_open()) {
            archivo_ << "[Archivo] " << mensaje << "\n";
        }
    }
};

// Logger que simula envío por red
class LoggerRed : public Logger {
public:
    void log(const std::string& mensaje) override {
        std::cout << "[Red -> servidor] " << mensaje << "\n";
    }
};

// NUEVO
// Logger que simula escribir en una base de datos
class LoggerBD : public Logger {
public:
    void log(const std::string& mensaje) override {
        std::cout << "[BD] INSERT INTO logs VALUES ('" << mensaje << "');\n";
    }
};