#include <bitset>
#include <iostream>
using namespace std;
const int x = 4;

bitset<x> sumaBinaria(bitset<x> a, bitset<x> b) {
    bitset<x> suma;
    bool acarreo = 0;
    for (int i = 0; i < x; i++) {
        bool bitA = a[i];
        bool bitB = b[i];

        bool resultadoBit = bitA ^ bitB ^ acarreo;
        acarreo = (bitA & bitB) | (bitA & acarreo) | (bitB & acarreo);

        suma[i] = resultadoBit;
    }
    return suma;
}

bitset<x> restaBinaria(bitset<x> a, bitset<x> b) {
    bitset<x> resta;
    b = b.flip();
    bool acarreo = 1;
    for (int i = 0; i < x; i++) {
        bool bitA = a[i];
        bool bitB = b[i];

        bool resultadoBit = bitA ^ bitB ^ acarreo;
        acarreo = (bitA & bitB) | (bitA & acarreo) | (bitB & acarreo);

        resta[i] = resultadoBit;
    }
    return resta;
}

void mostrarValoresIniciales(bitset<x> A, bitset<x> Q, bool _Q1, bitset<x> M) {
    cout << "VALORES INICIALES" << endl;
    cout << A << " " << Q << " " << _Q1 << " " << M << endl << endl;
}

void mostrarResultado(bitset<x> A, bitset<x> Q, int q, int m) {
  cout << "El resultado es: " << A << Q << " = " << q * m;
}

int main() {

    cout << "Se esta trabajando con tamaño de: " << x << " bits" << endl;

    int q = 0;
    cout << "Ingresar multiplicador: ";
    cin >> q;

    int m = 0;
    cout << "Ingresar multiplicando: ";
    cin >> m;

    bitset<x> Q(+q);
    bitset<x> M(+m);

    cout << "Se estan multiplicando los numeros: " << q << " = " << Q << " y "
        << m << " = " << M << endl
        << endl;

    bool _Q1 = 0;
    bool Q_0 = 0;
    bitset<x> A(+0);
    bool aux1 = 0;
    bool aux2 = 0;

    mostrarValoresIniciales(A, Q, _Q1, M);

    for (int c = 0; c < x; c++) {
        Q_0 = Q[0];
        if (Q_0 == 0 && _Q1 == 1) {
        cout << "SUMA" << endl;
        A = sumaBinaria(A, M);
        } else if (Q_0 == 1 && _Q1 == 0) {
        cout << "RESTA" << endl;
        A = restaBinaria(A, M);
        } else {
        cout << "SOLO CORRIMIENTO" << endl;
        }
        cout << A << " " << Q << " " << _Q1 << " " << M << endl;
        aux1 = A[x - 1];
        aux2 = A[0];
        A >>= 1;
        A[x - 1] = aux1;
        _Q1 = Q[0];
        Q >>= 1;
        Q[x - 1] = aux2;
        cout << A << " " << Q << " " << _Q1 << " " << M << endl << endl;
    }

    mostrarResultado(A, Q, q, m);

    return 0;
}
