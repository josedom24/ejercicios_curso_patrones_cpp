#pragma once
#include <iostream>
#include <memory>

// ----------------------------------------
// Interfaces de los productos
// ----------------------------------------

class Button {
public:
    virtual ~Button() = default;
    virtual void paint() const = 0;
};

class Checkbox {
public:
    virtual ~Checkbox() = default;
    virtual void toggle() const = 0;
};


// ----------------------------------------
// Productos concretos: FAMILIA WINDOWS
// ----------------------------------------

class WinButton : public Button {
public:
    void paint() const override {
        std::cout << "[Windows] Dibujando botón.\n";
    }
};

class WinCheckbox : public Checkbox {
public:
    void toggle() const override {
        std::cout << "[Windows] Alternando checkbox.\n";
    }
};


// ----------------------------------------
// Productos concretos: FAMILIA LINUX
// ----------------------------------------

class LinuxButton : public Button {
public:
    void paint() const override {
        std::cout << "[Linux] Dibujando botón.\n";
    }
};

class LinuxCheckbox : public Checkbox {
public:
    void toggle() const override {
        std::cout << "[Linux] Alternando checkbox.\n";
    }
};