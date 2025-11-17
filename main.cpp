#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>


#include "Piloto.hpp"
#include "Coche.hpp"
#include "Escuderia.hpp"
#include "Circuito.hpp"
#include "Carrera.hpp"
#include "Campeonato.hpp"

using namespace std;

//FUNCIONES AUXILIARES 

int leerEntero(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            return valor;
        } else {
            cout << "Entrada no válida. Introduce un número.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

string leerLinea(const string& mensaje) {
    cout << mensaje;
    string s;
    getline(cin, s);
    return s;
}

void leerClasificacionDesdeFichero() {
    ifstream file("clasificacion.txt");
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo clasificacion.txt\n";
        return;
    }

    cout << "\n=== CLASIFICACION DESDE FICHERO ===\n";

    string linea;
    while (getline(file, linea)) {
        cout << linea << "\n";
    }

    file.close();
}
void guardarClasificacionEnFichero(const vector<Escuderia*>& escuderias) {
    ofstream file("clasificacion.txt");
    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el archivo clasificacion.txt");
    }

    vector<Escuderia*> clasificacion = escuderias;
    std::sort(clasificacion.begin(), clasificacion.end(),
              [](Escuderia* a, Escuderia* b) {
                  return a->getPuntosTotales() > b->getPuntosTotales();
              });

    file << "=== CLASIFICACION GENERAL ===\n";
    for (size_t i = 0; i < clasificacion.size(); ++i) {
        file << i + 1 << ". "
             << clasificacion[i]->getNombre()
             << " - " << clasificacion[i]->getPuntosTotales()
             << " puntos\n";
    }

    file.close();
    cout << "Clasificación guardada en 'clasificacion.txt'\n";
}


void testBasico() {
    cout << "\n=== Ejecutando test básico ===\n";
    Piloto p("Test", 20, "España");
    p.agregarPuntos(10);
    if (p.getPuntosTotales() != 10) {
        throw runtime_error("ERROR en test básico: puntos incorrectos.");
    }
    cout << "Test OK.\n";
}

//MAIN 

int main() {
    vector<Escuderia*> escuderias;
    vector<Piloto*>    pilotos;
    vector<Coche*>     coches;
    vector<Circuito*>  circuitos;
    vector<Carrera*>   carreras;

    Campeonato campeonato("Formula X");

    try {
        bool salir = false;
        while (!salir) {
            cout << "\n============ MENU ============\n";
            cout << "1. Crear escuderia\n";
            cout << "2. Crear piloto y asignar a escuderia\n";
            cout << "3. Crear coche y asignar a escuderia/piloto\n";
            cout << "4. Crear circuito\n";
            cout << "5. Crear carrera (a partir de un circuito)\n";
            cout << "6. Registrar resultados de una carrera\n";
            cout << "7. Mostrar escuderias\n";
            cout << "8. Mostrar carreras\n";
            cout << "9. Mostrar clasificacion general\n";
            cout << "10. Guardar clasificacion en fichero\n";
            cout << "11. Leer clasificacion desde fichero\n";
            cout << "0. Salir\n";
            cout << "Elige una opcion: ";

            int opcion = leerEntero("Elige una opcion: ");

            switch (opcion) {

            //CREAR ESCUDERIA 
            case 1: {
                string nombre, pais;
                nombre = leerLinea("Nombre de la escuderia: ");
                pais   = leerLinea("Pais de la escuderia: ");

                Escuderia* e = new Escuderia(nombre, pais);
                escuderias.push_back(e);
                campeonato.agregarEscuderia(e);

                cout << "Escuderia creada y añadida al campeonato.\n";
                break;
            }

            //CREAR PILOTO
            case 2: {
                if (escuderias.empty()) {
                    cout << "Primero debes crear al menos una escuderia.\n";
                    break;
                }

                string nombre, nac;
                int edad;

                nombre = leerLinea("Nombre del piloto: ");
                edad   = leerEntero("Edad del piloto: ");
                nac    = leerLinea("Nacionalidad del piloto: ");

                cout << "\nEscuderias disponibles:\n";
                for (size_t i = 0; i < escuderias.size(); ++i) {
                    cout << i + 1 << ". " << escuderias[i]->getNombre() << "\n";
                }
                int idx = leerEntero("Elige escuderia para el piloto: ") - 1;

                if (idx < 0 || idx >= (int)escuderias.size()) {
                    cout << "Escuderia no valida.\n";
                    break;
                }

                Piloto* p = new Piloto(nombre, edad, nac);
                pilotos.push_back(p);
                escuderias[idx]->agregarPiloto(p);

                cout << "Piloto creado y asignado.\n";
                break;
            }

            //CREAR COCHE
            case 3: {
                if (escuderias.empty()) {
                    cout << "Primero debes crear al menos una escuderia.\n";
                    break;
                }

                string modelo;
                int potencia, vmax;

                modelo   = leerLinea("Modelo del coche: ");
                potencia = leerEntero("Potencia (CV): ");
                vmax     = leerEntero("Velocidad maxima (km/h): ");

                cout << "\nEscuderias disponibles:\n";
                for (size_t i = 0; i < escuderias.size(); ++i) {
                    cout << i + 1 << ". " << escuderias[i]->getNombre() << "\n";
                }
                int idxEsc = leerEntero("Elige escuderia para el coche: ") - 1;

                if (idxEsc < 0 || idxEsc >= (int)escuderias.size()) {
                    cout << "Escuderia no valida.\n";
                    break;
                }

                Coche* c = new Coche(modelo, potencia, vmax);
                coches.push_back(c);
                escuderias[idxEsc]->agregarCoche(c);

                // Asignar piloto opcionalmente
                if (!pilotos.empty()) {
                    cout << "¿Quieres asignar un piloto a este coche? (1=si, 0=no): ";
                    int resp;
                    cin >> resp;
                    if (resp == 1) {
                        cout << "Pilotos disponibles:\n";
                        for (size_t i = 0; i < pilotos.size(); ++i) {
                            cout << i + 1 << ". " << pilotos[i]->getNombre() << "\n";
                        }
                        int idxPil = leerEntero("Elige piloto: ") - 1;
                        if (idxPil >= 0 && idxPil < (int)pilotos.size()) {
                            c->asignarPiloto(pilotos[idxPil]);
                            cout << "Piloto asignado al coche.\n";
                        } else {
                            cout << "Piloto no valido. Coche sin piloto.\n";
                        }
                    }
                }

                cout << "Coche creado.\n";
                break;
            }

            //CREAR CIRCUITO
            case 4: {
                string nombre, pais;
                int longitud, vueltas;

                nombre   = leerLinea("Nombre del circuito: ");
                pais     = leerLinea("Pais del circuito: ");
                longitud = leerEntero("Longitud (m): ");
                vueltas  = leerEntero("Numero de vueltas: ");

                Circuito* cir = new Circuito(nombre, pais, longitud, vueltas);
                circuitos.push_back(cir);

                cout << "Circuito creado.\n";
                break;
            }

            //CREAR CARRERA
            case 5: {
                if (circuitos.empty()) {
                    cout << "Primero debes crear al menos un circuito.\n";
                    break;
                }

                cout << "\nCircuitos disponibles:\n";
                for (size_t i = 0; i < circuitos.size(); ++i) {
                    cout << i + 1 << ". " << circuitos[i]->getNombre()
                         << " (" << circuitos[i]->getPais() << ")\n";
                }
                int idxC = leerEntero("Elige circuito para la carrera: ") - 1;

                if (idxC < 0 || idxC >= (int)circuitos.size()) {
                    cout << "Circuito no valido.\n";
                    break;
                }

                // Carrera recibe una referencia al circuito
                Carrera* car = new Carrera(*circuitos[idxC]);
                carreras.push_back(car);
                campeonato.agregarCarrera(car);

                // añado todas las escuderias 
                for (Escuderia* e : escuderias) {
                    car->agregarEscuderia(e);
                }

                cout << "Carrera creada y escuderias añadidas.\n";
                break;
            }

            //REGISTRAR RESULTADOS
            case 6: {
                if (carreras.empty()) {
                    cout << "No hay carreras creadas.\n";
                    break;
                }
                if (pilotos.empty()) {
                    cout << "No hay pilotos para registrar resultados.\n";
                    break;
                }

                cout << "\nCarreras disponibles:\n";
                for (size_t i = 0; i < carreras.size(); ++i) {
                    cout << i + 1 << ". Carrera " << i + 1 << "\n";
                }
                int idxCar = leerEntero("Elige carrera: ") - 1;

                if (idxCar < 0 || idxCar >= (int)carreras.size()) {
                    cout << "Carrera no valida.\n";
                    break;
                }

                int n = leerEntero("¿Cuantos pilotos quieres clasificar?: ");
                if (n <= 0) {
                    cout << "Nada que registrar.\n";
                    break;
                }

                vector<Piloto*> clasificacion;
                for (int i = 0; i < n; ++i) {
                    cout << "\nPilotos disponibles:\n";
                    for (size_t j = 0; j < pilotos.size(); ++j) {
                        cout << j + 1 << ". " << pilotos[j]->getNombre()
                             << " (puntos actuales: " << pilotos[j]->getPuntosTotales() << ")\n";
                    }
                    int idxP = leerEntero("Indice del piloto en posicion "
                                          + to_string(i + 1) + ": ") - 1;

                    if (idxP < 0 || idxP >= (int)pilotos.size()) {
                        cout << "Piloto no valido. Se salta esta posicion.\n";
                        continue;
                    }
                    int puntos = leerEntero("Puntos obtenidos por este piloto: ");
                    pilotos[idxP]->agregarPuntos(puntos);
                    clasificacion.push_back(pilotos[idxP]);
                }

                carreras[idxCar]->registrarResultado(clasificacion);
                cout << "Resultados registrados.\n";
                break;
            }

            // MOSTRAR ESCUDERIAS
            case 7: {
                campeonato.mostrarEscuderias();
                break;
            }

            // MOSTRAR CARRERAS 
            case 8: {
                campeonato.mostrarCarreras();
                break;
            }

            // CLASIFICACION GENERAL
            case 9: {
                campeonato.mostrarClasificacionGeneral();
                break;
            }

            // GUARDAR EN FICHERO 
            case 10: {
                guardarClasificacionEnFichero(escuderias);
                break;
            }

            case 11: {
                leerClasificacionDesdeFichero();
                break;
            }
            // SALIR 
            case 0: {
                salir = true;
                break;
            }

            default:
                cout << "Opcion no valida.\n";
                break;
            }
        }

        // test obligatorio
        testBasico();
    }
    catch (exception& e) {
        cerr << "ERROR: " << e.what() << "\n";
    }

    //  LIBERAR MEMORIA DINAMICA
    for (Escuderia* e : escuderias) delete e;
    for (Piloto*    p : pilotos)    delete p;
    for (Coche*     c : coches)     delete c;
    for (Circuito*  c : circuitos)  delete c;
    for (Carrera*   c : carreras)   delete c;

    return 0;
}