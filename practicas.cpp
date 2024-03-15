#include <iostream>
#include <string>

std::string NumeroRomano(int Numero) {
    std::string NumeroRomano;
    int Valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string Simbolos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for(int i=0; i < 13; i++) {
        while(Numero >= Valores[i]) {
            NumeroRomano += Simbolos[i];
            Numero -= Valores[i];
        }
    }
    return NumeroRomano;
}

void MostrarMenu() {
    std::cout << "=============================";
    std::cout <<"         BIENVENIDOS           ";
    std::cout << "=============================";
    std::cout << "1. convertir un numero entero a romano...";
    std::cout << "2. Salir..";
}

int main(){
    int opcion;
    std::cout<< "ingrese la opcion: "; std::cin>>opcion;

    do {
        MostrarMenu();
        std::cout<< "ingresa la opcion: "; 
        std::cin>>opcion;
        switch(opcion) {
            case 1 : {
                int Numero;
                std::cout<< "ingresa un numero para convertir en numeros romanos: "; 
                std::cin>>Numero;
                std::string Resultado = NumeroRomano(Numero);
                std::cout<< "el numero " << Numero << " en romano es: " << Resultado <<"\n";
                break; 
                }
            case 2 :
                std::cout << "saliendo...\n";
            default :
                std::cout<<" error!!!\n";
        }

    } while(opcion != 2);
    return 0;
}