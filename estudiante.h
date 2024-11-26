#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <sstream>
#include <stdexcept>

using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
Node *merge(Node *left, Node *right) // merge sort para la lista doblemente ligada
{
  if (!left)
  {
    return right;
  }
  if (!right)
  {
    return left;
  }
  // seleccion del nodo menor como cabeza de la lista
  if (left->calificacion <= right->calificacion)
  {
    left->sig = merge(left->sig, right);
    left->sig->ant = left;
    left->ant = nullptr;
    return left;
  }
  else
  {
    right->sig = merge(left, right->sig);
    right->sig->ant = right;
    right->ant = nullptr;
    return right;
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Node *split(Node *head) {}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Node *mergesort(Node *head) {}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
  void actualizarEstudiante()
  {
    if (head == nullptr) // si la lista esta vacia
    {
      cout << "No hay estudiantes registrados en la lista" << endl;
      return;
    }

    int index;
    cout << "Ingresa el indice del estudiante a actualizar: ";
    cin >> index;

    Node *actual = head; // iniciamos en la cabeza de la lista
    int actIndex = 0;    // indice actual

    while (actual != nullptr && actIndex < index) // mientras que el ndo actual no este vacio y el indice actual sea menor al indice que se esta buscando
    {
      actual = actual->sig;
      ++actIndex;
    }
    if (actual == nullptr) // el indice esta fuera de rango
    {
      throw out_of_range("Indice fuera del rango");
      return;
    }

    // solicia la nueva calificacion del alumno
    float Ncalificacion;
    cout << "Ingese la nueva calificacion para " << actual->nombre << ": ";
    cin >> Ncalificacion;

    // Actualiza la nueva calificacion
    actual->calificacion = Ncalificacion;
    // mensaje de confirmacion con la nueva calificacion ingresada
    cout << endl;
    cout << "Calificacion actualizada para " << actual->nombre << endl;
    cout << "Su nueva calificacion es: " << actual->calificacion << endl;
    merge_estudiantes();
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void eliminarEstudiante()
  {
    if (head == nullptr) // si la lista esta vacia
    {
      cout << "No hay estudiantes registrados en la lista" << endl;
      return;
    }
    int index;
    cout << "Ingrese el indice del estudiante que desea eliminar: ";
    cin >> index;

    Node *actual = head; // iniciamos la lista en la cabeza
    int actIndex = 0;    // indice actual de busqueda

    // Recorrer la lista hasta encontrar el indice que se busca
    while (actual != nullptr && actIndex < index) // mientras no se llegue al final de la lista y el indice actual no sea el que se busca
    {
      actual = actual->sig;
      ++actIndex;
    }
    if (actual == nullptr) // si el indice esta fuera del rango
    {
      throw out_of_range("Indice fuera del rango de la lista");
      return;
    }

    // Ajuste de punteros hacia atras
    if (actual->ant != nullptr) // si el nodo no es el primero de la lista
    {
      actual->ant->sig = actual->sig; // el actual se vuelve el previo y se conecta al siguiente
    }
    else
    {
      head = actual->sig; // actualiza la cabeza de la lista si era el primero
    }
    // Ajuste de punteros hacia adelante
    if (actual->sig != nullptr) // si el nodo no es el ultimo
    {
      actual->sig->ant = actual->ant; // el actual se vuelvel siguiente y se conecta al anterior
    }
    else // si es el ultimo
    {
      tail = actual->ant; // actualiza la cola de la lista
    }

    // Libera la memoria del nodo eliminado
    delete actual;
    cout << "Estudiante " << actual->nombre << " eliminado con exito" << endl;
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
};
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
};
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

void searchEstudiante() {}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
FUNCION que despliega el menu principal para visualizar el funcionamiento del prototipo
*/
void main_menu()
{
  vector<Estudiante> estudiantes; // vector que almacena la informacion ingresada
  ListDubl lista;                 // lista doblemente enlazada para almacenar informacion ingresada
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
            animacionMensaje("Volviendo al menu principal...");
            break;

          default:
            cout << "opcion no valida, porfavor intente de nuevo." << endl;
            break;
          }

        } while (desplace != 'c');
      }
      break;
    case 6:
      lista.actualizarEstudiante();
      break;
    case 7:
      lista.eliminarEstudiante();
      break;
    case 8:
      animacionMensaje("Saliendo del sistema...");
      break;

    default:
      cout << "Opcion no valida, intente de nuevo" << endl;
    }
  } while (eleccion != 8);
};

#endif // ESTUDIANTE_H
