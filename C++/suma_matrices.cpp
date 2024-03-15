#include <iostream>

void sumarMatrices(const int** matriz1, const int** matriz2, int** resultado, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

int main() {
    int n;
    std::cout << "Ingrese el tamaño de las matrices cuadradas: ";
    std::cin >> n;

    // Crear las matrices usando asignación de memoria dinámica
    int** matriz1 = new int*[n];
    int** matriz2 = new int*[n];
    int** resultado = new int*[n];
    for (int i = 0; i < n; i++) {
        matriz1[i] = new int[n];
        matriz2[i] = new int[n];
        resultado[i] = new int[n];
    }

    std::cout << "Ingrese los elementos de la matriz 1:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matriz1[i][j];
        }
    }

    std::cout << "Ingrese los elementos de la matriz 2:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matriz2[i][j];
        }
    }

    sumarMatrices((const int**)matriz1, (const int**)matriz2, resultado, n);

    std::cout << "La matriz resultante de la suma es:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << resultado[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Liberar la memoria asignada
    for (int i = 0; i < n; i++) {
        delete[] matriz1[i];
        delete[] matriz2[i];
        delete[] resultado[i];
    }
    delete[] matriz1;
    delete[] matriz2;
    delete[] resultado;

    return 0;
}