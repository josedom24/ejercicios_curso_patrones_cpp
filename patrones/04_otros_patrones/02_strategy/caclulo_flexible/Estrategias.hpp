#pragma once
#include <functional>

// ----------------------------------------
// Firma común de las estrategias
// ----------------------------------------
using EstrategiaCalculo = std::function<int(int, int)>;

// ----------------------------------------
// Fábricas de estrategias
// ----------------------------------------
EstrategiaCalculo estrategia_suma();
EstrategiaCalculo estrategia_producto();
EstrategiaCalculo estrategia_potencia();