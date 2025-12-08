#include "Fabricas.hpp"

void cliente(const AbstractGUIFactory& fabrica) {
    auto boton = fabrica.create_button();
    auto checkbox = fabrica.create_checkbox();

    boton->paint();
    checkbox->toggle();
}

int main() {
    WindowsFactory winUI;
    LinuxFactory   linuxUI;

    cliente(winUI);
    cliente(linuxUI);

    return 0;
}