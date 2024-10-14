#include <iostream>

using namespace std;

template <typename E>
class Node {
public:
    E value;
    Node<E>* next;

    explicit Node(Node<E>* nextNode = NULL) {
        next = nextNode;
    }

    explicit Node(E nodeValue, Node<E>* nextNode = NULL) {
        value = nodeValue;
        next = nextNode;
    }
};

template <typename E>
class Stack {
public:
    Stack() {
        top = NULL;
        numberElements = 0;
    }

    void print() {
        Node<E>* temp = top;
        for (int i = 0; temp != NULL; ++i) {
            cout << "[" << i << "] = " << temp->value << endl;
            temp = temp->next;
        }
    }

    E getTop() {
        if (top == NULL) {
            cerr << "Error: there is no element in the stack";
            exit(1);
        }
        return top->value;
    }

    void push(E value) {
        top = new Node<E>(value, top);
        numberElements++;
    }

    E pop() {
        if (top == NULL) {
            cerr << "Error: the stack is already empty!";
            exit(1);
        }

        Node<E>* temp = top;
        E value = top->value;

        top = top->next;

        numberElements--;

        delete temp;

        return value;
    }

    int getNumberElements() {
        return numberElements;
    }

private:
    Node<E>* top;
    int numberElements;
};

int main() {
    return 0;
}
