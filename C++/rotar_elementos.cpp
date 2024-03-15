#include <iostream>

void rotarArreglo(int* arreglo, int n, int k) {
    k = k % n; // Asegurarse de que k esté dentro del rango [0, n)

    // Crear un arreglo auxiliar para almacenar los elementos rotados
    int* auxiliar = new int[n];

    // Copiar los últimos k elementos al arreglo auxiliar
    for (int i = 0; i < k; i++) {
        auxiliar[i] = arreglo[n - k + i];
    }

    // Mover los primeros n-k elementos k posiciones hacia la derecha
    for (int i = n - 1; i >= k; i--) {
        arreglo[i] = arreglo[i - k];
    }

    // Copiar los elementos del arreglo auxiliar al inicio del arreglo original
    for (int i = 0; i < k; i++) {
        arreglo[i] = auxiliar[i];
    }

    // Liberar la memoria del arreglo auxiliar
    delete[] auxiliar;
}

int main() {
    int n = 5;
    int arreglo[] = {1, 2, 3, 4, 5};
    int k = 2;

    std::cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;

    rotarArreglo(arreglo, n, k);

    std::cout << "Arreglo rotado " << k << " posiciones hacia la derecha: ";
    for (int i = 0; i < n; i++) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}