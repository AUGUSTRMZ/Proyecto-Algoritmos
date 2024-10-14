#include <iostream>
#include <vector>
#include "estudiante.h"

using namespace std;

// Función para ordenar los estudiantes por nombre (alfabéticamente)
void bubbleSortNombre(vector<Estudiante> &estudiantes)
{
    for (size_t i = 0; i < estudiantes.size() - 1; i++)
    {
        for (size_t j = 0; j < estudiantes.size() - i - 1; j++)
        {
            if (estudiantes[j].nombre > estudiantes[j + 1].nombre)
            {
                swap(estudiantes[j], estudiantes[j + 1]);
            }
        }
    }
    cout << "Estudiantes ordenados alfabéticamente con exito!.\n";
}

// Función para ordenar los estudiantes por calificación
void bubbleSortCalificacion(vector<Estudiante> &estudiantes)
{
    for (size_t i = 0; i < estudiantes.size() - 1; i++)
    {
        for (size_t j = 0; j < estudiantes.size() - i - 1; j++)
        {
            if (estudiantes[j].calificacion > estudiantes[j + 1].calificacion)
            {
                swap(estudiantes[j], estudiantes[j + 1]);
            }
        }
    }
    cout << "Estudiantes ordenados por calificación con exito!.\n";
}

int main()
{
    vector<Estudiante> estudiantes;
    ListaDoble listaEstudiantes;
    Nodo *actual = nullptr; // Para navegación en la lista doblemente ligada
    int opcion;

    do
    {
        cout << "\nMenu principal:\n";
        cout << "1. Agregar estudiante al registro\n";
        cout << "2. Agregar estudiante a la lista\n";
        cout << "3. Mostrar registro de estudiantes\n";
        cout << "4. Mostrar estudiantes de la lista\n";
        cout << "5. Ordenar estudiantes por nombre (alfabéticamente)\n";
        cout << "6. Ordenar estudiantes por calificación\n";
        cout << "7. Siguiente estudiante en la lista \n";
        cout << "8. Estudiante anterior en la lista\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarEstudiante(estudiantes); // Función original para agregar al vector
            break;
        case 2:
        {
            Estudiante nuevo;
            cout << "Ingrese nombre: ";
            cin >> nuevo.nombre;
            cout << "Ingrese matrícula: ";
            cin >> nuevo.matricula;
            cout << "Ingrese calificación: ";
            cin >> nuevo.calificacion;
            listaEstudiantes.agregarEstudiante(nuevo);
            if (!actual)
                actual = listaEstudiantes.getCabeza(); // Iniciar la navegación si es el primer estudiante
            break;
        }
        case 3:
            mostrarEstudiantes(estudiantes); // Mostrar estudiantes del vector
            break;
        case 4:
            listaEstudiantes.mostrarEstudiantes(); // Mostrar estudiantes de la lista doblemente ligada
            break;
        case 5:
            bubbleSortNombre(estudiantes);   // Ordenar estudiantes por nombre
            mostrarEstudiantes(estudiantes); // Mostrar estudiantes ordenados
            break;
        case 6:
            bubbleSortCalificacion(estudiantes); // Ordenar estudiantes por calificación
            mostrarEstudiantes(estudiantes);     // Mostrar estudiantes ordenados
            break;
        case 7:
            if (actual)
                listaEstudiantes.siguiente(actual); // Navegar al siguiente estudiante
            else
                cout << "La lista está vacía o no se ha ingresado ningún estudiante.\n";
            break;
        case 8:
            if (actual)
                listaEstudiantes.anterior(actual); // Navegar al estudiante anterior
            else
                cout << "La lista está vacía o no se ha ingresado ningún estudiante.\n";
            break;
        case 0:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción inválida, intente nuevamente.\n";
            break;
        }
    } while (opcion != 0);

    return 0;
}
