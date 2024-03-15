#include <iostream>
#include <iomanip>
using namespace std;

class Calendario {
private:
    int anio;
    int mes;

public:
    Calendario(int _anio, int _mes) {
        anio = _anio;
        mes = _mes;
    }

    bool esBisiesto() {
    if (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

    int obtenerDiasEnMes() {
        if (mes == 2) {
            return esBisiesto() ? 29 : 28;
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            return 30;
        } else {
            return 31;
        }
    }

    int obtenerDiaSemana(int dia) {
        static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        int anioTemporal = anio - (mes < 3);
        int diaSemana = (anioTemporal + anioTemporal / 4 - anioTemporal / 100 + anioTemporal / 400 + t[mes - 1] + dia) % 7;
        return diaSemana;
    }

    void imprimirCalendario() {
        int numDias = obtenerDiasEnMes();
        int primerDiaSemana = obtenerDiaSemana(1);

        cout << "======================" << endl;
        cout << "      " << mes << " / " << anio << endl;
        cout << "======================" << endl;
        cout << "Do Lu Ma Mi Ju Vi Sa" << endl;

        for (int i = 0; i < primerDiaSemana; i++) {
            cout << "    ";
        }

        for (int dia = 1; dia <= numDias; dia++) {
            std::cout << std::setw(2) << dia << " ";
            if ((dia + primerDiaSemana) % 7 == 0) {
                cout << endl;
            }
        }

        cout << endl << "======================" << endl;
    }
};

int main() {
    int anio, mes;

    cout << "Ingrese el año: ";
    cin >> anio;
    cout << "Ingrese el mes: ";
    cin >> mes;

    Calendario calendario(anio, mes);
    calendario.imprimirCalendario();

    return 0;
}