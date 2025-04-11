#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T value;
    Node* next;
    Node(T val) {
        value = val;
        next = nullptr;
    }
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int length_;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        length_ = 0;
    }

    void append(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length_++;
    }

    void prepend(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length_++;
    }

    int length() {
        return length_;
    }

    void removeLast() {
        if (!head) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T>* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        length_--;
    }

    void removeFirst() {
        if (!head) return;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
        length_--;
    }

    void display() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList<int> list;
    list.append(10);
    list.append(20);
    list.prepend(5);
    list.prepend(1);
    list.removeLast();
    list.removeFirst();
    list.display();
    cout << list.length() << endl;
}
