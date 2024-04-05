#include <iostream>

double Multiplicacion(double* a, double* b) {return *a * *b; }
double Resta(double* a, double* b) { return *a - *b; }
double Suma(double* a, double* b) { return *a + *b; }
double Division(double* a, double* b) { return (*b != 0 ? *a / *b : 0.0); }

int main(){
    
    double Num1, Num2, Resultado;
    char operador;

    std::cout << "ingrese el primer numero..."; std::cin>>Num1;
    std::cout << "ingrese el operador..."; std::cin>>operador;
    std::cout << "ingrese el segundo numero..."; std::cin>>Num2;

    switch( operador ) {
        case '*' : 
            Resultado = Multiplicacion(&Num1, &Num2);
            break;
        case '-' :
            Resultado = Resta(&Num1, &Num2);
            break;
        case '+' :
            Resultado = Suma(&Num1, &Num2);
            break;
        case '/' :
            Resultado = Division(&Num1, &Num2);
            break;
        default :
            std:: cout << "el operador es invalido...";
            break;
    }

    std::cout << "El resultado de la operacion es = " << Resultado << "\n";

    return 0;
}