#pragma once
#include <memory>
#include <string>

// ----------------------------------------
// Interfaz base del componente
// ----------------------------------------
class Markdown {
public:
    virtual ~Markdown() = default;
    virtual std::string render() const = 0;
};

// ----------------------------------------
// Componente concreto: texto base
// ----------------------------------------
class TextoMarkdown : public Markdown {
    std::string texto_;

public:
    explicit TextoMarkdown(std::string texto)
        : texto_(std::move(texto)) {}

    std::string render() const override {
        return texto_;
    }
};

// ----------------------------------------
// Clase base del decorador
// ----------------------------------------
class DecoradorMarkdown : public Markdown {
protected:
    std::unique_ptr<Markdown> componente_;

public:
    explicit DecoradorMarkdown(std::unique_ptr<Markdown> componente)
        : componente_(std::move(componente)) {}

    std::string render() const override {
        return componente_->render();
    }
};

// ----------------------------------------
// Decorador concreto: título
// ----------------------------------------
class TituloMarkdown : public DecoradorMarkdown {
    int nivel_;

public:
    TituloMarkdown(std::unique_ptr<Markdown> componente, int nivel)
        : DecoradorMarkdown(std::move(componente)),
          nivel_(nivel) {}

    std::string render() const override {
        return std::string(nivel_, '#') + " " +
               DecoradorMarkdown::render();
    }
};

// ----------------------------------------
// Decorador concreto: negrita
// ----------------------------------------
class NegritaMarkdown : public DecoradorMarkdown {
public:
    using DecoradorMarkdown::DecoradorMarkdown;

    std::string render() const override {
        return "**" + DecoradorMarkdown::render() + "**";
    }
};

// ----------------------------------------
// Decorador concreto: cursiva
// ----------------------------------------
class CursivaMarkdown : public DecoradorMarkdown {
public:
    using DecoradorMarkdown::DecoradorMarkdown;

    std::string render() const override {
        return "*" + DecoradorMarkdown::render() + "*";
    }
};

// ----------------------------------------
// Decorador concreto: bloque de código
// ----------------------------------------
class CodigoMarkdown : public DecoradorMarkdown {
public:
    using DecoradorMarkdown::DecoradorMarkdown;

    std::string render() const override {
        return "```cpp\n" +
               DecoradorMarkdown::render() +
               "\n```";
    }
};


// ----------------------------------------
// NUEVO Decorador concreto: lista
// ----------------------------------------
class ListaMarkdown : public DecoradorMarkdown {
public:
    using DecoradorMarkdown::DecoradorMarkdown;

    std::string render() const override {
        return "- " + DecoradorMarkdown::render();
    }
};