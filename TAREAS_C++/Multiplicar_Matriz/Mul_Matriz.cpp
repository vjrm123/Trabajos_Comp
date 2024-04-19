#include <iostream>
#include <iomanip>

void ImprimirMatriz(int (*matriz)[3][3]) {
    for (int i = 0; i < 3; i++) {
        std::cout << "| ";
        for (int j = 0; j < 3; j++) {
            std::cout << std::left << std::setw(5) << (*matriz)[i][j] ;
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::endl;
}

void MultiplicarMatriz(int (*p)[3][3]) {
    int matriz1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matriz2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // Imprimir las matrices de entrada
    std::cout << "Matriz 1:" << std::endl;
    ImprimirMatriz(&matriz1);

    std::cout << "Matriz 2:" << std::endl;
    ImprimirMatriz(&matriz2);

    // Calcular la multiplicación de matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            (*p)[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                (*p)[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    // Imprimir la matriz resultante
    std::cout << "Matriz resultado:" << std::endl;
    ImprimirMatriz(p);
}

int main() {
    int array[3][3][3] = {};

    // Llamar a la función MultiplicarMatriz
    MultiplicarMatriz(&array[2]);

    return 0;
}