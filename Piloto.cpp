// Piloto.cpp
#include "Piloto.hpp"
#include <string>
// Constructor
Piloto::Piloto(std::string nombre, int edad, std::string nacionalidad)
    : nombre(nombre),
      edad(edad),
      nacionalidad(nacionalidad),
      puntuacion()   // se llama al constructor por defecto de Puntuacion
{
}
// Suma puntos al piloto usando su objeto Puntuacion
void Piloto::agregarPuntos(int puntos) {
    puntuacion.agregarPuntos(puntos);
}
