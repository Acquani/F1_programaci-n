// Campeonato.cpp

#include "Campeonato.hpp"
#include "Carrera.hpp"
#include "Escuderia.hpp"
#include "Circuito.hpp"

#include <iostream>
#include <algorithm>   

// Constructor
Campeonato::Campeonato(std::string nombre)
    : nombre(nombre)
{
}

// Métodos
void Campeonato::agregarCarrera(Carrera* carrera) {
    carreras.push_back(carrera);   
}

void Campeonato::agregarEscuderia(Escuderia* escuderia) {
    escuderias.push_back(escuderia);   
}

void Campeonato::mostrarEscuderias() const {
    std::cout << "\nEscuderías inscritas en el campeonato " << nombre << ":\n";
    for (auto* e : escuderias) {
        std::cout << "-------------------------\n";
        e->mostrarInfo();
    }
}

// Mostrar todas las carreras programadas
void Campeonato::mostrarCarreras() const {
    std::cout << "\nCarreras del campeonato " << nombre << ":\n";
    for (auto* c : carreras) {
        std::cout << "-------------------------\n";
        c->mostrarResultados(); 
    }
}

void Campeonato::mostrarClasificacionGeneral() const {
    
    std::vector<Escuderia*> clasificacion = escuderias;

    // Ordenamos de mayor a menor puntos
    std::sort(clasificacion.begin(), clasificacion.end(),
        [](Escuderia* a, Escuderia* b) {
            return a->getPuntosTotales() > b->getPuntosTotales();
        }
    );

    // Mostramos la clasificación
    std::cout << "Clasificación General:\n";
    for (size_t i = 0; i < clasificacion.size(); i++) {
        std::cout << i + 1 << ". "
                  << clasificacion[i]->getNombre()    
                  << " - " << clasificacion[i]->getPuntosTotales()
                  << " puntos\n";
    }
}

void Campeonato::mostrarCalendario() const {
    std::cout << "=== Calendario del Campeonato ===\n";

    if (circuitos.empty()) {
        std::cout << "No hay circuitos registrados en el calendario.\n";
        return;
    }

    for (size_t i = 0; i < circuitos.size(); i++) {
        std::cout << i + 1 << ". "
                  << circuitos[i]->getNombre()
                  << " (" << circuitos[i]->getPais() << ")"
                  << " - " << circuitos[i]->getLongitud() << " km"
                  << std::endl;
    }
}

