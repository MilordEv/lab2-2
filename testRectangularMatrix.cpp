#include <iostream>
#include "ArraySquareMatrix.hpp"

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

    ArraySquareMatrix<int>* example = new ArraySquareMatrix<int>(2, arr);

    for (int i = 0; i < example->GetDimension(); i++) {
        for (int j = 0; j < example->GetDimension(); j++) {
            cout << example->Get(i, j) << " ";
        }
        cout << endl;
    }
        cout << endl;


    example->AddRowAndColumn(arr[0], 1, arr[1], 1);

    for (int i = 0; i < example->GetDimension(); i++) {
        for (int j = 0; j < example->GetDimension(); j++) {
            cout << example->Get(i, j) << " ";
        }
        cout << endl;
    }
        cout << endl;


    example->MultRow(2, 3);
    example->MultColumn(2, 4);

    for (int i = 0; i < example->GetDimension(); i++) {
        for (int j = 0; j < example->GetDimension(); j++) {
            cout << example->Get(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;


    example->AddRowByRow(0, 1, 1);
    example->AddColumnByColumn(1, 2, 1);

    for (int i = 0; i < example->GetDimension(); i++) {
        for (int j = 0; j < example->GetDimension(); j++) {
            cout << example->Get(i, j) << " ";
        }
        cout << endl;
    }
        cout << endl;



    example->SwapRows(0, 2);

    for (int i = 0; i < example->GetDimension(); i++) {
        for (int j = 0; j < example->GetDimension(); j++) {
            cout << example->Get(i, j) << " ";
        }
        cout << endl;
    }
        cout << endl;

    ArraySquareMatrix<int>* example2 = new ArraySquareMatrix<int>;
    *example2 = *example;
    example->MultScalar(-4);

    for (int i = 0; i < example->GetDimension(); i++) {
        for (int j = 0; j < example->GetDimension(); j++) {
            cout << example2->Get(i, j) << " ";
        }
        cout << endl;
    }
        cout << endl;

    example->AddMatrix(example2);

    for (int i = 0; i < example->GetDimension(); i++) {
        for (int j = 0; j < example->GetDimension(); j++) {
            cout << example->Get(i, j) << " ";
        }
        cout << endl;
    }

    
    for (int i =0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete example;
    return 0;
}