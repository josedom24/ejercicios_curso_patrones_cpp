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
class SingletonLogger : public ILogger {
public:
    // Punto de acceso global
    static SingletonLogger& instance() {
        static SingletonLogger instance; // Inicialización segura desde C++11
        return instance;
    }

    // Eliminamos copia y asignación
    SingletonLogger(const SingletonLogger&) = delete;
    SingletonLogger& operator=(const SingletonLogger&) = delete;

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
    SingletonLogger() = default;
};