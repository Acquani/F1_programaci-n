// Escuderia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "Escuderia.hpp"

    //constructor
    Escuderia::Escuderia(std::string nombre, std::string pais): 
        nombre(nombre),
        pais(pais) {}

    void Escuderia::agregarPiloto(Piloto* piloto) {
        pilotos.push_back(piloto);
    }
    void Escuderia::agregarCoche(Coche* coche) {
        coches.push_back(coche);
    }
    int Escuderia::getPuntosTotales() const {
        int puntos = 0;
        for (int i = 0; i < pilotos.size(); i++)
        {
            puntos += pilotos[i]->getPuntosTotales;
        }
        return puntos;
    }
    void Escuderia::mostrarInfo() const {
        std::cout << "Escudería: " << nombre << " (" << pais << ")\n";

        std::cout << "Pilotos:\n";
        for (auto piloto : pilotos) {
            std::cout << "  - ";
            piloto->mostrarInfo();
        }

        std::cout << "Coches:\n";
        for (auto coche : coches) {
            std::cout << "  - ";
            coche->mostrarInfo();
        }

        std::cout << "Puntos totales: " << getPuntosTotales() << "\n";
    }
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
