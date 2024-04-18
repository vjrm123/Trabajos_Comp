#include <iostream>

void Intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Cocktail_Sort(int* inicio, int* fin) {
    bool hubo_intercambio = true;

    while (hubo_intercambio) {
        hubo_intercambio = false;

        // Recorrido de izquierda a derecha
        int* i = inicio;
        while (i != fin) {
            if (*i > *(i + 1)) {
                Intercambiar(i, i + 1);
                hubo_intercambio = true;
            }
            i++;
        }

        // Si no hubo intercambios en el recorrido anterior, se termina
        if (!hubo_intercambio) {
            break;
        }

        hubo_intercambio = false;
        fin--;

        // Recorrido de derecha a izquierda
        i = fin;
        while (i != inicio) {
            if (*i < *(i - 1)) {
                Intercambiar(i, i - 1);
                hubo_intercambio = true;
            }
            i--;
        }

        inicio++;
    }
}




