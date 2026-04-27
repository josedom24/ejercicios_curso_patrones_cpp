#pragma once
#include "EstadoReproductor.hpp"

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

// ----------------------------------------
// Nuevo estado concreto: Sin contenido
// ----------------------------------------
class EstadoSinContenido : public EstadoReproductor {
public:
    void play(Reproductor&) override;
    void pause(Reproductor&) override;
    void stop(Reproductor&) override;
};