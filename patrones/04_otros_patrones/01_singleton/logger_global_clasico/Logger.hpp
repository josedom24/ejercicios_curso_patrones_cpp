#pragma once
#include <iostream>
#include <string>

// ----------------------------------------
// Interfaz del logger
// ----------------------------------------
class ILogger {
public:
    virtual ~ILogger() = default;

    virtual void log(const std::string& msg) = 0;
    virtual void warning(const std::string& msg) = 0;
    virtual void error(const std::string& msg) = 0;
};

// ----------------------------------------
// Implementación Singleton
// ----------------------------------------
class ConsoleLogger : public ILogger {
public:
    // Punto de acceso global
    static ConsoleLogger& instance() {
        static ConsoleLogger instance; // Inicialización segura desde C++11
        return instance;
    }

    // Eliminamos copia y asignación
    ConsoleLogger(const ConsoleLogger&) = delete;
    ConsoleLogger& operator=(const ConsoleLogger&) = delete;

    // Implementación de ILogger
    void log(const std::string& msg) override {
        std::cout << "[LOG] " << msg << "\n";
    }

    void warning(const std::string& msg) override {
        std::cout << "[WARNING] " << msg << "\n";
    }

    void error(const std::string& msg) override {
        std::cout << "[ERROR] " << msg << "\n";
    }

private:
    // Constructor privado: impide creación externa
    ConsoleLogger() = default;
};