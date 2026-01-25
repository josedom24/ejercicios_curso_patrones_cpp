#include "ControlRemoto.hpp"
#include "Receptor.hpp"

int main() {
    Luz luz;
    Persiana persiana;

    ControlRemoto control;

    // Encender luz
    control.asignar_accion([&]() { luz.encender(); });
    control.pulsar_boton();

    // Apagar luz
    control.asignar_accion([&]() { luz.apagar(); });
    control.pulsar_boton();

    // Subir persiana
    control.asignar_accion([&]() { persiana.subir(); });
    control.pulsar_boton();

    // Bajar persiana
    control.asignar_accion([&]() { persiana.bajar(); });
    control.pulsar_boton();

    return 0;
}