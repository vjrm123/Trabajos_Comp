#include <iostream>

int* eliminarDuplicados(int* arreglo, int tamano, int& tamanoResultado) {
    int* resultado = new int[tamano];
    tamanoResultado = 0;

    for (int i = 0; i < tamano; i++) {
        bool esDuplicado = false;

        for (int j = 0; j < tamanoResultado; j++) {
            if (arreglo[i] == resultado[j]) {
                esDuplicado = true;
                break;
            }
        }

        if (!esDuplicado) {
            resultado[tamanoResultado] = arreglo[i];
            tamanoResultado++;
        }
    }

    return resultado;
}

int main() {
    int arreglo[] = {2, 5, 10, 7, 3, 5, 7, 2, 8, 10};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);

    int tamanoResultado;
    int* resultado = eliminarDuplicados(arreglo, tamano, tamanoResultado);

    std::cout << "Arreglo original: ";
    for (int i = 0; i < tamano; i++) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Arreglo sin duplicados: ";
    for (int i = 0; i < tamanoResultado; i++) {
        std::cout << resultado[i] << " ";
    }
    std::cout << std::endl;

    delete[] resultado;

    return 0;
}