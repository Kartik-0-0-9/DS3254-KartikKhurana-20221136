#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Queue {
private:
    Node* frontNode;
    Node* rearNode;
public:
    Queue() {
        frontNode = rearNode = nullptr;
    }

    void enqueue(int x) {
        Node* temp = new Node(x);
        if (!rearNode) {
            frontNode = rearNode = temp;
        } else {
            rearNode->next = temp;
            rearNode = temp;
        }
    }

    void dequeue() {
        if (!frontNode) return;
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (!frontNode) rearNode = nullptr;
        delete temp;
    }

    int front() {
        return frontNode->data;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.dequeue();
    cout << q.front() << endl;
}
