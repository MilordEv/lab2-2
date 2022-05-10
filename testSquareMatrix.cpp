#include <iostream>
#include "testSquareMatrix.h"

using namespace std;

int SquareMatrix() {
    ArraySquareMatrix<int>* arraySquareMatrixInt = nullptr;
    ListSquareMatrix<int>* listSquareMatrixInt = nullptr;
    int codeType = 0;

     while(1 + 1 == 2) {
        cout << endl;

        cout << "Enter a number for:" << endl;
        cout << "\t1 - To enter data" << endl; 
        cout << "\t2 - Add a new row and new column" << endl; 
        cout << "\t3 - Multiply a row by a digit" << endl; 
        cout << "\t4 - Multiply a column by a digit" << endl; 
        cout << "\t5 - Add row by row" << endl; 
        cout << "\t6 - Add column by column" << endl; 
        cout << "\t7 - To permute rows" << endl; 
        cout << "\t8 - To permute columns" << endl; 
        cout << "\t9 - To to for multiplication by scalar" << endl; 
        cout << "\t10 - To adding matrix by matrix" << endl; 
        cout << "\t11 - To output norm matrix" << endl; 
        cout << "\t12 - To output dimension" << endl; 
        cout << "\t13 - To output matrix" << endl; 
        cout << "\t0 - To exit the test" << endl; 
        cout << endl << "Enter: ";
        
        int code = 0;
        cin >> code;

        cout << endl;

        switch(code) {
            case 1: 
                InputData(&codeType, &arraySquareMatrixInt, &listSquareMatrixInt);
                break;

            case 2: 
                AddNewRowAndColumn(&codeType, &arraySquareMatrixInt, &listSquareMatrixInt);
                break;

            case 3: 
                MultRowByDigit(&codeType, &arraySquareMatrixInt, &listSquareMatrixInt);
                break;

            case 4: 
                MultColumnByDigit(&codeType, &arraySquareMatrixInt, &listSquareMatrixInt);
                break;

            case 5: 
                AddingRows(&codeType, &arraySquareMatrixInt, &listSquareMatrixInt);
                break;

            case 6: 
                AddingColumns(&codeType, &arraySquareMatrixInt, &listSquareMatrixInt);
                break;

            case 7: 
                RowPermutation(&codeType, &arraySquareMatrixInt, &listSquareMatrixInt);
                break;

            case 8: 
                ColumnPermutation(&codeType, &arraySquareMatrixInt, &listSquareMatrixInt);
                break;

            case 9: 
                MultByScalar(&codeType, &arraySquareMatrixInt, &listSquareMatrixInt);
                break;

            case 10: 
                AddingMatrix(&codeType, &arraySquareMatrixInt, &listSquareMatrixInt);
                break;

            case 11: 
                OutputNorm(&codeType, &arraySquareMatrixInt, &listSquareMatrixInt);
                break;

            case 12: 
                OutputDimension(&codeType, &arraySquareMatrixInt, &listSquareMatrixInt);
                break;

            case 13: 
                OutputMatrix(&codeType, &arraySquareMatrixInt, &listSquareMatrixInt);
                break;

            case 0:
                delete arraySquareMatrixInt;
                delete listSquareMatrixInt;

                cout << endl << "Exiting the test" << endl;
                return 0;

            default: 
                cout << "Input error, please re-enter" << endl << endl;
        } 
     }
}

int InputData(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listSquareMatrixInt) {
    delete *arraySquareMatrixInt;
    delete *listSquareMatrixInt;

    cout << "Enter a number for:" << endl;
    cout << "\t1 - To enter int ArraySquareMatrix" << endl;
    cout << "\t2 - To enter int ListSquareMatrix" << endl;
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
                for (int j = 0; j < dimension; j++) {
                    cout << '[' << i << "][" << j << "]: "; 
                    cin >> items[i][j];
                }
            }

            delete *arraySquareMatrixInt;
            *arraySquareMatrixInt = new ArraySquareMatrix<int>(dimension, items);

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
                for (int j = 0; j < dimension; j++) {
                    cout << '[' << i << "][" << j << "]: "; 
                    cin >> items[i][j];
                }
            }

            delete *listSquareMatrixInt;
            *listSquareMatrixInt = new ListSquareMatrix<int>(dimension, items);

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

int AddNewRowAndColumn(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listSquareMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    cout << "Enter the index where the new row will be inserted: ";
    int indexRow = 0;
    cin >> indexRow;

    cout << "Enter the index where the new column will be inserted: ";
    int indexColumn = 0;
    cin >> indexColumn;

    try {

        if (*codeType == 1) {
            int newRow[(*arraySquareMatrixInt)->GetDimension()];

            cout << "Enter new row:" << endl;
            for (int i = 0; i < (*arraySquareMatrixInt)->GetDimension(); i++) {
                cout << "[" << i << "]: ";
                cin >> newRow[i];
            }

            int newColumn[(*arraySquareMatrixInt)->GetDimension() + 1];

            cout << "Enter new column:" << endl;
            for (int i = 0; i < (*arraySquareMatrixInt)->GetDimension() + 1; i++) {
                cout << "[" << i << "]: ";
                cin >> newColumn[i];
            }

            (*arraySquareMatrixInt)->AddRowAndColumn(newRow, indexRow, newColumn, indexColumn);        
        }

        if (*codeType == 2) {
            int newRow[(*listSquareMatrixInt)->GetDimension()];

            cout << "Enter new row:" << endl;
            for (int i = 0; i < (*listSquareMatrixInt)->GetDimension(); i++) {
                cout << "[" << i << "]: ";
                cin >> newRow[i];
            }

            int newColumn[(*listSquareMatrixInt)->GetDimension() + 1];

            cout << "Enter new row:" << endl;
            for (int i = 0; i < (*listSquareMatrixInt)->GetDimension() + 1; i++) {
                cout << "[" << i << "]: ";
                cin >> newColumn[i];
            }

            (*listSquareMatrixInt)->AddRowAndColumn(newRow, indexRow, newColumn, indexColumn);        
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int MultRowByDigit(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listSquareMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    cout << "Enter the index of the row to be multiplied: ";
    int index = 0;
    cin >> index;

    try {

        if (*codeType == 1) {
            cout << "Enter the number by which you want to multiply the row: ";
            int digit = 0;
            cin >> digit;

            (*arraySquareMatrixInt)->MultRow(index, digit); 
        }

        if (*codeType == 2) {
            cout << "Enter the number by which you want to multiply the row: ";
            int digit = 0;
            cin >> digit;

            (*listSquareMatrixInt)->MultRow(index, digit); 
        }
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }

    return 0;
}

int MultColumnByDigit(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listSquareMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    cout << "Enter the index of the column to be multiplied: ";
    int index = 0;
    cin >> index;

    try {

        if (*codeType == 1) {
            cout << "Enter the number by which you want to multiply the column: ";
            int digit = 0;
            cin >> digit;

            (*arraySquareMatrixInt)->MultColumn(index, digit); 
        }

        if (*codeType == 2) {
            cout << "Enter the number by which you want to multiply the column: ";
            int digit = 0;
            cin >> digit;

            (*listSquareMatrixInt)->MultColumn(index, digit); 
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int AddingRows(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listSquareMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    cout << "Enter the index of the row to which you will add from other row: ";
    int indexFromRow = 0;
    cin >> indexFromRow;

    cout << "Enter the index of the row to which you will add to other row: ";
    int indexToRow = 0;
    cin >> indexToRow;

    try {

        if (*codeType == 1) {
            cout << "Enter the coefficient by which you want to multiply the second row: ";
            int digit = 0;
            cin >> digit;

            (*arraySquareMatrixInt)->AddRowByRow(indexFromRow, indexToRow, digit); 
        }

        if (*codeType == 2) {
            cout << "Enter the coefficient by which you want to multiply the second row: ";
            int digit = 0;
            cin >> digit;

            (*listSquareMatrixInt)->AddRowByRow(indexFromRow, indexToRow, digit); 
        }
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }

    return 0;
}

int AddingColumns(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listSquareMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    cout << "Enter the index of the column to which you will add from other column: ";
    int indexFromColumn = 0;
    cin >> indexFromColumn;

    cout << "Enter the index of the column to which you will add to other column: ";
    int indexToColumn = 0;
    cin >> indexToColumn;

    try {

        if (*codeType == 1) {
            cout << "Enter the coefficient by which you want to multiply the second column: ";
            int digit = 0;
            cin >> digit;

            (*arraySquareMatrixInt)->AddColumnByColumn(indexFromColumn, indexToColumn, digit); 
        }

        if (*codeType == 2) {
            cout << "Enter the number by which you want to multiply the column: ";
            int digit = 0;
            cin >> digit;

            (*listSquareMatrixInt)->AddColumnByColumn(indexFromColumn, indexToColumn, digit); 
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int RowPermutation(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listSquareMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    cout << "Enter the index of the first row: ";
    int indexFirstRow = 0;
    cin >> indexFirstRow;

    cout << "Enter the index of the second row: ";
    int indexSecondRow = 0;
    cin >> indexSecondRow;

    try {

        if (*codeType == 1) {
            (*arraySquareMatrixInt)->SwapRows(indexFirstRow, indexSecondRow); 
        }

        if (*codeType == 2) {
            (*listSquareMatrixInt)->SwapRows(indexFirstRow, indexSecondRow); 
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int ColumnPermutation(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listSquareMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    cout << "Enter the index of the first column: ";
    int indexFirstColumn = 0;
    cin >> indexFirstColumn;

    cout << "Enter the index of the second column: ";
    int indexSecondColumn = 0;
    cin >> indexSecondColumn;

    try {

        if (*codeType == 1) {
            (*arraySquareMatrixInt)->SwapColumns(indexFirstColumn, indexSecondColumn); 
        }

        if (*codeType == 2) {
            (*listSquareMatrixInt)->SwapColumns(indexFirstColumn, indexSecondColumn); 
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int MultByScalar(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listSquareMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    try {

        if (*codeType == 1) {
            cout << "Enter the scalar: ";
            int scalar = 0;
            cin >> scalar;

            (*arraySquareMatrixInt)->MultScalar(scalar); 
        }

        if (*codeType == 2) {
            cout << "Enter the scalar: ";
            int scalar = 0;
            cin >> scalar;

            (*listSquareMatrixInt)->MultScalar(scalar); 
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int AddingMatrix(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listSquareMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    try {

        if (*codeType == 1) {
            int** items = new int*[(*arraySquareMatrixInt)->GetDimension()];

            for (int i = 0; i < (*arraySquareMatrixInt)->GetDimension(); i++) {
                items[i] = new int[(*arraySquareMatrixInt)->GetDimension()];
            }

            cout << "Enter items:" << endl;
            for (int i = 0; i < (*arraySquareMatrixInt)->GetDimension(); i++) {
                for (int j = 0; j < (*arraySquareMatrixInt)->GetDimension(); j++) {
                    cout << '[' << i << "][" << j << "]: "; 
                    cin >> items[i][j];
                }
            }

            ArraySquareMatrix<int>* secondMatrix = new ArraySquareMatrix<int>((*arraySquareMatrixInt)->GetDimension(), items);

            (*arraySquareMatrixInt)->AddMatrix(secondMatrix); 

            for (int i = 0; i < (*arraySquareMatrixInt)->GetDimension(); i++) {
                delete[] items[i];
            }
            delete[] items;
            delete secondMatrix;
        }

        if (*codeType == 2) {
            int** items = new int*[(*listSquareMatrixInt)->GetDimension()];

            for (int i = 0; i < (*listSquareMatrixInt)->GetDimension(); i++) {
                items[i] = new int[(*listSquareMatrixInt)->GetDimension()];
            }

            cout << "Enter items:" << endl;
            for (int i = 0; i < (*listSquareMatrixInt)->GetDimension(); i++) {
                for (int j = 0; j < (*listSquareMatrixInt)->GetDimension(); j++) {
                    cout << '[' << i << "][" << j << "]: "; 
                    cin >> items[i][j];
                }
            }

            ListSquareMatrix<int>* secondMatrix = new ListSquareMatrix<int>((*listSquareMatrixInt)->GetDimension(), items);

            (*listSquareMatrixInt)->AddMatrix(secondMatrix); 

            for (int i = 0; i < (*listSquareMatrixInt)->GetDimension(); i++) {
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

int OutputNorm(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listSquareMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        cout << "Norm: " << (*arraySquareMatrixInt)->GetNorm() << endl;
    }

    if (*codeType == 2) {
        cout << "Norm: " << (*listSquareMatrixInt)->GetNorm() << endl;
    }

    return 0;
}

int OutputDimension(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listSquareMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        cout << "Matrix dimension: " << (*arraySquareMatrixInt)->GetDimension() << endl;
    }

    if (*codeType == 2) {
        cout << "Matrix dimension: " << (*listSquareMatrixInt)->GetDimension() << endl;
    }

    return 0;
}

int OutputMatrix(int* codeType, ArraySquareMatrix<int>** arraySquareMatrixInt, ListSquareMatrix<int>** listSquareMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        for (int i = 0; i < (*arraySquareMatrixInt)->GetDimension(); i++) {
            for (int j = 0; j < (*arraySquareMatrixInt)->GetDimension(); j++) {
                cout << (*arraySquareMatrixInt)->Get(i, j) << " ";
            }
            cout << endl;
        }
    }

    if (*codeType == 2) {
        for (int i = 0; i < (*listSquareMatrixInt)->GetDimension(); i++) {
            for (int j = 0; j < (*listSquareMatrixInt)->GetDimension(); j++) {
                cout << (*listSquareMatrixInt)->Get(i, j) << " ";
            }
            cout << endl;
        }
    }

    return 0;
}