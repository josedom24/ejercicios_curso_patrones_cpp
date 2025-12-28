#include "Mediador.hpp"
#include "Colegas.hpp"

int main() {
    auto mediador = std::make_shared<MediadorConcreto>();

    auto usuario1 = std::make_shared<UsuarioRegular>("Usuario1");
    auto usuario2 = std::make_shared<UsuarioRegular>("Usuario2");
    auto admin    = std::make_shared<UsuarioAdministrador>("Admin");
    auto premium = std::make_shared<UsuarioPremium>("Premium1");   //NUEVO 
    
    
    usuario1->establecer_mediador(mediador);
    usuario2->establecer_mediador(mediador);
    admin->establecer_mediador(mediador);
    premium->establecer_mediador(mediador); //NUEVO

    mediador->registrar_usuario(usuario1);
    mediador->registrar_usuario(usuario2);
    mediador->registrar_usuario(admin);
    mediador->registrar_usuario(premium); //NUEVO

    usuario1->enviar("Hola a todos!");
    usuario2->enviar("Saludos!");
    admin->enviar("Recordad las normas.");
    premium->enviar("Hola, soy usuario premium."); //NUEVO

    return 0;
}