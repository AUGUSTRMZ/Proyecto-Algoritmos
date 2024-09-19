#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// estructura Estudiante, almacena la información de cada estudiante
struct Estudiante
{
    string nombre;      // Nombre del estudiante
    int matricula;      // Matrícula única del estudiante (solo funciona con numeros)
    float calificacion; // Calificacion del estudiante
};

// Función para agregar un estudiante al vector de estudiantes
void agregarEstudiante(vector<Estudiante> &estudiantes)
{
    Estudiante nuevo; // Se crea una nueva instancia de Estudiante
    cout << "Ingrese nombre: ";
    cin >> nuevo.nombre; // Entrada del nombre del estudiante
    cout << "Ingrese matrícula: ";
    cin >> nuevo.matricula; // Entrada de la matrícula del estudiante
    cout << "Ingrese calificación: ";
    cin >> nuevo.calificacion;    // Entrada de la calificación del estudiante
    estudiantes.push_back(nuevo); // Se agrega el nuevo estudiante al vector
    cout << "Estudiante agregado exitosamente.\n";
}

// Función para eliminar un estudiante por matrícula
void eliminarEstudiante(vector<Estudiante> &estudiantes, int matricula)
{
    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it)
    { // Se itera sobre el vector
        if (it->matricula == matricula)
        {                          // Si la matrícula coincide
            estudiantes.erase(it); // Se elimina el estudiante
            cout << "Estudiante eliminado exitosamente.\n";
            return; // Salimos de la función
        }
    }
    cout << "Estudiante no encontrado.\n"; // Mensaje si no se encuentra el estudiante
}

// Función para modificar los datos de un estudiante
void modificarEstudiante(vector<Estudiante> &estudiantes, int matricula)
{
    for (auto &estudiante : estudiantes)
    { // Se itera sobre el vector
        if (estudiante.matricula == matricula)
        { // Si la matrícula coincide
            cout << "Ingrese el nuevo nombre: ";
            cin >> estudiante.nombre; // Se modifica el nombre
            cout << "Ingrese la nueva calificación: ";
            cin >> estudiante.calificacion; // Se modifica la calificación
            cout << "Estudiante modificado exitosamente.\n";
            return;
        }
    }
    cout << "Estudiante no encontrado.\n"; // Mensaje si no se encuentra el estudiante
}

// Función para buscar un estudiante por matrícula y mostrar sus datos
void buscarEstudiante(const vector<Estudiante> &estudiantes, int matricula)
{
    for (const auto &estudiante : estudiantes)
    { // Se itera sobre el vector
        if (estudiante.matricula == matricula)
        { // Si la matrícula coincide
            // Se muestran los datos del estudiante
            cout << "Nombre: " << estudiante.nombre << endl;
            cout << "Matrícula: " << estudiante.matricula << endl;
            cout << "Calificación: " << estudiante.calificacion << endl;
            return;
        }
    }
    cout << "Estudiante no encontrado.\n"; // Mensaje si no se encuentra el estudiante
}

// Bubble Sort para ordenar por nombre
void ordenarPorNombre(vector<Estudiante> &estudiantes)
{
    for (size_t i = 0; i < estudiantes.size() - 1; ++i)
    {
        for (size_t j = 0; j < estudiantes.size() - i - 1; ++j)
        {
            // Se compara el nombre del estudiante actual con el siguiente
            if (estudiantes[j].nombre > estudiantes[j + 1].nombre)
            {
                swap(estudiantes[j], estudiantes[j + 1]); // Se swapean los estudiantes
            }
        }
    }
    cout << "Estudiantes ordenados por nombre.\n";
}

// Bubble Sort para ordenar por calificacion
void ordenarPorCalificacion(vector<Estudiante> &estudiantes)
{
    for (size_t i = 0; i < estudiantes.size() - 1; ++i)
    {
        for (size_t j = 0; j < estudiantes.size() - i - 1; ++j)
        {
            // Se compara la calificación del estudiante actual con la del siguiente
            if (estudiantes[j].calificacion < estudiantes[j + 1].calificacion)
            {
                swap(estudiantes[j], estudiantes[j + 1]); // Se swapean los estudiantes
            }
        }
    }
    cout << "Estudiantes ordenados por calificación.\n";
}

// Función para mostrar todos los estudiantes registrados
void mostrarEstudiantes(const vector<Estudiante> &estudiantes)
{
    if (estudiantes.empty())
    { // Si el vector está vacío
        cout << "No hay estudiantes registrados.\n";
        return;
    }
    // Se itera sobre el vector y se muestran los datos de cada estudiante
    for (const auto &estudiante : estudiantes)
    {
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Matrícula: " << estudiante.matricula << endl;
        cout << "Calificación: " << estudiante.calificacion << endl;
    }
}

#endif // Fin de la directiva para evitar múltiples inclusiones
