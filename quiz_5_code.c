/* Instrucciones breves a seguir. 
 * 
 *   1. Crear matriz m×n con valores aleatorios (1-100)
 *   2. Permite redimensionar a m2×n2 manteniendo valores existentes
 *   3. Llena nuevas posiciones con valores aleatorios
 *   4. Liberra toda la memoria correctamente
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funcion para una matriz de enteros en memoria dinamica mxn.
//
int** creacion_matriz(int filas, int columnas) {
    int** matriz = (int**)malloc(m * sizeof(int*)); // Reservar memoria para filas (punteros a enteros)

    for (int i = 0; i < filas; i++) {
        matriz[i] = (int*)malloc(columnas * sizeof(int));  // Reservar memoria para columnas en cada fila
    }
    return matriz; // Devolver nueva matriz.
}

// Funcion para llenar la matriz con números aleatorios de uno al cien (1-100)

void llenar_matriz(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 100 + 1; // Asignar valor aleatorio entre 1 y 100
        }
    }
}

// Funcion para imprimir la matriz

void imprimir_matriz(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%3d ", matriz[i][j]); // Imprimir cada elemento con 3 de ancho.
        }
        printf("\n"); // Salto de linea.
    }
}

// Función para redimensionar la matriz

int** dimensionar_matriz(int** matriz, int filas_old, int columnas_old, int filas_new, int columnas_new) {
    int** nueva_matriz = creacion_matriz(filas_new, columnas_new); // Crea una nueva matriz con las nuevas dimensiones

// Copiar los valores antiguos si aun caben en la nueva matriz

    for (int i = 0; i < filas_new; i++) {
        for (int j = 0; j < columnas_new; j++) {
            if (i < filas_old && j < columnas_old) {
                nueva_matriz[i][j] = matriz[i][j]; // Conserva el valor antiguo
            } else {
                nueva_matriz[i][j] = rand() % 100 + 1; // Rellenar nuevas posiciones con aleatorios
            }
        }
    }

// Liberar la memoria de la matriz antigua

    for (int i = 0; i < filas_old; i++) {
        free(matriz[i]); // Libera cada fila
    }
    free(matriz); // Libera el arreglo de punteros

    return nueva_matriz; // Devuelve la nueva matriz redimensionada
}

// Función principal interaccion con usuario
int main() {
    srand(time(NULL)); // Inicia para números aleatorios

    int filas, columnas, filas2, columnas2;

    // Pide al usuario las dimensiones iniciales
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    int** matriz = creacion_matriz(filas, columnas); // Crea la matriz inicial
    llenar_matriz(matriz, filas, columnas);      // Llena la matriz con valores aleatorios

    printf("\nMatriz original:\n");
    imprimir_matriz(matriz, filas, columnas);    // Muestra la matriz original

    // Solucitud al usuario las nuevas dimensiones
    printf("\nIngrese el nuevo número de filas : ");
    scanf("%d", &filas2);
    printf("Ingrese el nuevo número de columnas : ");
    scanf("%d", &columnas2);

    matriz = dimensionar_matriz(matriz, filas, columnas, filas2, columnas2); // Redimensiona la matriz

    printf("\nMatriz redimensionada:\n");
    imprimir_matriz(matriz, filas2, columnas2);  // Muestra la matriz redimensionada

    // Libera la memoria al finalizar
    for (int i = 0; i < filas2; i++) {
        free(matriz[i]); // Liberar cada fila
    }
    free(matriz); // Libera el arreglo de punteritos

    return 0;
}
