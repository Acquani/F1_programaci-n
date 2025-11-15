// Campeonato.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <vector>
#include "Campeonato.hpp"
using namespace std;
private:
    std::string nombre;
    std::vector<Carrera*> carreras;
    std::vector<Escuderia*> escuderias;


    // Constructor
    Campeonato::Campeonato(string nombre) :
        nombre(nombre)
    {
    }
    // Métodos
    void Campeonato::agregarCarrera(Carrera* carrera) {
        carreras.push_back(c);
    }

    void Campeonato::agregarEscuderia(Escuderia* escuderia) {
        escuderias.push_back(e);
    }

    void Campeonato::mostrarEscuderias() const {
        std::cout << "\nEscuderías inscritas en el campeonato " << nombre << ":\n";
        for (auto e : escuderias) {
            std::cout << "-------------------------\n";
            e->mostrarInfo();
        }
    }

    // Mostrar todas las carreras programadas
    void Campeonato::mostrarCarreras() const {
        std::cout << "\nCarreras del campeonato " << nombre << ":\n";
        for (auto c : carreras) {
            std::cout << "-------------------------\n";
            c->mostrarInfo();
        }
    }

    void Campeonato::mostrarClasificacionGeneral() const {
        // Creamos una copia del vector para ordenarlo
        std::vector<Escuderia*> clasificacion = escuderias;

        // Ordenamos de mayor a menor puntos
        std::sort(clasificacion.begin(), clasificacion.end(),
            [](Escuderia* a, Escuderia* b) {
                return a->getPuntosTotales() > b->getPuntosTotales();
            }
        );

        // Mostramos la clasificación
        cout << "Clasificación General:\n";
        for (size_t i = 0; i < clasificacion.size(); i++) {
            cout << i + 1 << ". "
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



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
