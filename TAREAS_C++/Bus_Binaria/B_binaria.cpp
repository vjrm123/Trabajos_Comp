#include <iostream>
#include "../Or_Cocktail/or_cocktail.cpp"

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
void Imprimir(int* inicio, int* final) {
    std::cout << " : [ ";
    while (inicio != final) {
        std::cout << *inicio << ", ";
        inicio++;
    }
    if (inicio == final) {
        std::cout << *inicio;
    }
    std::cout << " ]\n";
}


void ImprimirMenu() {
    std::cout << "+--------------------------------+\n";
    std::cout << "|        MENU PRINCIPAL          |\n";
    std::cout << "+--------------------------------+\n";
    std::cout << "| Elige una opcion:              |\n";
    std::cout << "| 1. Busqueda Binaria            |\n";
    std::cout << "| 2. Ordenamiento Cocktail       |\n";
    std::cout << "| 3. Salir                       |\n";
    std::cout << "+--------------------------------+\n";
}

void ImprimirMenuPregunta() {
    std::cout << "+----------------------------+\n";
    std::cout << "| DESEA SEGUIR BUSCANDO?     |\n";
    std::cout << "+----------------------------+\n";
    std::cout << "| 1. SI                      |\n";
    std::cout << "| 2. NO                      |\n";
    std::cout << "+----------------------------+\n";
}

int main() {
    int array[] = {1,234, 12, 100, 500, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(int);
    int Opcion;
    bool Encontrado;

    do {
        ImprimirMenu();
        std::cin >> Opcion;
        switch (Opcion) {
            case 1:
                int opcion;
                do {
                    int ValorBuscar;
                    std::cout << "Ingrese el valor que desea buscar: ";
                    std::cin >> ValorBuscar;
                    Encontrado = busquedaBinaria(array, array + size, ValorBuscar);

                    if (Encontrado) {
                        std::cout << "\nEl numero " << ValorBuscar << " se encuentra en el Arreglo\n";
                        Imprimir(array, array + size);
                    } else {
                        std::cout << "El numero " << ValorBuscar << " no se encuentra en el Arreglo\n\n";
                    }

                    ImprimirMenuPregunta();
                    std::cin >> opcion;

                    if (opcion != 1 && opcion != 2) {
                        std::cout << "Opcion Invalida\n";
                        break;
                    }
                } while (opcion == 1);

                break;
            case 2:
                std::cout<< "Arreglo Original: ";
                Imprimir(array, array + size );

                Ordenamiento_Cocktail(array, array + size);

                std::cout<< "Arreglo Ordenado: ";
                Imprimir(array, array+size);

                std::cout << "Presione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                break;
            case 3:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida\n";
                break;
        }
    } while (Opcion != 3);

    return 0;
}