#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include "Observadores.hpp"

// ----------------------------------------
// Interfaz base del sujeto (observable)
// ----------------------------------------
class Sujeto {
public:
    virtual ~Sujeto() = default;

    virtual void adjuntar(const std::shared_ptr<Observador>& obs) = 0;
    virtual void desadjuntar(const std::shared_ptr<Observador>& obs) = 0;

protected:
    virtual void notificar(int nueva_temperatura) = 0;
};

// ----------------------------------------
// Sujeto concreto: un sensor de temperatura
// ----------------------------------------
class SensorTemperatura : public Sujeto {
private:
    int temperatura_actual_{0};
    std::vector<std::weak_ptr<Observador>> observadores_;

public:
    void establecer_temperatura(int nueva_temp) {
        if (nueva_temp != temperatura_actual_) {
            temperatura_actual_ = nueva_temp;
            notificar(nueva_temp);
        }
    }

    void adjuntar(const std::shared_ptr<Observador>& obs) override {
        observadores_.push_back(obs);
    }

    void desadjuntar(const std::shared_ptr<Observador>& obs) override {
        observadores_.erase(
            std::remove_if(
                observadores_.begin(),
                observadores_.end(),
                [&obs](std::weak_ptr<Observador>& w) {
                    auto fuerte = w.lock();
                    return !fuerte || fuerte == obs;
                }
            ),
            observadores_.end()
        );
    }

protected:
    void notificar(int nueva_temperatura) override {
        observadores_.erase(
            std::remove_if(
                observadores_.begin(),
                observadores_.end(),
                [nueva_temperatura](std::weak_ptr<Observador>& w) {
                    auto fuerte = w.lock();
                    if (!fuerte)
                        return true;
                    fuerte->actualizar(nueva_temperatura);
                    return false;
                }
            ),
            observadores_.end()
        );
    }
};