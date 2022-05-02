#include <iostream>
#include "RectangularMatrix.hpp"

using namespace std;

int main() {
    int n = 2;
    int m = 3;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = i + j;
        }
    }

    RectangularMatrix<int>* example = new RectangularMatrix<int>(2, 3, arr);

    example->addRow(arr[0], 2);
    example->addColumn(arr[1], 1);

    for (int i = 0; i < example->GetNumberRows(); i++) {
        for (int j = 0; j < example->GetNumberColumns(); j++) {
            cout << example->Get(i, j) << " ";
        }
        cout << endl;
    }

    

    return 0;
}