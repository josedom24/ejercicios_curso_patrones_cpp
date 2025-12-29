#include <iostream>
#include <memory>
#include "Estados.hpp"
#include "Reproductor.hpp"

// ----------------------------------------
// EstadoDetenido
// ----------------------------------------
void EstadoDetenido::play(Reproductor& r) {
    std::cout << "[Detenido] Iniciando reproducción.\n";
    r.cambiar_estado(std::make_unique<EstadoReproduciendo>());
}

void EstadoDetenido::pause(Reproductor&) {
    std::cout << "[Detenido] No se puede pausar.\n";
}

void EstadoDetenido::stop(Reproductor&) {
    std::cout << "[Detenido] Ya está detenido.\n";
}

// ----------------------------------------
// EstadoReproduciendo
// ----------------------------------------
void EstadoReproduciendo::play(Reproductor&) {
    std::cout << "[Reproduciendo] Ya se está reproduciendo.\n";
}

void EstadoReproduciendo::pause(Reproductor& r) {
    std::cout << "[Reproduciendo] Pausando reproducción.\n";
    r.cambiar_estado(std::make_unique<EstadoPausado>());
}

void EstadoReproduciendo::stop(Reproductor& r) {
    std::cout << "[Reproduciendo] Deteniendo reproducción.\n";
    r.cambiar_estado(std::make_unique<EstadoDetenido>());
}

// ----------------------------------------
// EstadoPausado
// ----------------------------------------
void EstadoPausado::play(Reproductor& r) {
    std::cout << "[Pausado] Reanudando reproducción.\n";
    r.cambiar_estado(std::make_unique<EstadoReproduciendo>());
}

void EstadoPausado::pause(Reproductor&) {
    std::cout << "[Pausado] Ya está en pausa.\n";
}

void EstadoPausado::stop(Reproductor& r) {
    std::cout << "[Pausado] Deteniendo reproducción.\n";
    r.cambiar_estado(std::make_unique<EstadoDetenido>());
}