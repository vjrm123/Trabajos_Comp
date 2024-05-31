#include <iostream>

template<class T>
class Stack {
public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (!isEmpty()) {
            Pop();
        }
    }

    void Push(const T& object);
    T Pop();
    bool isEmpty();

private:
    struct StackNode {
        T Data;
        StackNode* Next;

        StackNode(const T& newData, StackNode* nextNode)
            : Data(newData), Next(nextNode) {}
    };
    StackNode* top;
};

template<class T>
bool Stack<T>::isEmpty() {
    return top == nullptr;
}

template<class T>
void Stack<T>::Push(const T& obj) {
    StackNode* newNode = new StackNode(obj, top);
    top = newNode;
}

template<class T>
T Stack<T>::Pop() {
    if (isEmpty()) {
        throw std::out_of_range("La pila está vacía");
    }
    StackNode* nodeToDelete = top;
    T data = nodeToDelete->Data;
    top = top->Next;
    delete nodeToDelete;
    return data;
}

int main() {
    Stack<int> stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    std::cout << "Elemento en la cima: " << stack.Pop() << std::endl;
    std::cout << "Elemento en la cima: " << stack.Pop() << std::endl;
    std::cout << "Elemento en la cima: " << stack.Pop() << std::endl;

    return 0;
}