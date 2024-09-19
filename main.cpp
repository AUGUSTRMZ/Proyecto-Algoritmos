#include "estudiante.h" // Se incluye el archivo de cabecera que contiene las funciones y la estructura
using namespace std;

int main()
{
    vector<Estudiante> estudiantes; // Se crea un vector para almacenar estudiantes
    int opcion = 0;                 // Variable para almacenar la opción del usuario en el menú

    do
    {
        // Menú principal
        cout << "\n--- Sistema de Gestión de Estudiantes ---\n";
        cout << "1. Agregar Estudiante\n";
        cout << "2. Eliminar Estudiante\n";
        cout << "3. Modificar Estudiante\n";
        cout << "4. Buscar Estudiante\n";
        cout << "5. Ordenar Estudiantes por Nombre\n";
        cout << "6. Ordenar Estudiantes por Calificación\n";
        cout << "7. Mostrar Todos los Estudiantes\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion; // Se lee la opción seleccionada por el usuario

        // Estructura switch para gestionar las opciones seleccionadas por el usuario
        switch (opcion)
        {
        case 1:
            agregarEstudiante(estudiantes); // Llama a la función para agregar un estudiante
            break;
        case 2:
        {
            int matricula;
            cout << "Ingrese la matrícula del estudiante a eliminar: ";
            cin >> matricula;                           // Se solicita la matrícula del estudiante a eliminar
            eliminarEstudiante(estudiantes, matricula); // Se llama a la función para eliminar
            break;
        }
        case 3:
        {
            int matricula;
            cout << "Ingrese la matrícula del estudiante a modificar: ";
            cin >> matricula;                            // Se solicita la matrícula del estudiante a modificar
            modificarEstudiante(estudiantes, matricula); // Se llama a la función para modificar
            break;
        }
        case 4:
        {
            int matricula;
            cout << "Ingrese la matrícula del estudiante a buscar: ";
            cin >> matricula;                         // Se solicita la matrícula del estudiante a buscar
            buscarEstudiante(estudiantes, matricula); // Se llama a la función para buscar
            break;
        }
        case 5:
            ordenarPorNombre(estudiantes); // Llama a la función para ordenar por nombre
            break;
        case 6:
            ordenarPorCalificacion(estudiantes); // Llama a la función para ordenar por calificación
            break;
        case 7:
            mostrarEstudiantes(estudiantes); // Llama a la función para mostrar todos los estudiantes
            break;
        case 0:
            cout << "Saliendo del programa...\n"; // Opción para salir del programa
            break;
        default:
            cout << "Opción inválida, intente de nuevo.\n"; // Mensaje para opción inválida
            break;
        }
    } while (opcion != 0); // Repite el menú mientras la opción no sea salir (0)

    return 0; // Fin del programa
}
