#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> data;
public:
    void push(int x) {
        data.push_back(x);
    }

    void pop() {
        if (!data.empty()) data.pop_back();
    }

    int top() {
        return data.back();
    }

    bool isEmpty() {
        return data.empty();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    cout << s.top() << endl;
}
