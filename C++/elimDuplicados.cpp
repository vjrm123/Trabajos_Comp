#include <iostream>
#include <vector>
#include <algorithm>
int* EliminarDuplicados(int* arreglo, int size, int& sizeResultante) {
    int* NuevoArreglo = new int[size];
    int tamanioResultante = 0;
    for(int i=0; i < size; i++) {
        bool DuplicadoEncontrado = false;
        for(int j =0; j < tamanioResultante; j++) {
            if(arreglo[i] == NuevoArreglo[j]) {
                DuplicadoEncontrado = true;
                break;
            }
        }
        if(!DuplicadoEncontrado) {
            NuevoArreglo[tamanioResultante++] = arreglo[i];
        }
    }
    sizeResultante = tamanioResultante;
    return NuevoArreglo;
}

std::vector<int>eliminarArreglo(std::vector<int>& arreglo) {
    std::vector<int> NuevoArreglo;
    for(int i=0; i < arreglo.size(); i++) {
        if(std::find(NuevoArreglo.begin(), NuevoArreglo.end(), arreglo[i]) == NuevoArreglo.end()) {
            NuevoArreglo.push_back(arreglo[i]);
        }
    }
    return NuevoArreglo;
}

int main(){
    std::vector<int> Arreglo = {1,1,2,2,3,3,4,4,5,5};
    std::vector<int> Resultado = eliminarArreglo(Arreglo);
    for(auto& elemento : Resultado) {
        std::cout << elemento << " ";
    }
    return 0;
}