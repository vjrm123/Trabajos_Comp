#include <iostream>

template <class T>
struct Nodo {
    T valor;
    Nodo<T>* next;
    Nodo(T v, Nodo<T>* n = nullptr) : valor(v), next(n) {}
};

template <class T>
struct Pila {
    Nodo<T>* Head = nullptr;

    void Push(T v) {
        Nodo<T>* nuevo = new Nodo<T>(v, Head); 
        Head = nuevo;
    }

    T Pop() {
        T v = 0;
        Nodo<T>* temp;
        if (Head) {
            v = Head->valor;
            temp = Head;
            Head = Head->next;
            delete temp;
        }
        return v;
    }

    void Print() {
        std::cout << "HEAD-> ";
        for (Nodo<T>* P = Head; P; P = P->next) {
            std::cout << P->valor << " -> ";
        }
        std::cout << "NULL\n";
    }
};

void print(Nodo<int>* X) {
    for (Nodo<int>* P = X; P != nullptr; P = P->next) {
        std::cout << P->valor << " -> ";
    }
    std::cout << "NULL\n";
}

int main() {
    Nodo<int>* Head = nullptr;
    for (int i = 0; i < 6; ++i) {
        Head = new Nodo<int>(i, Head);
    }
    print(Head);

    while (Head) {
        Nodo<int>* temporal;
        temporal = Head;
        Head = Head->next;
        delete temporal;
    }
    print(Head);

    Pila<int> Pichi;
    for (int i = 0; i < 6; ++i) {
        Pichi.Push(i);
    }
    Pichi.Print();

    while (Pichi.Head) {
        std::cout << "Pop: " << Pichi.Pop() << "\n";
        Pichi.Print();
    }

    return 0;
}
