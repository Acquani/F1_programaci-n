// Circuito.hpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <string>
#include <iostream>

class Circuito {
private:
    std::string nombre;
    std::string pais;
    int longitud;     // en kilómetros
    int vueltas;      // número de vueltas de la carrera

public:
    // Constructor
    Circuito(std::string nombre, std::string pais, int longitud, int vueltas);

    // Métodos
    std::string getNombre() const;
    std::string getPais() const;
    int getLongitud() const;
    int getVueltas() const;
    void mostrarInfo() const;
};


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
