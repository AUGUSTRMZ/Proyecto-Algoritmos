# Sistema de Gestión de Estudiantes en C++

## Descripción del Proyecto

Este proyecto es un **Sistema de Gestión de Estudiantes** desarrollado en C++ que permite agregar, modificar, eliminar, buscar, ordenar y visualizar registros de estudiantes. Cada registro incluye el **nombre**, **matrícula** y **calificación** de los estudiantes, y todas las operaciones se ejecutan desde la terminal utilizando la estructura dinámica `vector` para almacenar los registros.

### Funcionalidades Principales:
1. **Agregar Estudiantes**: Permite ingresar un nuevo estudiante con su nombre, matrícula y calificación.
2. **Eliminar Estudiantes**: Elimina un estudiante buscando por su matrícula.
3. **Modificar Estudiantes**: Actualiza los datos de un estudiante existente.
4. **Buscar Estudiantes**: Busca un estudiante por matrícula y muestra su información.
5. **Ordenar Estudiantes**:
   - **Por Nombre**: Ordena a los estudiantes alfabéticamente utilizando **Bubble Sort**.
   - **Por Calificación**: Ordena a los estudiantes de mayor a menor calificación utilizando **Bubble Sort**.
6. **Mostrar Todos los Estudiantes**: Imprime una lista de todos los estudiantes registrados en el sistema.

---

## Algoritmos de Ordenamiento Utilizados

### **Bubble Sort** (Ordenamiento de Burbuja)

Este proyecto emplea el algoritmo de ordenamiento **Bubble Sort** para dos tareas específicas:
- **Ordenar por Nombre**: Los registros de los estudiantes se organizan en orden alfabético según el nombre.
- **Ordenar por Calificación**: Los estudiantes se ordenan en orden descendente según su calificación.

El **Bubble Sort** es fácil de implementar y comprender, pero tiene una complejidad de tiempo **O(n²)**, lo que lo hace menos eficiente para grandes cantidades de datos. Para este proyecto, es una elección adecuada, ya que las listas de estudiantes manejadas suelen ser pequeñas.

---

## Expansión del Proyecto

Este proyecto está diseñado como una base que se expandirá conforme a las **necesidades del curso**. A medida que se avancen en los contenidos de la materia, se irán incorporando nuevas funcionalidades y optimizaciones que permitirán:
- **Mejorar el rendimiento**: Se podrán introducir nuevos algoritmos de ordenamiento más eficientes, o estructuras de datos que optimicen las búsquedas y la manipulación de registros.
- **Aumentar la capacidad del sistema**: La inclusión de persistencia de datos (lectura/escritura desde archivos) podría añadirse si el curso lo requiere.
- **Incorporar validación avanzada de entradas**: A medida que se profundice en temas de validación y manejo de errores, el programa podría ampliarse para incluir validaciones más robustas sobre los datos ingresados por los usuarios.

**Disclaimer IMPORTANTE!!!!**
Sobre las matriculas, solo acepta numeros enteros favor de no poner letras ni simbolos especiales o el programa devolvera un error
  
