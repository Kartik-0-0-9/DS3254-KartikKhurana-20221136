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

class Stack {
private:
    Node* topNode;
public:
    Stack() {
        topNode = nullptr;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = topNode;
        topNode = temp;
    }

    void pop() {
        if (topNode) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    int top() {
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.pop();
    cout << s.top() << endl;
}
