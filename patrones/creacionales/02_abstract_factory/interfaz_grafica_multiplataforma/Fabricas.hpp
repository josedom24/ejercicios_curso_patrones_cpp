#pragma once
#include <memory>
#include "Productos.hpp"

// ----------------------------------------
// Fábrica abstracta
// ----------------------------------------
class AbstractGUIFactory {
public:
    virtual ~AbstractGUIFactory() = default;

    virtual std::unique_ptr<Button>   create_button() const = 0;
    virtual std::unique_ptr<Checkbox> create_checkbox() const = 0;
};


// ----------------------------------------
// Fábrica concreta: FAMILIA WINDOWS
// ----------------------------------------

class WindowsFactory : public AbstractGUIFactory {
public:
    std::unique_ptr<Button> create_button() const override {
        return std::make_unique<WinButton>();
    }
    
    std::unique_ptr<Checkbox> create_checkbox() const override {
        return std::make_unique<WinCheckbox>();
    }
};


// ----------------------------------------
// Fábrica concreta: FAMILIA LINUX
// ----------------------------------------

class LinuxFactory : public AbstractGUIFactory {
public:
    std::unique_ptr<Button> create_button() const override {
        return std::make_unique<LinuxButton>();
    }
    
    std::unique_ptr<Checkbox> create_checkbox() const override {
        return std::make_unique<LinuxCheckbox>();
    }
};