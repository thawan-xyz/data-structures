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

    Node(E nodeValue, Node<E>* nextNode = NULL) {
        value = nodeValue;
        next = nextNode;
    }
};

template <typename E>
class Queue {
public:
    Queue() {
        front = back = new Node<E>;
        numberElements = 0;
    }

    void print() {
        Node<E>* temp = front->next;
        for (int i = 0; temp != NULL; ++i) {
            cout << "[" << i << "] = " << temp->value << endl;
            temp = temp->next;
        }
    }

    E getValue() {
        if (front == back) {
            cerr << "Error: there is no element in the queue";
            exit(1);
        }
        return (front->next)->value;
    }

    void enqueue(E value) {
        back->next = new Node<E>(value);
        back = back->next;

        numberElements++;
    }

    E dequeue() {
        if (numberElements == 0) {
            cerr << "Error: the queue is already empty!";
            exit(1);
        }

        Node<E>* temp = front->next;
        E value = (front->next)->value;

        front->next = (front->next)->next;

        if (front->next == NULL) {
            back = front;
        }

        numberElements--;

        delete temp;

        return value;
    }

    int getNumberElements() {
        return numberElements;
    }

private:
    Node<E>* front;
    Node<E>* back;
    int numberElements;
};

int main() {
    return 0;
}
