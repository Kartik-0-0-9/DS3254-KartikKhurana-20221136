#include <iostream>
#include <map>
using namespace std;

class SparseMatrix {
private:
    int rows, cols;
    map<pair<int, int>, int> elements;

public:
    SparseMatrix(int r, int c) {
        rows = r;
        cols = c;
    }

    void set(int i, int j, int val) {
        if (val != 0)
            elements[{i, j}] = val;
        else
            elements.erase({i, j});
    }

    int get(int i, int j) {
        if (elements.count({i, j}))
            return elements[{i, j}];
        return 0;
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    SparseMatrix mat(3, 3);
    mat.set(0, 0, 5);
    mat.set(1, 2, 9);
    mat.set(2, 1, 4);
    mat.display();
}
