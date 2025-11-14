// Carrera.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Carrera.hpp"
#include <iostream>

// Constructor
Carrera::Carrera(const Circuito& circuito)
    : circuito(circuito), finalizada(false) {}

// Agregar escudería participante
void Carrera::agregarEscuderia(Escuderia* e) {
    if (finalizada) {
        std::cout << "No se pueden agregar escuderías después de finalizar la carrera.\n";
        return;
    }
    escuderiasParticipantes.push_back(e);
}

// Registrar resultado de pilotos
void Carrera::registrarResultado(std::vector<Piloto*> clasificacion) {
    if (finalizada) {
        std::cout << "La carrera ya ha sido finalizada.\n";
        return;
    }

    this->clasificacionPilotos = clasificacion;
    finalizada = true;
}

// Mostrar resultados en orden
void Carrera::mostrarResultados() const {
    if (!finalizada) {
        std::cout << "La carrera aún no ha finalizado.\n";
        return;
    }

    std::cout << "=== Resultados de la carrera en " << circuito.getNombre() << " ===\n";

    int posicion = 1;
    for (auto* piloto : clasificacionPilotos) {
        std::cout << posicion << ". " << piloto->getNombre() << "\n";
        posicion++;
    }
}

// Saber si la carrera ya terminó
bool Carrera::estaFinalizada() const {
    return finalizada;
}
