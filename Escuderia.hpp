// Escuderia.hpp
#pragma once

#include <string>
#include <vector>

class Piloto;
class Coche;

class Escuderia {
private:
    std::string nombre;
    std::string pais;
    std::vector<Piloto*> pilotos;
    std::vector<Coche*> coches;

public:
    Escuderia(std::string nombre, std::string pais);

    void agregarPiloto(Piloto* piloto);
    void agregarCoche(Coche* coche);
    int getPuntosTotales() const;

    std::string getNombre() const { return nombre; }

    void mostrarInfo() const;
};

