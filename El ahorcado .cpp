#include <iostream>
#include <cstdlib>  // Para la función system()
#include <ctime>    // Para la función time()
#include <algorithm>

using namespace std;

// Funciones usadas en el juego
void LimpiarPantalla();
void JugarPartida();
void MostrarPuntajes();
void MostrarCreditos();
void Dibujar();

// Estructura usada para almacenar los datos de cada jugador
struct Jugador {
    string nombre;
    int puntaje;
};

Jugador jugadores[3];
int numJugadores = 0;
char eleccion;
string palabras[] = {"carro", "mariposa", "ventilador", "corona", "fantasma", "gato", "aeropuerto", "universidad", "politecnico", "computacion"}; // Todas las palabras que se usarán aleatoriamente en el juego
string palabra;
int numeroA;
int vida;
bool correcta, completa;

// Función de comparación fuera de la función MostrarPuntajes
bool CompararJugadores(const Jugador& a, const Jugador& b) {
    return a.puntaje > b.puntaje;
}

// Función que se ejecutará al seleccionar la opción 1
void JugarPartida() {
    if (numJugadores >= 3) {
        cout << "No se pueden agregar más jugadores." << endl;
        return;
    }

    string nombreJugador;
    cout << "Ingrese su nombre: ";
    cin >> nombreJugador;

    srand((int)time(NULL));
    numeroA = rand() % 10; // Escoje un número al azar del 0 al 9, cada número contiene una palabra

    for (int i = 0; i < (int)palabras[numeroA].size(); i++) {
        palabra += "-"; // Mide el número de letras que tiene la palabra escogida y por cada una agrega un guión
    }

    while (vida > 0) {
        LimpiarPantalla();
        cout << endl;
        cout << "\t  S U E R T E ! ! " << endl;
        Dibujar();
        cout << "  Tu palabra es: " << palabra << endl;
        cout << "Ingrese una letra en minuscula: ";
        cin >> eleccion;

        // Verifica si la letra ingresada por el jugador pertenece a la palabra seleccionada
        correcta = false;
        for (int i = 0; i < (int)palabras[numeroA].size(); i++) {
            if (palabras[numeroA][i] == eleccion) {
                palabra[i] = eleccion;
                correcta = true;
            }
        }
        if (!correcta) {
            vida--;
        }

        // Comprueba si se llegó a completar la palabra 
        completa = true;
        for (int i = 0; i < (int)palabra.size(); i++) {
            if (palabra[i] == '-') {
                completa = false;
            }
        }
        if (completa) {//pantalla si se llegara a ganar
            LimpiarPantalla();
            cout<<endl;
            cout << "\t    F E L I C I T A C I O N E S  ! ! !" << endl;
            cout << "\t               GANASTE!!" << endl;
            Dibujar();
            cout << "Palabra: " << palabras[numeroA] << endl;
            cout << "Presiona cualquier tecla para continuar: ";
            cin >> eleccion;

            // Guarda el nuevo puntaje obtenido en el nombre del jugador
            jugadores[numJugadores++] = {nombreJugador, vida};
            return;
        }
    }

    LimpiarPantalla();
    cout << endl;//pantalla si se llega a perder
    cout << "\t S U E R T E  P A R A  L A  P R O X I M A " << endl;
    cout << "\t              PERDISTE! :( " << endl;
    Dibujar();
    cout << "La palabra era: " << palabras[numeroA] << endl;
    cout << "Presiona cualquier tecla para continuar: ";
    cin >> eleccion;

    jugadores[numJugadores++] = {nombreJugador, 0};
    return;
}

// Función que se ejecutará al seleccionar la opción 2
void MostrarPuntajes() {
    LimpiarPantalla();
    cout << "\t--- TABLA DE PUNTAJES ---" << endl;
    sort(jugadores, jugadores + numJugadores, CompararJugadores);

    for (int i = 0; i < min(3, numJugadores); i++) {
        cout << i + 1 << ". " << jugadores[i].nombre << " - " << jugadores[i].puntaje << " puntos" << endl;
    }

    cout << "Presione cualquier tecla para volver al menu: ";
    cin >> eleccion;
}

// Función que se ejecutará al seleccionar la opción 4
void MostrarCreditos() {
    LimpiarPantalla();
    cout << "\t--- CREDITOS ---" << endl;
    cout << "Juego hecho por:" << endl;
    cout << "1. Anahi Achote" << endl;
    cout << "2. Mateo Campaña" << endl;
    cout << "Presione cualquier tecla para volver al menu: ";
    cin >> eleccion;
}

//Funcion que ejecutará el dibujo de el ahorcado dependiendo del numero de veces que el jugador se equivoque
void Dibujar() {
    switch (vida) {
        case 6:
            cout << "  --------" << endl;
            cout << "  |      |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << " ---" << endl;
            break;
        case 5:
            cout << "  --------" << endl;
            cout << "  |      |" << endl;
            cout << "  |      O" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << " ---" << endl;
            break;
        case 4:
            cout << "  --------" << endl;
            cout << "  |      |" << endl;
            cout << "  |      O" << endl;
            cout << "  |      |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << " ---" << endl;
            break;
        case 3:
            cout << "  --------" << endl;
            cout << "  |      |" << endl;
            cout << "  |      O" << endl;
            cout << "  |     /|" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << " ---" << endl;
            break;
        case 2:
            cout << "  --------" << endl;
            cout << "  |      |" << endl;
            cout << "  |      O" << endl;
            cout << "  |     /|\\" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << " ---" << endl;
            break;
        case 1:
            cout << "  --------" << endl;
            cout << "  |      |" << endl;
            cout << "  |      O" << endl;
            cout << "  |     /|\\" << endl;
            cout << "  |     /" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << " ---" << endl;
            break;
        case 0:
            cout << "  --------" << endl;
            cout << "  |      |" << endl;
            cout << "  |      O" << endl;
            cout << "  |     /|\\" << endl;
            cout << "  |     / \\" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << " ---" << endl;
            break;
    }
}

//Funcion que limpia la pantalla
void LimpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//Funcion Principal
int main() {
    while (true) {
        vida = 6;
        palabra = "";
        LimpiarPantalla();
        cout << "---Escuela Politecnica Nacional---" << endl;
        cout << "\t   *   Programacion   *" << endl;
        cout << "\t      PROYECTO FINAL " << endl;
        cout << "\t     *    Grupo 1   *" << endl;
        cout << endl;
        cout << "\t   EL AHORCADO   " << endl;
        cout << "\t    - MENU -" << endl;
        cout << "1) Comenzar a jugar" << endl;
        cout << "2) Mostrar todos los puntajes" << endl;
        cout << "3) Salir" << endl;
        cout << "4) Creditos" << endl;
        cout << "Escoja una opcion: ";
        cin >> eleccion;

        switch (eleccion) {
            case '1':
                JugarPartida();
                break;
            case '2':
                MostrarPuntajes();
                break;
            case '3':
                return 0; //Se termina de ejecutar el programa 
            case '4':
                MostrarCreditos();
                break;
            default:
                cout << "Opción no válida. Ingrese un numero del 1 al 4." << endl;
                break;
        }
    }
}

