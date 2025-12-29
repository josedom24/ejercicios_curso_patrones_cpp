#pragma once

// Declaración anticipada
class Reproductor;

// ----------------------------------------
// Interfaz base del estado
// ----------------------------------------
class EstadoReproductor {
public:
    virtual ~EstadoReproductor() = default;

    virtual void play(Reproductor&) = 0;
    virtual void pause(Reproductor&) = 0;
    virtual void stop(Reproductor&) = 0;
};