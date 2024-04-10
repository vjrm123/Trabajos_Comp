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

bool busquedaBinaria(int *inicio, int *final, int valor) {
    while(inicio <= final) {
        int *medio = inicio + (final - inicio)/2;
        if(*medio == valor) {
            return true;
        } else if(*medio < valor){
            inicio = medio + 1;
        } else {
            final = medio -1;
        }
    }
    return false;
}
void Imprimir(int *inicio, int *final) {
    std::cout<<"Array : [ ";
    while(inicio < final) {
        std::cout<< *inicio++ << " ";
    }
    std::cout<<"]\n";
}

void ImprimirMenu(){
    std::cout<<"********************************\n";
    std::cout<<"             MENU               \n";
    std::cout<<"********************************\n";
    std::cout<<"1. Busqueda Binaria \n";
    std::cout<<"2. Salir\n";
    std::cout<<"********************************\n";
}

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(array) / sizeof(int);
    int Opcion;
    do {
        ImprimirMenu();
        std::cin>>Opcion;
        switch(Opcion) {
            case 1:
                int ValorBuscar;
                std::cout<<"Ingrese el valor que desea buscar: " ;
                std::cin>>ValorBuscar;
                bool Encontrado = BusquedaBinaria(array, array + size, ValorBuscar);
                std::cout << "Presione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                break;
            deafult:
                std::cout<<"Ingreso una opcion invalida!!\n";
                break;
        }
    }while(Opcion != 2);
    
    
    
    return 0;
}