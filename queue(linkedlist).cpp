#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
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

    void enqueue(int val) {
        Node* temp = new Node(val);
        if (!rearNode) {
            frontNode = rearNode = temp;
            return;
        }
        rearNode->next = temp;
        rearNode = temp;
    }

    int dequeue() {
        if (!frontNode) return -1;
        Node* temp = frontNode;
        int val = temp->data;
        frontNode = frontNode->next;
        if (!frontNode) rearNode = nullptr;
        delete temp;
        return val;
    }

    int front() {
        if (!frontNode) return -1;
        return frontNode->data;
    }

    bool empty() {
        return frontNode == nullptr;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.empty() << endl;
}
