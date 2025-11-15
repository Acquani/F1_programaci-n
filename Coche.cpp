// Coche.cpp
#include "Coche.hpp"
#include <string>
#include <iostream>

// Constructor
Coche::Coche(std::string modelo, int potencia, int velocidadMaxima)
    : modelo(modelo),
      potencia(potencia),
      velocidadMaxima(velocidadMaxima),
      pilotoAsignado(nullptr)   // Al principio el coche no tiene piloto
{
}

// Asocia un piloto al coche
void Coche::asignarPiloto(Piloto* p) {
    pilotoAsignado = p;
}

// Devuelve el piloto asignado (puede ser nullptr si no hay)
Piloto* Coche::getPiloto() const {
    return pilotoAsignado;
}

// Getters simples
std::string Coche::getModelo() const {
    return modelo;
}

int Coche::getPotencia() const {
    return potencia;
}

int Coche::getVelocidadMaxima() const {
    return velocidadMaxima;
}
void Coche::mostrarInfo() const {
    std::cout << "Modelo: " << modelo << "\n";
    std::cout << "Potencia: " << potencia << " CV\n";
    std::cout << "Velocidad máxima: " << velocidadMaxima << " km/h\n";

    if (pilotoAsignado != nullptr) {
        std::cout << "Piloto asignado: "
                  << pilotoAsignado->getNombre()
                  << " (" << pilotoAsignado->getPuntosTotales() << " puntos)\n";
    } else {
        std::cout << "Piloto asignado: ninguno\n";
    }
}
