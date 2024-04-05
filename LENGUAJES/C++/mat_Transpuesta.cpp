#include <iostream>

void matrizTranspuesta(int** matriz, int tamano) {
    for (int i = 0; i < tamano; i++) {
        for (int j = i + 1; j < tamano; j++) {
            int temp = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = temp;
        }
    }
}

void imprimirMatriz(int** matriz, int tamano) {
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Ingresa el tamaño de la matriz: ";
    std::cin >> n;

    // Asignar memoria para la matriz
    int** matriz = new int*[n];
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[n];
    }

    // Leer los elementos de la matriz
    std::cout << "Ingresa los elementos de la matriz:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matriz[i][j];
        }
    }

    std::cout << "Matriz original:" << std::endl;
    imprimirMatriz(matriz, n);

    matrizTranspuesta(matriz, n);

    std::cout << "Matriz transpuesta:" << std::endl;
    imprimirMatriz(matriz, n);

    // Liberar memoria
    for (int i = 0; i < n; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}