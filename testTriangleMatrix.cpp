#include <iostream>
#include "testTriangleMatrix.h"

using namespace std;

int TriangleMatrix() {
    ArrayTriangleMatrix<int>* arrayTriangleMatrixInt = nullptr;
    ListTriangleMatrix<int>* listTriangleMatrixInt = nullptr;
    int codeType = 0;

     while(1 + 1 == 2) {
        cout << endl;

        cout << "Enter a number for:" << endl;
        cout << "\t1 - To enter data" << endl; 
        cout << "\t2 - Add a new row" << endl;
        cout << "\t3 - Add a new column" << endl;
        cout << "\t4 - To to for multiplication by scalar" << endl; 
        cout << "\t5 - To adding matrix by matrix" << endl; 
        cout << "\t6 - To output norm matrix" << endl; 
        cout << "\t7 - To output dimension" << endl; 
        cout << "\t8 - To output matrix" << endl; 
        cout << "\t0 - To exit the test" << endl; 
        cout << endl << "Enter: ";
        
        int code = 0;
        cin >> code;

        cout << endl;

        switch(code) {
            case 1: 
                InputData(&codeType, &arrayTriangleMatrixInt, &listTriangleMatrixInt);
                break;

            case 2: 
                AddNewRow(&codeType, &arrayTriangleMatrixInt, &listTriangleMatrixInt);
                break;

            case 3: 
                AddNewColumn(&codeType, &arrayTriangleMatrixInt, &listTriangleMatrixInt);
                break;

            case 4: 
                MultByScalar(&codeType, &arrayTriangleMatrixInt, &listTriangleMatrixInt);
                break;

            case 5: 
                AddingMatrix(&codeType, &arrayTriangleMatrixInt, &listTriangleMatrixInt);
                break;

            case 6: 
                OutputNorm(&codeType, &arrayTriangleMatrixInt, &listTriangleMatrixInt);
                break;

            case 7: 
                OutputDimension(&codeType, &arrayTriangleMatrixInt, &listTriangleMatrixInt);
                break;

            case 8: 
                OutputMatrix(&codeType, &arrayTriangleMatrixInt, &listTriangleMatrixInt);
                break;

            case 0:
                delete arrayTriangleMatrixInt;
                delete listTriangleMatrixInt;

                cout << endl << "Exiting the test" << endl;
                return 0;

            default: 
                cout << "Input error, please re-enter" << endl << endl;
        } 
     }
}

int InputData(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt) {
    delete *arrayTriangleMatrixInt;
    delete *listTriangleMatrixInt;

    cout << "Enter a number for:" << endl;
    cout << "\t1 - To enter int ArrayTriangleMatrix" << endl;
    cout << "\t2 - To enter int ListTriangleMatrix" << endl;
    cout << "Enter: ";

    int code = 0;
    cin >> code;

    int dimension = 0;
    cout << "Enter the matrix dimension" << endl;
    cout << "Enter: ";
    cin >> dimension;

    switch(code) {
        case 1: {
            int** items = new int*[dimension];

            for (int i = 0; i < dimension; i++) {
                items[i] = new int[dimension];
            }

            cout << "Enter items:" << endl;
            for (int i = 0; i < dimension; i++) {
                for (int j = i; j < dimension; j++) {
                    cout << '[' << i << "][" << j << "]: "; 
                    cin >> items[i][j];
                }
            }

            delete *arrayTriangleMatrixInt;
            *arrayTriangleMatrixInt = new ArrayTriangleMatrix<int>(dimension, items);

            for (int i = 0; i < dimension; i++) {
                delete[] items[i];
            }

            delete[] items;

            *codeType = 1;
            cout << endl << endl;
            return 0;
            break;

        }

        case 2: {
            int** items = new int*[dimension];

            for (int i = 0; i < dimension; i++) {
                items[i] = new int[dimension];
            }

            cout << "Enter items:" << endl;
            for (int i = 0; i < dimension; i++) {
                for (int j = i; j < dimension; j++) {
                    cout << '[' << i << "][" << j << "]: "; 
                    cin >> items[i][j];
                }
            }

            delete *listTriangleMatrixInt;
            *listTriangleMatrixInt = new ListTriangleMatrix<int>(dimension, items);

            for (int i = 0; i < dimension; i++) {
                delete[] items[i];
            }

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

int AddNewRow(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    try {

        if (*codeType == 1) {
            int newRow[(*arrayTriangleMatrixInt)->GetDimension() + 1];

            cout << "Enter new row:" << endl;
            for (int i = 0; i < (*arrayTriangleMatrixInt)->GetDimension() + 1; i++) {
                cout << "[" << i << "]: ";
                cin >> newRow[i];
            }

            (*arrayTriangleMatrixInt)->AddRow(newRow);        
        }

        if (*codeType == 2) {
            int newRow[(*listTriangleMatrixInt)->GetDimension() + 1];

            cout << "Enter new row:" << endl;
            for (int i = 0; i < (*listTriangleMatrixInt)->GetDimension() + 1; i++) {
                cout << "[" << i << "]: ";
                cin >> newRow[i];
            }

            (*listTriangleMatrixInt)->AddRow(newRow);        
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int AddNewColumn(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    try {

        if (*codeType == 1) {
            int newColumn[(*arrayTriangleMatrixInt)->GetDimension() + 1];

            cout << "Enter new column:" << endl;
            for (int i = 0; i < (*arrayTriangleMatrixInt)->GetDimension() + 1; i++) {
                cout << "[" << i << "]: ";
                cin >> newColumn[i];
            }

            (*arrayTriangleMatrixInt)->AddColumn(newColumn);        
        }

        if (*codeType == 2) {
            int newColumn[(*listTriangleMatrixInt)->GetDimension() + 1];

            cout << "Enter new column:" << endl;
        
            for (int i = 0; i < (*listTriangleMatrixInt)->GetDimension() + 1; i++) {
                cout << "[" << i << "]: ";
                cin >> newColumn[i];
            }

            (*listTriangleMatrixInt)->AddColumn(newColumn);        
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int MultByScalar(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    try {

        if (*codeType == 1) {
            cout << "Enter the scalar: ";
            int scalar = 0;
            cin >> scalar;

            (*arrayTriangleMatrixInt)->MultScalar(scalar); 
        }

        if (*codeType == 2) {
            cout << "Enter the scalar: ";
            int scalar = 0;
            cin >> scalar;

            (*listTriangleMatrixInt)->MultScalar(scalar); 
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int AddingMatrix(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    try {

        if (*codeType == 1) {
            int** items = new int*[(*arrayTriangleMatrixInt)->GetDimension()];

            for (int i = 0; i < (*arrayTriangleMatrixInt)->GetDimension(); i++) {
                items[i] = new int[(*arrayTriangleMatrixInt)->GetDimension()];
            }

            cout << "Enter items:" << endl;
            for (int i = 0; i < (*arrayTriangleMatrixInt)->GetDimension(); i++) {
                for (int j = i; j < (*arrayTriangleMatrixInt)->GetDimension(); j++) {
                    cout << '[' << i << "][" << j << "]: "; 
                    cin >> items[i][j];
                }
            }

            ArrayTriangleMatrix<int>* secondMatrix = new ArrayTriangleMatrix<int>((*arrayTriangleMatrixInt)->GetDimension(), items);

            (*arrayTriangleMatrixInt)->AddMatrix(secondMatrix); 

            for (int i = 0; i < (*arrayTriangleMatrixInt)->GetDimension(); i++) {
                delete[] items[i];
            }
            delete[] items;
            delete secondMatrix;
        }

        if (*codeType == 2) {
            int** items = new int*[(*listTriangleMatrixInt)->GetDimension()];

            for (int i = 0; i < (*listTriangleMatrixInt)->GetDimension(); i++) {
                items[i] = new int[(*listTriangleMatrixInt)->GetDimension()];
            }

            cout << "Enter items:" << endl;
            for (int i = 0; i < (*listTriangleMatrixInt)->GetDimension(); i++) {
                for (int j = i; j < (*listTriangleMatrixInt)->GetDimension(); j++) {
                    cout << '[' << i << "][" << j << "]: "; 
                    cin >> items[i][j];
                }
            }

            ListTriangleMatrix<int>* secondMatrix = new ListTriangleMatrix<int>((*listTriangleMatrixInt)->GetDimension(), items);

            (*listTriangleMatrixInt)->AddMatrix(secondMatrix); 

            for (int i = 0; i < (*listTriangleMatrixInt)->GetDimension(); i++) {
                delete[] items[i];
            }
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

int OutputNorm(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        cout << "Norm: " << (*arrayTriangleMatrixInt)->GetNorm() << endl;
    }

    if (*codeType == 2) {
        cout << "Norm: " << (*listTriangleMatrixInt)->GetNorm() << endl;
    }

    return 0;
}

int OutputDimension(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        cout << "Matrix dimension: " << (*arrayTriangleMatrixInt)->GetDimension() << endl;
    }

    if (*codeType == 2) {
        cout << "Matrix dimension: " << (*listTriangleMatrixInt)->GetDimension() << endl;
    }

    return 0;
}

int OutputMatrix(int* codeType, ArrayTriangleMatrix<int>** arrayTriangleMatrixInt, ListTriangleMatrix<int>** listTriangleMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        for (int i = 0; i < (*arrayTriangleMatrixInt)->GetDimension(); i++) {
            for (int j = 0; j < (*arrayTriangleMatrixInt)->GetDimension(); j++) {
                if (i > j) {
                    cout << 0 << " ";
                } else {
                    cout << (*arrayTriangleMatrixInt)->Get(i, j) << " ";
                }
            }
            cout << endl;
        }
    }

    if (*codeType == 2) {
        for (int i = 0; i < (*listTriangleMatrixInt)->GetDimension(); i++) {
            for (int j = 0; j < (*listTriangleMatrixInt)->GetDimension(); j++) {
                if (i > j) {
                    cout << 0 << " ";
                } else {
                    cout << (*listTriangleMatrixInt)->Get(i, j) << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}