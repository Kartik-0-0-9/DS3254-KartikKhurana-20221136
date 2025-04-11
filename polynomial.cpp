#include <iostream>
using namespace std;

class Term {
public:
    int coeff, power;
    Term* next;
    Term(int c, int p) {
        coeff = c;
        power = p;
        next = nullptr;
    }
};

class Polynomial {
private:
    Term* head;
public:
    Polynomial() {
        head = nullptr;
    }

    void insertTerm(int coeff, int power) {
        Term* newTerm = new Term(coeff, power);
        if (!head || power > head->power) {
            newTerm->next = head;
            head = newTerm;
        } else {
            Term* temp = head;
            while (temp->next && temp->next->power > power)
                temp = temp->next;
            if (temp->power == power) {
                temp->coeff += coeff;
            } else if (temp->next && temp->next->power == power) {
                temp->next->coeff += coeff;
            } else {
                newTerm->next = temp->next;
                temp->next = newTerm;
            }
        }
    }

    void display() {
        Term* temp = head;
        while (temp) {
            cout << temp->coeff << "x^" << temp->power;
            if (temp->next) cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    Polynomial add(Polynomial& other) {
        Polynomial result;
        Term* p1 = head;
        Term* p2 = other.head;
        while (p1 && p2) {
            if (p1->power == p2->power) {
                result.insertTerm(p1->coeff + p2->coeff, p1->power);
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->power > p2->power) {
                result.insertTerm(p1->coeff, p1->power);
                p1 = p1->next;
            } else {
                result.insertTerm(p2->coeff, p2->power);
                p2 = p2->next;
            }
        }
        while (p1) {
            result.insertTerm(p1->coeff, p1->power);
            p1 = p1->next;
        }
        while (p2) {
            result.insertTerm(p2->coeff, p2->power);
            p2 = p2->next;
        }
        return result;
    }
};

int main() {
    Polynomial p1, p2;
    p1.insertTerm(3, 3);
    p1.insertTerm(2, 2);
    p1.insertTerm(1, 0);

    p2.insertTerm(5, 2);
    p2.insertTerm(4, 1);

    Polynomial result = p1.add(p2);
    result.display();
}
