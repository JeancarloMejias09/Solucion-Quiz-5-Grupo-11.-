# Matriz Dinámica en C

Este programa permite crear, y redimensionar matrices de enteros en memoria dinámica. Se detallan sus funcionalidades y cómo utilizarlo.

## Funcionalidades

1. **Creación de Matriz**: Genera una matriz de tamaño `filas×columnas` con valores aleatorios entre 1 y 100.
2. **Redimensionamiento**: Permite cambiar el tamaño de la matriz a `filas2×columnas2`, conservando los valores existentes y llenando las nuevas posiciones con valores aleatorios.
3. **Liberación de Memoria**: Libera toda la memoria utilizada por la matriz al finalizar el programa.

## Estructura del Código

- **`creacion_matriz`**: Reserva memoria para una matriz de `filas × columnas`.
- **`llenar_matriz`**: Llena la matriz con valores aleatorios entre 1 y 100.
- **`imprimir_matriz`**: Muestra la matriz en la consola con formato legible.
- **`dimensionar_matriz`**: Redimensiona la matriz, copiando los valores existentes y llenando las nuevas posiciones con valores aleatorios.
- **`main`**: Función principal que interactúa con el usuario para definir las dimensiones iniciales y redimensionadas de la matriz.

## Instrucciones de Uso

1. **Compilación**: Compila el programa con un compilador de C, por ejemplo:
   ```bash
   gcc quiz_5_code.c -o matriz_dinamica
