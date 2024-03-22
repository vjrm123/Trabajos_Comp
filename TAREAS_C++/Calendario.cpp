#include <iostream>
#include <iomanip>

class Calendario {
    private:
        int Mes, Anio;
    public:
        Calendario(int Mes, int Anio) : Mes((Mes > 1 && Mes <= 12) ? Mes : 1), Anio((Anio > 0 ) ? Anio : 1) {}

        bool EsBisiesto(){
            if(Anio % 4 == 0 && (Anio % 100 != 0 || Anio % 400 == 0 )) {
                return true;
            } else {
                return false;
            }
        }

        int ObtenerDiasDelmes(){
            if(Mes == 2) {
                return EsBisiesto() ? 29 : 28;
            } 
            else if(Mes == 4 || Mes == 6 || Mes == 9 || Mes == 11) {
                return 30;
            } else {
                return 31;
            }
        }
        
        std::string ImprimirMes(int Numero) {
            std::string Arrays[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
            return Arrays[Numero -1];
        }

        int ObtenerPrimerDiaSemana() {
            int ajusteMes = (14 - Mes) / 12;
            int ajusteAnio = Anio - ajusteMes;
            int mesAjustado = Mes + 12 * ajusteMes - 2;
            int primerDiaSemana = (1 + ajusteAnio + ajusteAnio / 4 - ajusteAnio / 100 + ajusteAnio / 400 + (31 * mesAjustado) / 12) % 7;
            return primerDiaSemana;
        }

        void ImprimirCalendario(){
            int NumDias = ObtenerDiasDelmes();
            int PrimerDiaSemana = ObtenerPrimerDiaSemana();
            
            std::cout<< "========================================\n";
            std::cout<< "  MES/AÑO ELEGIDO: " << ImprimirMes(Mes) << " / " << this->Anio << "\n";
            std::cout<< "========================================\n";
            std::cout<< "  D   L   M   M   J   V   S  \n";

            for(int i=0; i < PrimerDiaSemana; i++) {
                std::cout<< "    ";
            }
            for(int dia = 1; dia <= NumDias; dia ++) {
                std::cout<< std::setw(3) << dia << " ";
                if((PrimerDiaSemana + dia ) % 7 == 0) {
                    std::cout<<"\n";
                }
            }
            std::cout<< "\n" << "========================================\n";
        }
};

int main() {
    int Mes = 3;
    int Anio = 2024;

    Calendario* calendario = new Calendario(Mes, Anio);
    calendario->ImprimirCalendario();

    delete calendario;

    return 0;
}