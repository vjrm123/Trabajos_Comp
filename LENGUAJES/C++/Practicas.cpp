#include <iostream>
#include <vector>
void Factorial(int Numero) {
    int Resultado = 1;
    if(Numero <= 0) { return; }
    else { 
        for(int i = Numero; i > 0; i--) {
            Resultado *= i ;
        }
    }
    std::cout << "el Factorial de " << Numero  << " es : " << Resultado <<"\n";
}

bool NumeroPrimo(int Numero) {
    if(Numero <= 1) {
        return false;
    } else {
        for(int i=2; i < Numero/2; i++) {
            if(Numero % i == 0) {
                return false;
            }
        }
        return true;
    }
}

void tablaMultiplicar(int numero) {
    for(int i=0; i < 11; i++) {
        std::cout<< numero << " x " << i << " = " << numero * i << "\n";
    }
}

void Tabla(int numero) {
    for(int i=1; i < numero; i++) {
        for(int j = 0; j < 11; j++) {
            std::cout<< i << " x " << j << " = " << i*j << "\n";
        }
        std::cout<< "\n";
    }
}

double calcularPromedio(int Numero) {
    double sumaTotal = 0.0;
    for(int i=0; i < Numero; i++) {
        int numero;
        std::cout<< "ingrese el numero..."; std::cin>>numero;
        sumaTotal +=numero;
    }
    return sumaTotal / Numero;
}

double promedioArreglo(int arreglo[], int size) {
    double Suma = 0.0;
    if(size > 0) {
        for(int i=0; i < size; i++) {
            Suma += arreglo[i]; 
        }
        return (Suma / size);
    } else {
        return 0.0;
    }
}


void intercambioArreglo(int* Arreglo, int inicio, int final) {
    while(inicio < final) {
        int temp = Arreglo[inicio];
        Arreglo[inicio] = Arreglo[final];
        Arreglo[final] = temp;
        inicio++;
        final--;
    }
}

void OrdenarArreglo(int* Arreglo, int size) {
    if(size > 0) {
        for(int i=0; i < size -1; i++) {
            for(int j=i+1; j < size; j++) {
                if(Arreglo[i] < Arreglo[j]) {
                    int temp = Arreglo[i];
                    Arreglo[i] = Arreglo[j];
                    Arreglo[j] = temp;
                }
            }
        }
    } else {
        std::cout<<"Error!!\n";
    }
}

class Persona {
    private:
        std::string Nombre, Apellido, Direccion, Ocupacion;
        int Edad;
    public:
        Persona(std::string Nombre, std::string Apellido, std::string Direccion, std::string Ocupacion, int Edad): 
        Nombre(Nombre), Apellido(Apellido), Direccion(Direccion), Ocupacion(Ocupacion) { if ( Edad > 0 ) this-> Edad = Edad; }

        void MostrarDatos() {
            std::cout << "********* MOSTRANDO DATOS ***********\n";
            std::cout << "Nombre: " << this->Nombre << "\n";
            std::cout << "Apellidos: " << this->Apellido << "\n";
            std::cout << "Direcion: " << this->Direccion << "\n";
            std::cout << "Ocupacion: " << this->Ocupacion << "\n";
            std::cout << "Edad: " << this->Edad << "\n";
            std::cout << "*************************************\n";
        }

};
int main() {
    std::vector<Persona*> personas;
    personas.push_back(new Persona("Victor", "ramos", "av el sol", "Estudiante", 20));
    personas.push_back(new Persona("juan" , "mamani", "av Obrera", "Estudiante", 20));

    for(Persona* personitas : personas) {
        personitas->MostrarDatos();
        std::cout << "\n";
    }

    for (Persona* personita : personas){
        delete personita;
    }
    
    return 0;
}