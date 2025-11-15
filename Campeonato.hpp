// Campeonato.hpp
#pragma once

#include <string>
#include <vector>
#include "Circuito.hpp"
#include "Escuderia.hpp"
#include "Carrera.hpp"

class Campeonato {
private:
    std::string nombre;
    std::vector<Carrera*> carreras;
    std::vector<Escuderia*> escuderias;
    std::vector<Circuito*> circuitos;   

public:
    Campeonato(std::string nombre);

    void agregarCarrera(Carrera* carrera);
    void agregarEscuderia(Escuderia* escuderia);
    void agregarCircuito(Circuito* circuito); 

    void mostrarEscuderias() const;
    void mostrarCarreras() const;
    void mostrarClasificacionGeneral() const;
    void mostrarCalendario() const;
};

