#include <iostream>
#include <bitset>
using namespace std;

bitset<23>Redondeo(bitset<49>J) {
    bitset<23>resultado(0);
    for(int i=0; i < 23; i++) {
        resultado[i] = J[i];
    }
    return resultado;
}

bitset<49>SumaBinaria(bitset<49>X, bitset<49>Y) {
    bitset<49>Suma;
    bool Acarreo = 0;
    for(int i=0; i < 49; i++) {
        bool bitA = X[i];
        bool bitB = Y[i];
        bool bits = bitA ^ bitB ^ Acarreo;
        Acarreo = (bitA && bitB) || (bitA && Acarreo) || (bitB && Acarreo);
        Suma[i] = bits;
    }
    return Suma;
}