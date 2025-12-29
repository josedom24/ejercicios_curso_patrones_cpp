#include "Reproductor.hpp"
#include "Estados.hpp"

Reproductor::Reproductor()
    : estado_(std::make_unique<EstadoSinContenido>()) {} //MODIFICADO

void Reproductor::cambiar_estado(std::unique_ptr<EstadoReproductor> nuevoEstado) {
    estado_ = std::move(nuevoEstado);
}

void Reproductor::play() {
    estado_->play(*this);
}

void Reproductor::pause() {
    estado_->pause(*this);
}

void Reproductor::stop() {
    estado_->stop(*this);
}