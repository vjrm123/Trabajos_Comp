#include <iostream>

bool BusquedaBinaria(int *inicio, int *final, int valor) {
    
    while(inicio <= final) {
        int *medio = inicio + (final - inicio)/2;
        if(*medio == valor) {
            return true;
        } else if(*medio < valor) {
            inicio = medio +1;
        } else {
            final = medio -1;
        }
    }
    return false;
}

int main(){
    int array[] = {1,2,3};
    int size = sizeof(array) / sizeof(int);
    int valor = 5;
    if(BusquedaBinaria(array, array + size, valor)) {
        std::cout<< " si se encuentra";
    } else {
        std::cout<<"no";
    }
}