#include <iostream>
#include "ArrayRectangularMatrix.hpp"

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

    ArrayRectangularMatrix<int>* example = new ArrayRectangularMatrix<int>(2, 3, arr);

    for (int i = 0; i < example->GetNumberRows(); i++) {
        for (int j = 0; j < example->GetNumberColumns(); j++) {
            cout << example->Get(i, j) << " ";
        }
        cout << endl;
    }
        cout << endl;


    example->AddRow(arr[0], 2);
    example->AddColumn(arr[1], 1);

    for (int i = 0; i < example->GetNumberRows(); i++) {
        for (int j = 0; j < example->GetNumberColumns(); j++) {
            cout << example->Get(i, j) << " ";
        }
        cout << endl;
    }
        cout << endl;


    example->MultRow(2, 3);
    example->MultColumn(3, 4);

    for (int i = 0; i < example->GetNumberRows(); i++) {
        for (int j = 0; j < example->GetNumberColumns(); j++) {
            cout << example->Get(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;


    example->AddRowByRow(0, 1, 1);
    example->AddColumnByColumn(1, 2, 1);

    for (int i = 0; i < example->GetNumberRows(); i++) {
        for (int j = 0; j < example->GetNumberColumns(); j++) {
            cout << example->Get(i, j) << " ";
        }
        cout << endl;
    }
        cout << endl;



    example->SwapRows(0, 2);

    for (int i = 0; i < example->GetNumberRows(); i++) {
        for (int j = 0; j < example->GetNumberColumns(); j++) {
            cout << example->Get(i, j) << " ";
        }
        cout << endl;
    }
        cout << endl;

    ArrayRectangularMatrix<int>* example2 = new ArrayRectangularMatrix<int>;
    *example2 = *example;
    example->MultScalar(-4);

    for (int i = 0; i < example->GetNumberRows(); i++) {
        for (int j = 0; j < example->GetNumberColumns(); j++) {
            cout << example2->Get(i, j) << " ";
        }
        cout << endl;
    }
        cout << endl;

    example->AddMatrix(example2);

    for (int i = 0; i < example->GetNumberRows(); i++) {
        for (int j = 0; j < example->GetNumberColumns(); j++) {
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