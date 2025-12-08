#include <iostream>
#include <memory>

// ======================================================
//    Interfaces de la familia de productos
// ======================================================

// Producto 1: Button
class Button {
public:
    virtual ~Button() = default;
    virtual void paint() const = 0;
};

// Producto 2: Checkbox
class Checkbox {
public:
    virtual ~Checkbox() = default;
    virtual void toggle() const = 0;
};


// ======================================================
//    Productos concretos de la familia Windows
// ======================================================

class WinButton : public Button {
public:
    void paint() const override {
        std::cout << "[Windows] Pintando botón.\n";
    }
};

class WinCheckbox : public Checkbox {
public:
    void toggle() const override {
        std::cout << "[Windows] Alternando checkbox.\n";
    }
};


// ======================================================
//    Productos concretos de la familia Linux
// ======================================================

class LinuxButton : public Button {
public:
    void paint() const override {
        std::cout << "[Linux] Pintando botón.\n";
    }
};

class LinuxCheckbox : public Checkbox {
public:
    void toggle() const override {
        std::cout << "[Linux] Alternando checkbox.\n";
    }
};


// ======================================================
//    Fábrica abstracta
// ======================================================

class AbstractGUIFactory {
public:
    virtual ~AbstractGUIFactory() = default;

    virtual std::unique_ptr<Button> create_button() const = 0;
    virtual std::unique_ptr<Checkbox> create_checkbox() const = 0;
};


// ======================================================
//    Fábricas concretas
// ======================================================

class WindowsFactory : public AbstractGUIFactory {
public:
    std::unique_ptr<Button> create_button() const override {
        return std::make_unique<WinButton>();
    }

    std::unique_ptr<Checkbox> create_checkbox() const override {
        return std::make_unique<WinCheckbox>();
    }
};

class LinuxFactory : public AbstractGUIFactory {
public:
    std::unique_ptr<Button> create_button() const override {
        return std::make_unique<LinuxButton>();
    }

    std::unique_ptr<Checkbox> create_checkbox() const override {
        return std::make_unique<LinuxCheckbox>();
    }
};


// ======================================================
//    Código cliente
// ======================================================

void cliente(const AbstractGUIFactory& factory) {
    auto button   = factory.create_button();
    auto checkbox = factory.create_checkbox();

    button->paint();
    checkbox->toggle();
}

int main() {
    WindowsFactory winFactory;
    LinuxFactory   linuxFactory;

    cliente(winFactory);
    cliente(linuxFactory);
}