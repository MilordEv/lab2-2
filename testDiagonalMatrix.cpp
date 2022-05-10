#include <iostream>
#include "testDiagonalMatrix.h"

using namespace std;

int DiagonalMatrix() {
    ArrayDiagonalMatrix<int>* arrayDiagonalMatrixInt = nullptr;
    ListDiagonalMatrix<int>* listDiagonalMatrixInt = nullptr;
    int codeType = 0;

     while(1 + 1 == 2) {
        cout << endl;

        cout << "Enter a number for:" << endl;
        cout << "\t1 - To enter data" << endl; 
        cout << "\t2 - Add a new row or new column" << endl;
        cout << "\t3 - To to for multiplication by scalar" << endl; 
        cout << "\t4 - To adding matrix by matrix" << endl; 
        cout << "\t5 - To output norm matrix" << endl; 
        cout << "\t6 - To output dimension" << endl; 
        cout << "\t7 - To output matrix" << endl; 
        cout << "\t0 - To exit the test" << endl; 
        cout << endl << "Enter: ";
        
        int code = 0;
        cin >> code;

        cout << endl;

        switch(code) {
            case 1: 
                InputData(&codeType, &arrayDiagonalMatrixInt, &listDiagonalMatrixInt);
                break;

            case 2: 
                AddNewRowOrNewColumn(&codeType, &arrayDiagonalMatrixInt, &listDiagonalMatrixInt);
                break;

            case 3: 
                MultByScalar(&codeType, &arrayDiagonalMatrixInt, &listDiagonalMatrixInt);
                break;

            case 4: 
                AddingMatrix(&codeType, &arrayDiagonalMatrixInt, &listDiagonalMatrixInt);
                break;

            case 5: 
                OutputNorm(&codeType, &arrayDiagonalMatrixInt, &listDiagonalMatrixInt);
                break;

            case 6: 
                OutputDimension(&codeType, &arrayDiagonalMatrixInt, &listDiagonalMatrixInt);
                break;

            case 7: 
                OutputMatrix(&codeType, &arrayDiagonalMatrixInt, &listDiagonalMatrixInt);
                break;

            case 0:
                delete arrayDiagonalMatrixInt;
                delete listDiagonalMatrixInt;

                cout << endl << "Exiting the test" << endl;
                return 0;

            default: 
                cout << "Input error, please re-enter" << endl << endl;
        } 
     }
}

int InputData(int* codeType, ArrayDiagonalMatrix<int>** arrayDiagonalMatrixInt, ListDiagonalMatrix<int>** listDiagonalMatrixInt) {
    delete *arrayDiagonalMatrixInt;
    delete *listDiagonalMatrixInt;

    cout << "Enter a number for:" << endl;
    cout << "\t1 - To enter int ArrayDiagonalMatrix" << endl;
    cout << "\t2 - To enter int ListDiagonalMatrix" << endl;
    cout << "Enter: ";

    int code = 0;
    cin >> code;

    int dimension = 0;
    cout << "Enter the matrix dimension" << endl;
    cout << "Enter: ";
    cin >> dimension;

    switch(code) {
        case 1: {
            int* items = new int[dimension];

            cout << "Enter items:" << endl;
            for (int i = 0; i < dimension; i++) {
                cout << '[' << i << "][" << i << "]: "; 
                cin >> items[i];
            }
            

            delete *arrayDiagonalMatrixInt;
            *arrayDiagonalMatrixInt = new ArrayDiagonalMatrix<int>(dimension, items);

            delete[] items;

            *codeType = 1;
            cout << endl << endl;
            return 0;
            break;

        }

        case 2: {
            int* items = new int[dimension];

            cout << "Enter items:" << endl;
            for (int i = 0; i < dimension; i++) {
                cout << '[' << i << "][" << i << "]: "; 
                cin >> items[i];
            }
            

            delete *listDiagonalMatrixInt;
            *listDiagonalMatrixInt = new ListDiagonalMatrix<int>(dimension, items);

            delete[] items;

            *codeType = 2;
            cout << endl << endl;
            return 0;
            break;


        }

        default:
            cout << "You make mistake" << endl << endl << endl;
            return -1;
    }
}

int AddNewRowOrNewColumn(int* codeType, ArrayDiagonalMatrix<int>** arrayDiagonalMatrixInt, ListDiagonalMatrix<int>** listDiagonalMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    cout << "Enter the index where to insert the element: ";
    int index = 0;
    cin >> index;

    try {

        if (*codeType == 1) {
            cout << "Enter new item: ";
            int newItem = 0;
            cin >> newItem;

            (*arrayDiagonalMatrixInt)->InsertRowOrColumn(index , newItem);        
        }

        if (*codeType == 2) {
            cout << "Enter new item: ";
            int newItem = 0;
            cin >> newItem;

            (*listDiagonalMatrixInt)->InsertRowOrColumn(index , newItem);    
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int MultByScalar(int* codeType, ArrayDiagonalMatrix<int>** arrayDiagonalMatrixInt, ListDiagonalMatrix<int>** listDiagonalMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    try {

        if (*codeType == 1) {
            cout << "Enter the scalar: ";
            int scalar = 0;
            cin >> scalar;

            (*arrayDiagonalMatrixInt)->MultScalar(scalar); 
        }

        if (*codeType == 2) {
            cout << "Enter the scalar: ";
            int scalar = 0;
            cin >> scalar;

            (*listDiagonalMatrixInt)->MultScalar(scalar); 
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int AddingMatrix(int* codeType, ArrayDiagonalMatrix<int>** arrayDiagonalMatrixInt, ListDiagonalMatrix<int>** listDiagonalMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    try {

        if (*codeType == 1) {
            int* items = new int[(*arrayDiagonalMatrixInt)->GetDimension()];

            cout << "Enter items:" << endl;
            for (int i = 0; i < (*arrayDiagonalMatrixInt)->GetDimension(); i++) {
                cout << '[' << i << "][" << i << "]: "; 
                cin >> items[i];
            }

            ArrayDiagonalMatrix<int>* secondMatrix = new ArrayDiagonalMatrix<int>((*arrayDiagonalMatrixInt)->GetDimension(), items);

            (*arrayDiagonalMatrixInt)->AddMatrix(secondMatrix); 

            delete[] items;
            delete secondMatrix;
        }

        if (*codeType == 2) {
            int* items = new int[(*listDiagonalMatrixInt)->GetDimension()];

            cout << "Enter items:" << endl;
            for (int i = 0; i < (*listDiagonalMatrixInt)->GetDimension(); i++) {
                cout << '[' << i << "][" << i << "]: "; 
                cin >> items[i];
            }

            ListDiagonalMatrix<int>* secondMatrix = new ListDiagonalMatrix<int>((*listDiagonalMatrixInt)->GetDimension(), items);

            (*listDiagonalMatrixInt)->AddMatrix(secondMatrix); 

            delete[] items;
            delete secondMatrix;
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int OutputNorm(int* codeType, ArrayDiagonalMatrix<int>** arrayDiagonalMatrixInt, ListDiagonalMatrix<int>** listDiagonalMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        cout << "Norm: " << (*arrayDiagonalMatrixInt)->GetNorm() << endl;
    }

    if (*codeType == 2) {
        cout << "Norm: " << (*listDiagonalMatrixInt)->GetNorm() << endl;
    }

    return 0;
}

int OutputDimension(int* codeType, ArrayDiagonalMatrix<int>** arrayDiagonalMatrixInt, ListDiagonalMatrix<int>** listDiagonalMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        cout << "Matrix dimension: " << (*arrayDiagonalMatrixInt)->GetDimension() << endl;
    }

    if (*codeType == 2) {
        cout << "Matrix dimension: " << (*listDiagonalMatrixInt)->GetDimension() << endl;
    }

    return 0;
}

int OutputMatrix(int* codeType, ArrayDiagonalMatrix<int>** arrayDiagonalMatrixInt, ListDiagonalMatrix<int>** listDiagonalMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        for (int i = 0; i < (*arrayDiagonalMatrixInt)->GetDimension(); i++) {
            for (int j = 0; j < (*arrayDiagonalMatrixInt)->GetDimension(); j++) {
                if (i != j) {
                    cout << 0 << " ";
                } else {
                    cout << (*arrayDiagonalMatrixInt)->Get(i, j) << " ";
                }
            }
            cout << endl;
        }
    }

    if (*codeType == 2) {
        for (int i = 0; i < (*listDiagonalMatrixInt)->GetDimension(); i++) {
            for (int j = 0; j < (*listDiagonalMatrixInt)->GetDimension(); j++) {
                if (i != j) {
                    cout << 0 << " ";
                } else {
                    cout << (*listDiagonalMatrixInt)->Get(i, j) << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}