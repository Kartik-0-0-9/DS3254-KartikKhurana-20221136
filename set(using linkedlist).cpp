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

class Set {
private:
    Node* head;

    bool contains(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

public:
    Set() {
        head = nullptr;
    }

    void insert(int val) {
        if (!contains(val)) {
            Node* temp = new Node(val);
            temp->next = head;
            head = temp;
        }
    }

    void remove(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* prev = head;
        Node* curr = head->next;
        while (curr) {
            if (curr->data == val) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Set unionWith(Set& other) {
        Set result;
        Node* temp = head;
        while (temp) {
            result.insert(temp->data);
            temp = temp->next;
        }
        temp = other.head;
        while (temp) {
            result.insert(temp->data);
            temp = temp->next;
        }
        return result;
    }

    Set intersectWith(Set& other) {
        Set result;
        Node* temp = head;
        while (temp) {
            if (other.contains(temp->data))
                result.insert(temp->data);
            temp = temp->next;
        }
        return result;
    }

    Set differenceWith(Set& other) {
        Set result;
        Node* temp = head;
        while (temp) {
            if (!other.contains(temp->data))
                result.insert(temp->data);
            temp = temp->next;
        }
        return result;
    }
};

int main() {
    Set a, b;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    b.insert(2);
    b.insert(4);

    Set u = a.unionWith(b);
    Set i = a.intersectWith(b);
    Set d = a.differenceWith(b);

    u.display();
    i.display();
    d.display();
}
