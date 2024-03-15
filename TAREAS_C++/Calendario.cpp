#include <iostream>
#include <iomanip>

class Calendario {
    private:
        int Mes, Anio;
    public:
        Calendario(int Mes, int Anio) : Mes((Mes <= 0 ? 1 : Mes)), Anio((Anio <= 0 ? 1 : Anio)){}

        bool EsBisiesto() {
            if(Anio % 4 == 0 && (Anio % 100 != 0 || Anio % 400 == 0)) {
                return true;
            } else {
                return false;
            }
        }

        int ObtenerDiasDelMes() {
            if(Mes == 2) {
                return EsBisiesto() ? 29 : 28;
            } else if (Mes == 4 || Mes == 6 || Mes == 9 || Mes == 11 ) {
                return 30;
            } else {
                return 31;
            }
        }

        void imprimirCalendario() {
        int numDias = ObtenerDiasDelMes();
        int primerDiaSemana = 1;

        std::cout << "==============================+" << std::endl;
        std::cout << "      " << Mes << " / " << Anio << std::endl;
        std::cout << "==============================+" << std::endl;
        std::cout << "  D   L   M   M   J   V   S" << std::endl;

        for (int i = 0; i < primerDiaSemana; i++) {
            std::cout << "    ";
        }

        for (int dia = 1; dia <= numDias; dia++) {
            std::cout << std::setw(3) << dia << " ";
            if ((dia + primerDiaSemana) % 7 == 0) {
                std::cout << std::endl;
            }
        }

        std::cout << std::endl << "==============================+" << std::endl;
    }
};

int main(){
    int anio=2024;
    int mes = 3;
    Calendario calendario(mes, anio);
    calendario.imprimirCalendario();
    return 0;
}