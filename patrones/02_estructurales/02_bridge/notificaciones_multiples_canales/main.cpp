#include "Notificaciones.hpp"

void cliente(Notificacion& notif) {
    notif.enviar("Revisar el sistema de seguridad.");
}

int main() {
    // Notificación de alerta por EMAIL
    NotificacionAlerta alerta{
        std::make_unique<CanalEmail>()
    };
    cliente(alerta);

    // Notificación de recordatorio por SMS
    NotificacionRecordatorio recordatorio{
        std::make_unique<CanalSMS>()
    };
    cliente(recordatorio);

    // Cambiar canal en tiempo de ejecución
    recordatorio.cambiar_canal(std::make_unique<CanalEmail>());
    recordatorio.enviar("Reunión mañana a las 10.");

    return 0;
}