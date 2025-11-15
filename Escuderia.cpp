// Escuderia.cpp

#include "Escuderia.hpp"
#include "Piloto.hpp"
#include "Coche.hpp"
#include <iostream>

// Constructor
Escuderia::Escuderia(std::string nombre, std::string pais)
    : nombre(nombre),
      pais(pais)
{}

// Añadir piloto
void Escuderia::agregarPiloto(Piloto* piloto) {
    pilotos.push_back(piloto);
}

// Añadir coche
void Escuderia::agregarCoche(Coche* coche) {
    coches.push_back(coche);
}

// Calcular puntos totales de la escudería
int Escuderia::getPuntosTotales() const {
    int puntos = 0;
    for (size_t i = 0; i < pilotos.size(); i++) {
        puntos += pilotos[i]->getPuntosTotales();  
    }
    return puntos;
}

// Mostrar información
void Escuderia::mostrarInfo() const {
    std::cout << "Escudería: " << nombre << " (" << pais << ")\n";

    std::cout << "Pilotos:\n";
    for (auto* piloto : pilotos) {
        std::cout << "  - ";
        piloto->mostrarInfo();
    }

    std::cout << "Coches:\n";
    for (auto* coche : coches) {
        std::cout << "  - ";
        coche->mostrarInfo();
    }

    std::cout << "Puntos totales: " << getPuntosTotales() << "\n";
}

