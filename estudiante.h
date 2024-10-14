#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;
//Cesar Augusto Ramirez Davila 
//A01712439
// Estructura Estudiante, almacena la información de cada estudiante
struct Estudiante
{
    string nombre;      // Nombre del estudiante
    int matricula;      // Matrícula única del estudiante
    float calificacion; // Calificación del estudiante
};

// Función para agregar un estudiante al vector de estudiantes
void agregarEstudiante(vector<Estudiante> &estudiantes)
{
    Estudiante nuevo;
    cout << "Ingrese nombre: ";
    cin >> nuevo.nombre;
    cout << "Ingrese matrícula: ";
    cin >> nuevo.matricula;
    cout << "Ingrese calificación: ";
    cin >> nuevo.calificacion;
    estudiantes.push_back(nuevo);
    cout << "Estudiante agregado exitosamente.\n";
}

// Función para mostrar los estudiantes del vector
void mostrarEstudiantes(const vector<Estudiante> &estudiantes)
{
    for (const auto &estudiante : estudiantes)
    {
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Matrícula: " << estudiante.matricula << endl;
        cout << "Calificación: " << estudiante.calificacion << endl;
    }
}

// Definición del nodo para la lista doblemente ligada
struct Nodo
{
    Estudiante estudiante; // Información del estudiante
    Nodo *siguiente;       // Puntero al siguiente nodo
    Nodo *anterior;        // Puntero al nodo anterior

    Nodo(Estudiante est) : estudiante(est), siguiente(nullptr), anterior(nullptr) {}
};

// Definición de la lista doblemente ligada
class ListaDoble
{
private:
    Nodo *cabeza;
    Nodo *cola;

public:
    ListaDoble() : cabeza(nullptr), cola(nullptr) {}

    // Agregar un nuevo estudiante a la lista doblemente ligada
    void agregarEstudiante(Estudiante nuevo)
    {
        Nodo *nuevoNodo = new Nodo(nuevo);

        if (!cabeza)
        {
            cabeza = cola = nuevoNodo;
        }
        else
        {
            cola->siguiente = nuevoNodo;
            nuevoNodo->anterior = cola;
            cola = nuevoNodo;
        }
    }

    // Mostrar todos los estudiantes de la lista doblemente ligada
    void mostrarEstudiantes()
    {
        Nodo *actual = cabeza;
        while (actual)
        {
            cout << "Nombre: " << actual->estudiante.nombre << endl;
            cout << "Matrícula: " << actual->estudiante.matricula << endl;
            cout << "Calificación: " << actual->estudiante.calificacion << endl;
            actual = actual->siguiente;
        }
    }

    // Navegar al siguiente estudiante
    void siguiente(Nodo *&actual)
    {
        if (actual->siguiente)
        {
            actual = actual->siguiente;
            cout << "Siguiente estudiante: " << actual->estudiante.nombre << endl;
        }
        else
        {
            cout << "No hay más estudiantes adelante.\n";
        }
    }

    // Navegar al estudiante anterior
    void anterior(Nodo *&actual)
    {
        if (actual->anterior)
        {
            actual = actual->anterior;
            cout << "Estudiante anterior: " << actual->estudiante.nombre << endl;
        }
        else
        {
            cout << "No hay más estudiantes atrás.\n";
        }
    }

    Nodo *getCabeza() { return cabeza; }
};

#endif // ESTUDIANTE_H
