#include <iostream>

int* BusquedaBinaria(int* inicio, int* final, int valor) {
    while(inicio <= final) {
        int* medio = inicio + (final - inicio) /2;
        if(*medio == valor) {
            return medio;
        }
        else if(*medio < valor) {
            inicio = medio + 1;
        }
        else {
            final = medio - 1;
        }
    }
    return nullptr;
}

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9};
    int valor = 9;
    int size = sizeof(array) / sizeof(int);
    int* posicion = BusquedaBinaria(array, array+size, valor);
    std::cout<< "el valor " << valor << " buscado se encuentra en la posicion " << posicion - array << "\n";
    return 0;
}