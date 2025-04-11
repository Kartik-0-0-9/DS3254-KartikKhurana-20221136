#include <iostream>
using namespace std;

class Matrix1D {
private:
    int* data;
    int rows, cols;

public:
    Matrix1D(int r, int c) {
        rows = r;
        cols = c;
        data = new int[r * c];
    }

    ~Matrix1D() {
        delete[] data;
    }

    void set(int i, int j, int val) {
        data[i * cols + j] = val;
    }

    int get(int i, int j) {
        return data[i * cols + j];
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
    Matrix1D mat(3, 3);
    int k = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            mat.set(i, j, k++);
    mat.display();
}
