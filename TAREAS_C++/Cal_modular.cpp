#include <iostream>

int suma_modular(int a, int b, int modulo) {
    return (a + b) % modulo;
}

int resta_modular(int a, int b, int modulo) {
    return (a - b + modulo) % modulo;
}

int multiplicacion_modular(int a, int b, int modulo) {
    return (a * b) % modulo;
}

int main() {
    int a, b, modulo;
    
    std::cout << "ingrese el primer numero: ";
    std::cin >> a;
    
    std::cout << "ingrese el segundo numero: ";
    std::cin >> b;
    
    std::cout << "ingrese el valor del modulo: ";
    std::cin >> modulo;
    
    std::cout << "Suma modular: " << suma_modular(a, b, modulo) << std::endl;
    std::cout << "Resta modular: " << resta_modular(a, b, modulo) << std::endl;
    std::cout << "Multiplicacion modular: " << multiplicacion_modular(a, b, modulo) << std::endl;
    
    return 0;
}
