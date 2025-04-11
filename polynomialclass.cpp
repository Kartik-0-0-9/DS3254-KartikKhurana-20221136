#include <iostream>
using namespace std;

class Term {
public:
    int coeff;
    int exp;
    Term(int c = 0, int e = 0) {
        coeff = c;
        exp = e;
    }
};

class Polynomial {
private:
    Term* terms;
    int size;
    int capacity;
public:
    Polynomial(int capacity = 10) {
        this->capacity = capacity;
        terms = new Term[capacity];
        size = 0;
    }

    ~Polynomial() {
        delete[] terms;
    }

    void addTerm(int coeff, int exp) {
        for (int i = 0; i < size; i++) {
            if (terms[i].exp == exp) {
                terms[i].coeff += coeff;
                return;
            }
        }
        terms[size++] = Term(coeff, exp);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << terms[i].coeff << "x^" << terms[i].exp;
            if (i != size - 1) cout << " + ";
        }
        cout << endl;
    }
};

int main() {
    Polynomial p;
    p.addTerm(3, 2);
    p.addTerm(2, 1);
    p.addTerm(4, 0);
    p.addTerm(1, 2);
    p.display();
}
