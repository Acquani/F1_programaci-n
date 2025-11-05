// Coche.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#pragma once
#include <string>
#include <iostream>
#include "Piloto.hpp"  // Necesario porque el coche tiene un piloto asignado

class Coche {
private:
    std::string modelo;
    int potencia;            // En caballos de fuerza (CV)
    int velocidadMaxima;     // En km/h
    Piloto* pilotoAsignado;  // Relación: un coche tiene un piloto

public:
    // Constructor
    Coche(std::string modelo, int potencia, int velocidadMaxima);

    // Métodos
    void asignarPiloto(Piloto* p);  // Asocia un piloto al coche
    Piloto* getPiloto() const;      // Devuelve el piloto asignado
    std::string getModelo() const;
    int getPotencia() const;
    int getVelocidadMaxima() const;
    void mostrarInfo() const;       // Muestra datos del coche y del piloto
};



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
