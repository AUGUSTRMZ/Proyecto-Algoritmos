#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <sstream>
#include <stdexcept>
#include <fstream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Estudiante // creacion de struct de estudiante
{
  string nombre;      // nombre del estudiante
  float calificacion; // calificacion de estudiante
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node // Nodos de la lista enlazada
{
  string nombre;      // Nombre del estudiante
  float calificacion; // calificacion del estudiante
  Node *sig;          // Apuntador al siguiente elemento
  Node *ant;          // Apuntador al anterior elemento
  // constructor para inicializar los nodos
  Node(string nom, float calif) : nombre(nom), calificacion(calif), sig(nullptr), ant(nullptr) {}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void merge_estudiantes(vector<Estudiante> &estudiantes);

class ListDubl
{
private:
  Node *head; // Primer nodo de la lista
  Node *tail; // Ultimo nodo de la lista

public:
  // constructor de la clase
  ListDubl() : head(nullptr), tail(nullptr) {}

  // Destructor limpia los nodos
  ~ListDubl()
  {
    Node *actual = head;
    while (actual != nullptr)
    {
      Node *temp = actual;
      actual = actual->sig;
      delete temp;
    }
  }
  Node *getHead()
  {
    return head;
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  // Metodo para insertar a la lista
  void insert(string nombre, float calificacion)
  {
    Node *nuevo = new Node(nombre, calificacion);
    if (head == nullptr) // si la lista esta vacia
    {
      head = tail = nuevo;
    }
    else // si la lista si tiene elementos
    {
      tail->sig = nuevo;
      nuevo->ant = tail;
      tail = nuevo;
    }
  }

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void actualizarEstudiante(vector<Estudiante> &estudiantes)
  {
    string nombreBuscar; // se busca al estudiante por nombre
    cout << "Ingrese el nombre del estudiante que desea actualizar: ";
    cin.ignore();
    getline(cin, nombreBuscar);

    bool found = false;           // bandera que indica si el estudiante fue encontrado, esta en false por defecto
    for (auto &est : estudiantes) // recorrer todo el vector de estudiantes
    {
      if (est.nombre == nombreBuscar) // si el nombre del estudiante actual es igual al que se busca
      {
        found = true;                                                        // la bandera cambia a true
        cout << "Ingrese la nueva calificacion para " << est.nombre << ": "; // se pide la nueva calificacion
        cin >> est.calificacion;                                             // se recibe la nueva calificacion
        break;
      }
    }
    if (found) // cuando la bandera este en true
    {
      merge_estudiantes(estudiantes);     // se vuelve a ordenar el vector ahora actualizado
      *this = ListDubl();                 // limpia la lista doble actual
      for (const auto &est : estudiantes) // recorre todo el vector de estudiantes
      {
        insert(est.nombre, est.calificacion); // se inserta el nuevo vector reordenado
      }
      cout << "Estudiante actualizado y base de datos organizada exitosamente" << endl;
    }
    else
    {
      cout << "Estudiante no encontrado" << endl;
    }
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void eliminarEstudiante(vector<Estudiante> &estudiantes)
  {
    string nombreBuscar;                                     // se busca al estudiante por nombre
    cout << "Ingrese el nombre del estudiante a eliminar: "; // se pide el nombre del estudiante
    cin.ignore();
    getline(cin, nombreBuscar); // se recibe el nombre del estudiante

    bool found = false;                                                // bandera que me indica si alumno fue encontrado
    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) // uso de iteradores para mantenerse buscando solo dentro del vector
    {
      if (it->nombre == nombreBuscar) // si el nombre actual es del alumno que se desea eliminar
      {
        estudiantes.erase(it); // Elimina el estudiante al que apunta el iterador del vector
        found = true;          // la bandera cambia a true
        break;                 // el bucle termina cuando se elimina el estudiantes
      }
    }
    if (found) // si la bandera es true
    {
      merge_estudiantes(estudiantes);     // reordena el vector de estudiantes nuevamente
      *this = ListDubl();                 // reinicia la lista
      for (const auto &est : estudiantes) // recorre todo el vector estudiantes
      {
        insert(est.nombre, est.calificacion); // inserta los nuevos datos en la lista
      }
      cout << "Estudiante eliminado y base de datos organizada exitosamente" << endl;
    }
    else
    {
      cout << "Estudiante no encontrado" << endl;
    }
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void next()
  {
    Node *actual = head;
    while (actual != nullptr)
    {
      cout << "=================================================" << endl;
      cout << "Nombre: " << actual->nombre << endl;
      cout << "Calificacion: " << actual->calificacion << endl;
      actual = actual->sig;
      cout << "=================================================" << endl;
      cout << endl;
    }
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void previous()
  {
    Node *actual = tail;
    while (actual != nullptr)
    {
      cout << "=================================================" << endl;
      cout << "Nombre: " << actual->nombre << endl;
      cout << "Calificacion: " << actual->calificacion << endl;
      actual = actual->ant;
      cout << "=================================================" << endl;
      cout << endl;
    }
  }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void animacionMensaje(string mensaje) // Mensaje de saliendo del sistema con animaciones
{
  for (char c : mensaje) // itera sobre cada caracter del mensaje de salida
  {
    cout << c; // imprime cada caracter del mensaje
    cout.flush();
    this_thread::sleep_for(chrono::milliseconds(100)); // pausa de 100 milisegundos entre caracter
  }
  cout << endl; // salto de linea despues del mensaje
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ingresarDatos(vector<Estudiante> &estudiantes)
{
  int cantidad;                                          // cantidad de alumnos que se ingresaran al elemento
  cout << "Ingrese la cantidad de alumnos a ingresar: "; // cantidad de estudiantes que se eingresaran
  cin >> cantidad;                                       // lectura del valor

  for (int i = 0; i < cantidad; i++)
  {
    Estudiante estudiante;                                        // instancia en la estructura estudiante
    cout << "Ingrese el nombre del estudiante " << i + 1 << ": "; // se pide que se ingrese el nombre del estudiante
    cin.ignore();
    getline(cin, estudiante.nombre); // leer el nombre del estudiante
    cout << "Ingrese la calificacion de " << estudiante.nombre << ": ";
    cin >> estudiante.calificacion;
    estudiantes.push_back(estudiante); // Agrego los estudiantes ingresados al vector
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// llamada a las funciones antes de para poder usarlas sin problemas
void mergeRecursion_estudiantes(vector<Estudiante> &estudiantes, int left, int right);
void mergeSorted_estudiantes(vector<Estudiante> &estudiantes, int left, int middle, int right);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
FUNCION que muestra todos los estudiantes dentro del vector junto con sus calificaciones
*/
void printEstudiantes(const vector<Estudiante> &estudiantes)
{
  for (const auto &est : estudiantes) // itera sobre cada estudiante del vector
  {
    cout << "============================================" << endl;
    cout << "Nombre: " << est.nombre << endl;
    cout << "Calificacion: " << est.calificacion << endl;
    cout << "============================================" << endl;
    cout << endl;
  }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void merge_estudiantes(vector<Estudiante> &estudiantes)
{
  mergeRecursion_estudiantes(estudiantes, 0, estudiantes.size() - 1);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mergeRecursion_estudiantes(vector<Estudiante> &estudiantes, int left, int right)
{
  if (left >= right) // condicion para terminar la recursion
  {
    return; // termina cuando no hay mas elementos en el vector o solo uno
  }
  int middle = left + (right - left) / 2;                     // punto medio
  mergeRecursion_estudiantes(estudiantes, left, middle);      // mitad izquierda del arreglo
  mergeRecursion_estudiantes(estudiantes, middle + 1, right); // mitad derecha del arreglo
  mergeSorted_estudiantes(estudiantes, left, middle, right);  // juntar ambas mitades
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mergeSorted_estudiantes(vector<Estudiante> &estudiantes, int left, int middle, int right)
{
  int left_side = middle - left + 1; // Porción izquierda del arreglo
  int right_side = right - middle;   // Porción derecha del arreglo

  // Subarreglos temporales para el lado izquierdo y derecho
  vector<Estudiante> temp_left(left_side);
  vector<Estudiante> temp_right(right_side);

  // Llenar los subarreglos temporales con datos del vector original
  for (int i = 0; i < left_side; i++)
  {
    temp_left[i] = estudiantes[left + i]; // pasar la porcion izquierda al arreglo temporal
  }
  for (int i = 0; i < right_side; i++)
  {
    temp_right[i] = estudiantes[middle + 1 + i]; // pasar la porcion derecha al arreglo temporal
  }

  // Combinar los subarreglos
  int i = 0, j = 0, k = left;             // indice de porcion izquierda, derecha y vector orignal
  while (i < left_side && j < right_side) // mientras los indices no se pasen de sus limites por porcion correspondiente
  {
    if (temp_left[i].calificacion <= temp_right[j].calificacion) // si la califacion en el indice i es menor que en el indice j
    {
      estudiantes[k] = temp_left[i]; // al vector original en el indice k se le pasa el valor que esta en el indice i
      i++;                           // los indices aumentan en 1 para comparar el siguiente dato
    }
    else // caso contrario
    {
      estudiantes[k] = temp_right[j]; // al vector original en el indice k se le pasa el valor en el indice j
      j++;                            // los indices aumentan en 1 para comparar el siguiente dato
    }
    k++; // el indice k aumenta para no pegar todo en el mismo lugar del vector
  }

  // Copiar los elementos restantes del lado izquierdo (si los hay)
  while (i < left_side) // mientras i siga siendo menor que su porcion izquierda
  {
    estudiantes[k] = temp_left[i]; // se siguen copiando los elementos del lado izquierdo
    i++;                           // aumentan los indides para progresar en el vector
    k++;
  }

  // Copiar los elementos restantes del lado derecho (si los hay)
  while (j < right_side) // mismo caso pero con el indice j y la porcion derecha
  {
    estudiantes[k] = temp_right[j];
    j++;
    k++;
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loadTXT(const string &txt_name, vector<Estudiante> &estudiantes) // carga los datos desde el archivo usando el nombre del archivo como parametro string y usando el vector de estudiantes
{
  ifstream file(txt_name); // abre el archivo en modo lectura
  if (!file.is_open())     // Verifica si se abrio correctamente
  {
    cout << "No se pudo abrir el archivo " << txt_name << endl; // si no se abrio pues sale esto
    return;
  }

  estudiantes.clear(); // limpia el vector antes de cargar cualquier dato nuevo
  string line;

  while (getline(file, line)) // leer linea por linea
  {
    stringstream ss(line);
    string nombre;
    float calificacion;

    // Leer nombre y calificacion separados por coma
    getline(ss, nombre, ','); // leer nombre hasta la coma
    ss >> calificacion;       // leer la calificacion

    // Agregar al vector
    Estudiante est;
    est.nombre = nombre;
    est.calificacion = calificacion;
    estudiantes.push_back(est);
  }
  file.close(); // cerrar el archivo
  cout << "Datos cargados desde " << txt_name << "Exitosamente" << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// guarda los datos en archivo con el nombre del archivo y el vector estudiantes
void saveOnFile(const string &txt_name, const vector<Estudiante> &estudiantes)
{
  ofstream file(txt_name); // Arbre el archivo en modo escritura
  if (!file.is_open())     // verificar que se abra bien el archivo
  {
    cout << "No se pudo abrir el archivo" << txt_name << endl;
    return;
  }
  for (const auto &est : estudiantes) // recorre todo el vector estudiantes
  {
    file << est.nombre << "," << est.calificacion << endl; // escribir en el formato "nombre, calificacion"
  }
  file.close(); // cerrar el archivo
  cout << "Datos guardados en " << txt_name << " exitosamente." << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
FUNCION que despliega el menu principal para visualizar el funcionamiento del prototipo
*/
void main_menu()
{
  vector<Estudiante> estudiantes;          // vector que almacena la informacion ingresada
  ListDubl lista;                          // lista doblemente enlazada para almacenar informacion ingresada
  loadTXT("estudiantes.txt", estudiantes); // cargo los datos del txt

  int eleccion;

  do
  {
    cout << "=== Sistema de estudiantes ===" << endl;
    cout << "Seleccione una accion a realizar" << endl;
    cout << "1. Ingresar estudiante(s)" << endl;
    cout << "2. Mostrar estudiantes" << endl;
    cout << "3. Ordenar por calificacion" << endl;
    cout << "4. Subir los datos a la lista de alumnos" << endl;
    cout << "5. Examinar lista de alumnos" << endl;
    cout << "6. Actualizar calificacion de alumno" << endl;
    cout << "7. Eliminar alumno" << endl;
    cout << "8. Salir del programa" << endl;
    cout << endl;
    cout << "Ingrese su eleccion: ";
    cin >> eleccion;

    switch (eleccion)
    {
    case 1:
      ingresarDatos(estudiantes);
      saveOnFile("estudiantes.txt", estudiantes);
      break;
    case 2:
      if (estudiantes.empty())
      {
        cout << "No hay estudiantes registrados" << endl;
        break;
      }
      else
      {
        printEstudiantes(estudiantes);
        break;
      }
    case 3:
      if (estudiantes.empty())
      {
        cout << "No hay estudiantes registrados" << endl;
        break;
      }
      else
      {
        merge_estudiantes(estudiantes);
        cout << "Estudiantes ordenados con exito" << endl;
        saveOnFile("estudiantes.txt", estudiantes);
        break;
      }
    case 4:
      if (estudiantes.empty())
      {
        cout << "No hay estudiantes registrados" << endl;
      }
      else
      {
        lista = ListDubl(); // reinicio de lista para evitar duplicados
        for (const auto &est : estudiantes)
        {
          lista.insert(est.nombre, est.calificacion);
        }
        cout << "Datos trasladados a la base de datos de alumnos(lista doble)" << endl;
      }
      break;

    case 5:
      if (lista.getHead() == nullptr)
      {
        cout << "Aun no se ingresan alumnos a la lista" << endl;
      }
      else
      {
        Node *actual = lista.getHead();
        char desplace;
        do
        {
          cout << "============================================" << endl;
          cout << "Alumno actual" << endl;
          cout << "Nombre: " << actual->nombre << endl;
          cout << "Calificacion: " << actual->calificacion << endl;
          cout << "============================================" << endl;

          cout << "Escriba 's' para pasar al siguiente alumno" << endl;
          cout << "Escriba 'a' para volver al alumno anterior" << endl;
          cout << "Escriba 'c' para cerrar este menu y volver al menu principal" << endl;
          cout << "Ingrese su eleccion: ";
          cin >> desplace;

          switch (desplace)
          {
          case 's':
            if (actual->sig != nullptr)
            {
              actual = actual->sig;
            }
            else
            {
              cout << "no hay mas alumnos en la lista" << endl;
            }
            break;
          case 'a':
            if (actual->ant != nullptr)
            {
              actual = actual->ant;
            }
            else
            {
              cout << "No hay mas alumnos antes de este" << endl;
            }
            break;
          case 'c':
            cout << "Volviendo al menu principal..." << endl;
            break;

          default:
            cout << "opcion no valida, porfavor intente de nuevo." << endl;
            break;
          }

        } while (desplace != 'c');
      }
      break;
    case 6:
      if (estudiantes.empty())
      {
        cout << "No hay estudiantes registrados" << endl;
      }
      else
      {
        lista.actualizarEstudiante(estudiantes);
        saveOnFile("estudiantes.txt", estudiantes);
      }
      break;
    case 7:
      if (estudiantes.empty())
      {
        cout << "No hay estudiantes registrados" << endl;
      }
      else
      {
        lista.eliminarEstudiante(estudiantes);
        saveOnFile("estudiantes.txt", estudiantes);
      }
      break;
    case 8:
      saveOnFile("estudiantes.txt", estudiantes);
      cout << "Datos guardados, saliendo del sistema..." << endl;
      break;

    default:
      cout << "Opcion no valida, intente de nuevo" << endl;
    }
  } while (eleccion != 8);
};

#endif // ESTUDIANTE_H
