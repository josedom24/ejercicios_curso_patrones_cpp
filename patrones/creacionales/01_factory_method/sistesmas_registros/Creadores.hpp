#pragma once
#include <memory>
#include <string>
#include "Productos.hpp"

// ----------------------------------------
// Interfaz base del creador
// ----------------------------------------
class CreadorLogger {
public:
    virtual ~CreadorLogger() = default;

    // Factory Method
    virtual std::unique_ptr<Logger> crear_logger() const = 0;

    // Método que utiliza el logger sin conocer su tipo concreto
    void registrar(const std::string& mensaje) const {
        auto logger = crear_logger();
        logger->log(mensaje);
    }
};

// ----------------------------------------
// Creadores concretos
// ----------------------------------------

class CreadorLoggerConsola : public CreadorLogger {
public:
    std::unique_ptr<Logger> crear_logger() const override {
        return std::make_unique<LoggerConsola>();
    }
};

class CreadorLoggerArchivo : public CreadorLogger {
private:
    std::string ruta_;

public:
    explicit CreadorLoggerArchivo(const std::string& ruta)
        : ruta_(ruta) {}

    std::unique_ptr<Logger> crear_logger() const override {
        return std::make_unique<LoggerArchivo>(ruta_);
    }
};

class CreadorLoggerRed : public CreadorLogger {
public:
    std::unique_ptr<Logger> crear_logger() const override {
        return std::make_unique<LoggerRed>();
    }
};