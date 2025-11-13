// Circuito.cpp
#include "Circuito.hpp"
#include <string>

// Constructor
Circuito::Circuito(std::string nombre, std::string pais, int longitud, int vueltas)
    : nombre(nombre),
      pais(pais),
      longitud(longitud),
      vueltas(vueltas)
{
}

