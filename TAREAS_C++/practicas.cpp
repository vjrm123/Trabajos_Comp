#include <iostream>

bool BusquedaBinaria(int* inicio, int* final, int valor) {
    while (inicio <= final) {
        int* medio = inicio + (final - inicio) / 2;
        if (*medio == valor) {
            return true;
        } else if (*medio < valor) {
            inicio = medio + 1;
        } else {
            final = medio - 1;
        }
    }
    return false;
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int valor = 19;
    int size = sizeof(array) / sizeof(int);
    bool encontrado = BusquedaBinaria(array, array + size, valor);
    if (encontrado) {
        std::cout << "El valor " << valor << " se encuentra en el array.\n";
    } else {
        std::cout << "El valor " << valor << " no se encuentra en el array.\n";
    }
    return 0;
}