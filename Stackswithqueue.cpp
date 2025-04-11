#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> inStack, outStack;

    void transfer() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    void enqueue(int x) {
        inStack.push(x);
    }

    void dequeue() {
        if (outStack.empty()) transfer();
        if (!outStack.empty()) outStack.pop();
    }

    int front() {
        if (outStack.empty()) transfer();
        return outStack.top();
    }

    bool isEmpty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    QueueUsingStacks q;
    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    cout << q.front() << endl;
}
