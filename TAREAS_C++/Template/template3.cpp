#include <iostream>

using namespace std;

template<class T>
class Nodo {
public:
    T Valor;
    Nodo<T>* Next;

    Nodo(T V, Nodo<T>* N = nullptr) : Valor(V), Next(N) {}
};

template<class T>
class LE {
    Nodo<T>* Head = nullptr;

public:
    void Print();
    bool Find(T V, Nodo<T>*& Pos);
    void Add(T V);
    void Delete(T v);

    ~LE();
};

template<class T>
void LE<T>::Print() {
    std::cout << "HEAD-> ";
    for (Nodo<T>* P = Head; P; P = P->Next) {
        std::cout << P->Valor << "-> ";
    }
    std::cout << "nullptr\n";
}

template<class T>
bool LE<T>::Find(T V, Nodo<T>*& Pos) {
    bool Encontrado = false;
    Pos = nullptr;

    for (Nodo<T>* P = Head; P && V >= P->Valor; P = P->Next) {
        if (V == P->Valor) {
            Encontrado = true;
            break;
        } else {
            Pos = P;
        }
    }
    return Encontrado;
}

template<class T>
void LE<T>::Add(T V) {
    Nodo<T>* Pos_ant;
    if (!Find(V, Pos_ant)) {
        if (Pos_ant) {
            Pos_ant->Next = new Nodo<T>(V, Pos_ant->Next);
        } else {
            Head = new Nodo<T>(V, Head);
        }
    }
}

template<class T>
void LE<T>::Delete(T v) {
    Nodo<T>* pos_ant = nullptr;
    if (Find(v, pos_ant)) {
        Nodo<T>* pos_del = (pos_ant) ? pos_ant->Next : Head;
        if (pos_ant) {
            pos_ant->Next = pos_del->Next;
        } else {
            Head = pos_del->Next;
        }
        delete pos_del;
    }
}

template<class T>
LE<T>::~LE() {
    while (Head) {
        Delete(Head->Valor);
    }
}

int main() {
    LE<int> lista;
    lista.Add(3);
    lista.Add(5);
    lista.Add(1);
    lista.Add(4);

    lista.Print();

    lista.Delete(5);
    lista.Delete(1);

    lista.Print();
    return 0;
}