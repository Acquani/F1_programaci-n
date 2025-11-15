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
// Devuelve el total de puntos del piloto
int Piloto::getPuntosTotales() const {
    return puntuacion.getTotal();
}

// Devuelve el nombre del piloto
std::string Piloto::getNombre() const {
    return nombre;
}
void Piloto::mostrarInfo() const {
    std::cout << "Piloto: " << nombre
              << " - Puntos: " << puntuacion.getTotal() << "\n";
}