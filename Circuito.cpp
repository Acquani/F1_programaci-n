// Circuito.cpp
#include "Circuito.hpp"
#include <string>
#include <iostream>

// Constructor
Circuito::Circuito(std::string nombre, std::string pais, int longitud, int vueltas)
    : nombre(nombre),
      pais(pais),
      longitud(longitud),
      vueltas(vueltas)
{
}
//Getters
std::string Circuito::getNombre() const {
    return nombre;
}

std::string Circuito::getPais() const {
    return pais;
}

int Circuito::getLongitud() const {
    return longitud;
}

int Circuito::getVueltas() const {
    return vueltas;
}

// Muestra la información del circuito por pantalla
void Circuito::mostrarInfo() const {
    std::cout << "Circuito: " << nombre << "\n";
    std::cout << "País: " << pais << "\n";
    std::cout << "Longitud: " << longitud << " km\n";
    std::cout << "Vueltas: " << vueltas << "\n";
}