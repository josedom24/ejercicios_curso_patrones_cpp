#include "Sujetos.hpp"

int main() {
    SensorTemperatura sensor;

    auto pantalla = std::make_shared<ObservadorPantalla>();
    auto archivo  = std::make_shared<ObservadorArchivo>("temperaturas.txt");
    auto alerta   = std::make_shared<ObservadorAlerta>(30);
    auto red = std::make_shared<ObservadorRed>();  //NUEVO


    sensor.adjuntar(pantalla);
    sensor.adjuntar(archivo);
    sensor.adjuntar(alerta);
    sensor.adjuntar(red);  //NUEVO

    sensor.establecer_temperatura(22);
    sensor.establecer_temperatura(31);

    // Desconectamos la pantalla
    sensor.desadjuntar(pantalla);

    sensor.establecer_temperatura(35);

    return 0;
}