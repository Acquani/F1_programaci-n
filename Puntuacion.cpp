// Puntuacion.cpp

#include "Puntuacion.hpp"
#include <iostream>

// Constructor: empieza con 0 puntos
Puntuacion::Puntuacion() : puntosTotales(0) {}

// Suma puntos y los guarda en el historial
void Puntuacion::agregarPuntos(int puntos)
{
    puntosTotales += puntos;
    puntosPorCarrera.push_back(puntos);   // <- aquí estaba el "pushback"
}

// Devuelve el total acumulado
int Puntuacion::getTotal() const
{
    return puntosTotales;
}

// Muestra todos los puntos por carrera y el total
void Puntuacion::mostrarHistorial() const {
    std::cout << "Historial de carreras: ";

    for (std::size_t i = 0; i < puntosPorCarrera.size(); ++i)
    {
        std::cout << puntosPorCarrera[i] << " ";
    }

    std::cout << "\nTotal: " << puntosTotales << std::endl;
}

// Pone los puntos a cero y borra el historial
void Puntuacion::reiniciar() {
    puntosTotales = 0;
    puntosPorCarrera.clear();
}
