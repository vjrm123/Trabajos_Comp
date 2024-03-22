#include <iostream>
#include <string>

std::string NumeroRomano(int Numero) {
    std::string NumeroRomano;
    int Valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string Simbolos[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    for(int i=0; i < 13; i++) {
        while(Numero >= Valores[i]) {
            NumeroRomano += Simbolos[i];
            Numero -= Valores[i];
        }
    }
    return NumeroRomano;
}

void mostrarMenu() {
    std::cout << "********************************************" << std::endl;
    std::cout << "**              Menu de opciones           **" << std::endl;
    std::cout << "********************************************" << std::endl;
    std::cout << "1. Convertir un número entero a romano" << std::endl;
    std::cout << "2. Salir" << std::endl;
    std::cout << "********************************************" << std::endl;
}

int main() {
    int opcion;
    
    do {
        mostrarMenu();
        
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;
        
        switch (opcion) {
            case 1: {
                int numero;
                std::cout << "Ingrese un número entero: ";
                std::cin >> numero;
                
                std::string numeroRomano = NumeroRomano(numero);
                std::cout << "El número " << numero << " en números romanos es: " << numeroRomano << std::endl;
                
                break;
            }
            case 2: {
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            }
            default: {
                std::cout << "Opción inválida. Por favor, ingrese una opción válida." << std::endl;
                break;
            }
        }
        
        std::cout << std::endl;
    } while (opcion != 2);
    
    return 0;
}