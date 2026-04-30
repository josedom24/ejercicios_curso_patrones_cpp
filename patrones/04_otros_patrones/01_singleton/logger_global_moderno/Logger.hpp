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
// Implementación concreta del logger
// ----------------------------------------
class ConsoleLogger : public ILogger {
public:
    void log(const std::string& msg) override {
        std::cout << "[LOG] " << msg << "\n";
    }

    void warning(const std::string& msg) override {
        std::cout << "[WARNING] " << msg << "\n";
    }

    void error(const std::string& msg) override {
        std::cout << "[ERROR] " << msg << "\n";
    }
};