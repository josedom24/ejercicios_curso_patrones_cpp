#include "Reproductor.hpp"

int main() {
    Reproductor r;

    r.play();   // SinContenido → Reproduciendo
    r.pause(); // Reproduciendo → Pausado
    r.play();  // Pausado → Reproduciendo
    r.stop();  // Reproduciendo → Detenido

    return 0;
}