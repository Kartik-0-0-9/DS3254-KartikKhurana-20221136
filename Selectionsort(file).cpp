#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) return 1;
    ifstream file(argv[1]);
    int n;
    file >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        file >> arr[i];
    }
    file.close();
    selectionSort(arr);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}