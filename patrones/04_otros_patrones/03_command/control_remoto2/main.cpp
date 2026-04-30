#include "ControlRemoto.hpp"
#include "Receptor.hpp"

int main() {
    Luz luz;
    Persiana persiana;
    Ventilador ventilador; //NUEVO

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

    // NUEVA configuración
    control.asignar_boton1([&]() { ventilador.activar(); });
    control.asignar_boton2([&]() { ventilador.desactivar(); });

    control.pulsar_boton1();
    control.pulsar_boton2();

    return 0;
}