#pragma once
#include <memory>
#include "EstadoReproductor.hpp"

// ----------------------------------------
// Contexto
// ----------------------------------------
class Reproductor {
public:
    Reproductor();

    void cambiar_estado(std::unique_ptr<EstadoReproductor> nuevoEstado);

    void play();
    void pause();
    void stop();

private:
    std::unique_ptr<EstadoReproductor> estado_;
};