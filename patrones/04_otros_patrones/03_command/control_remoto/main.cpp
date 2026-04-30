#include "ControlRemoto.hpp"
#include "Receptor.hpp"

int main() {
    Luz luz;
    Persiana persiana;

    ControlRemoto control;

    // ----------------------------
    // Configuración inicial
    // ----------------------------

    control.asignar_boton1([&]() { luz.encender(); });
    control.asignar_boton2([&]() { persiana.subir(); });

    control.pulsar_boton1(); // Luz encendida
    control.pulsar_boton2(); // Persiana subida

    // ----------------------------
    // Reconfiguración dinámica
    // ----------------------------

    control.asignar_boton1([&]() { luz.apagar(); });
    control.asignar_boton2([&]() { persiana.bajar(); });

    control.pulsar_boton1(); // Luz apagada
    control.pulsar_boton2(); // Persiana bajada

    return 0;
}