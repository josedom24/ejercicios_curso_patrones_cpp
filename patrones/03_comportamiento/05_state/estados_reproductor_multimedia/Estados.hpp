#pragma once
#include "EstadoReproductor.hpp"

// Declaraciones anticipadas
class EstadoDetenido;
class EstadoReproduciendo;
class EstadoPausado;

// ----------------------------------------
// Estados concretos
// ----------------------------------------
class EstadoDetenido : public EstadoReproductor {
public:
    void play(Reproductor&) override;
    void pause(Reproductor&) override;
    void stop(Reproductor&) override;
};

class EstadoReproduciendo : public EstadoReproductor {
public:
    void play(Reproductor&) override;
    void pause(Reproductor&) override;
    void stop(Reproductor&) override;
};

class EstadoPausado : public EstadoReproductor {
public:
    void play(Reproductor&) override;
    void pause(Reproductor&) override;
    void stop(Reproductor&) override;
};