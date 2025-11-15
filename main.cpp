// main.cpp
#include <iostream>
#include <vector>

#include "Puntuacion.hpp"
#include "Piloto.hpp"
#include "Coche.hpp"
#include "Escuderia.hpp"
#include "Circuito.hpp"
#include "Carrera.hpp"
#include "Campeonato.hpp"

int main() {
    // 1. Creamos algunos pilotos
    Piloto piloto1("Max Verstappen", 27, "Paises Bajos");
    Piloto piloto2("Lewis Hamilton", 40, "Reino Unido");
    Piloto piloto3("Charles Leclerc", 28, "Mónaco");

    // 2. Creamos algunos coches
    Coche coche1("Red Bull RB20", 1000, 350);
    Coche coche2("Mercedes W15",   980, 345);
    Coche coche3("Ferrari SF-24",  990, 348);

    // Asignamos pilotos a coches
    coche1.asignarPiloto(&piloto1);
    coche2.asignarPiloto(&piloto2);
    coche3.asignarPiloto(&piloto3);

    // 3. Creamos escuderías
    Escuderia redBull("Red Bull Racing", "Austria");
    Escuderia mercedes("Mercedes AMG", "Alemania");
    Escuderia ferrari("Scuderia Ferrari", "Italia");

    // Añadimos pilotos y coches a cada escudería
    redBull.agregarPiloto(&piloto1);
    redBull.agregarCoche(&coche1);

    mercedes.agregarPiloto(&piloto2);
    mercedes.agregarCoche(&coche2);

    ferrari.agregarPiloto(&piloto3);
    ferrari.agregarCoche(&coche3);

    // 4. Creamos un circuito y una carrera
    Circuito monza("Monza", "Italia", 5793, 53);
    Carrera gpItalia(monza);

    // Escuderías que participan en la carrera
    gpItalia.agregarEscuderia(&redBull);
    gpItalia.agregarEscuderia(&mercedes);
    gpItalia.agregarEscuderia(&ferrari);

    // 5. Clasificación de la carrera (ordenada: 1º, 2º, 3º...)
    std::vector<Piloto*> clasificacion;
    clasificacion.push_back(&piloto1); // 1º
    clasificacion.push_back(&piloto3); // 2º
    clasificacion.push_back(&piloto2); // 3º

    // Registramos la clasificación en la carrera
    gpItalia.registrarResultado(clasificacion);

    // Asignamos puntos al estilo Fórmula 1 (25, 18, 15 para los 3 primeros)
    std::vector<int> puntosF1 = {25, 18, 15};

    for (std::size_t i = 0; i < clasificacion.size(); ++i) {
        if (i < puntosF1.size()) {
            clasificacion[i]->agregarPuntos(puntosF1[i]);
        }
    }

    // 6. Creamos el campeonato y añadimos escuderías y la carrera
    Campeonato campeonato("Campeonato del Mundo F1 (ejemplo)");

    campeonato.agregarEscuderia(&redBull);
    campeonato.agregarEscuderia(&mercedes);
    campeonato.agregarEscuderia(&ferrari);

    campeonato.agregarCarrera(&gpItalia);
    // Si en tu Campeonato tienes agregarCircuito(), podrías hacer:
    // campeonato.agregarCircuito(&monza);

    // 7. Mostramos información
    std::cout << "========== INFORMACION ESCUDERIAS ==========\n";
    campeonato.mostrarEscuderias();

    std::cout << "\n========== RESULTADOS DE LA CARRERA ==========\n";
    gpItalia.mostrarResultados();

    std::cout << "\n========== CLASIFICACION GENERAL ==========\n";
    campeonato.mostrarClasificacionGeneral();

    std::cout << "\nFin del programa.\n";
    return 0;
}
