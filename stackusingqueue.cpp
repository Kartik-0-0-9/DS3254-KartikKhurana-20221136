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

class Stack {
private:
    Node* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    void push(int val) {
        Node* temp = new Node(val);
        temp->next = topNode;
        topNode = temp;
    }

    int pop() {
        if (!topNode) return -1;
        Node* temp = topNode;
        int val = temp->data;
        topNode = topNode->next;
        delete temp;
        return val;
    }

    int top() {
        if (!topNode) return -1;
        return topNode->data;
    }

    bool empty() {
        return topNode == nullptr;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.empty() << endl;
}
