// Puntuacion.hpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>

class Puntuacion {
private:
    int puntosTotales;                 // Total de puntos acumulados
    std::vector<int> puntosPorCarrera; // Historial de puntos por carrera

public:
    // Constructor
    Puntuacion();

    // Métodos
    void agregarPuntos(int puntos);    // Suma puntos (por ejemplo, tras una carrera)
    int getTotal() const;              // Devuelve el total de puntos
    void mostrarHistorial() const;     // Muestra el historial de puntuaciones
    void reiniciar();                  // Pone los puntos a cero
};


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
