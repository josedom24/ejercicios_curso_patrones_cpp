#include "Reproductor.hpp"

int main() {
    Reproductor r;

    r.play();   // Detenido → Reproduciendo
    r.pause(); // Reproduciendo → Pausado
    r.play();  // Pausado → Reproduciendo
    r.stop();  // Reproduciendo → Detenido

    return 0;
}