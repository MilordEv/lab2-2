#include <iostream>
#include "testRectangularMatrix.h"

using namespace std;

int RectangularMatrix() {
    ArrayRectangularMatrix<int>* arrayRectangularMatrixInt = nullptr;
    ListRectangularMatrix<int>* listRectangularMatrixInt = nullptr;
    int codeType = 0;

     while(1 + 1 == 2) {
        cout << endl;

        cout << "Enter a number for:" << endl;
        cout << "\t1 - To enter data" << endl; 
        cout << "\t2 - Add a new row" << endl; 
        cout << "\t3 - Add a new column" << endl; 
        cout << "\t4 - Multiply a row by a digit" << endl; 
        cout << "\t5 - Multiply a column by a digit" << endl; 
        cout << "\t6 - Add row by row" << endl; 
        cout << "\t7 - Add column by column" << endl; 
        cout << "\t8 - To permute rows" << endl; 
        cout << "\t9 - To permute columns" << endl; 
        cout << "\t10 - To to for multiplication by scalar" << endl; 
        cout << "\t11 - To adding matrix by matrix" << endl; 
        cout << "\t12 - To output norm matrix" << endl; 
        cout << "\t13 - To output dimension" << endl; 
        cout << "\t14 - To output matrix" << endl; 
        cout << "\t0 - To exit the test" << endl; 
        cout << endl << "Enter: ";
        
        int code = 0;
        cin >> code;

        cout << endl;

        switch(code) {
            case 1: 
                InputData(&codeType, &arrayRectangularMatrixInt, &listRectangularMatrixInt);
                break;

            case 2: 
                AddNewRow(&codeType, &arrayRectangularMatrixInt, &listRectangularMatrixInt);
                break;

            case 3: 
                AddNewColumn(&codeType, &arrayRectangularMatrixInt, &listRectangularMatrixInt);
                break;

            case 4: 
                MultRowByDigit(&codeType, &arrayRectangularMatrixInt, &listRectangularMatrixInt);
                break;

            case 5: 
                MultColumnByDigit(&codeType, &arrayRectangularMatrixInt, &listRectangularMatrixInt);
                break;

            case 6: 
                AddingRows(&codeType, &arrayRectangularMatrixInt, &listRectangularMatrixInt);
                break;

            case 7: 
                AddingColumns(&codeType, &arrayRectangularMatrixInt, &listRectangularMatrixInt);
                break;

            case 8: 
                RowPermutation(&codeType, &arrayRectangularMatrixInt, &listRectangularMatrixInt);
                break;

            case 9: 
                ColumnPermutation(&codeType, &arrayRectangularMatrixInt, &listRectangularMatrixInt);
                break;

            case 10: 
                MultByScalar(&codeType, &arrayRectangularMatrixInt, &listRectangularMatrixInt);
                break;

            case 11: 
                AddingMatrix(&codeType, &arrayRectangularMatrixInt, &listRectangularMatrixInt);
                break;

            case 12: 
                OutputNorm(&codeType, &arrayRectangularMatrixInt, &listRectangularMatrixInt);
                break;

            case 13: 
                OutputDimension(&codeType, &arrayRectangularMatrixInt, &listRectangularMatrixInt);
                break;

            case 14: 
                OutputMatrix(&codeType, &arrayRectangularMatrixInt, &listRectangularMatrixInt);
                break;

            case 0:
                delete arrayRectangularMatrixInt;
                delete listRectangularMatrixInt;

                cout << endl << "Exiting the test" << endl;
                return 0;

            default: 
                cout << "Input error, please re-enter" << endl << endl;
        } 
     }
}

int InputData(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt) {
    delete *arrayRectangularMatrixInt;
    delete *listRectangularMatrixInt;

    cout << "Enter a number for:" << endl;
    cout << "\t1 - To enter int ArrayRectangularMatrix" << endl;
    cout << "\t2 - To enter int ListRectangularMatrix" << endl;
    cout << "Enter: ";

    int code = 0;
    cin >> code;

    int numberRow = 0;
    int numberColumns = 0;

    switch(code) {
        case 1: {
            cout << "Enter the number of rows" << endl;
            cout << "Enter: ";
            cin >> numberRow;

            cout << "Enter the number of columns" << endl;
            cout << "Enter: ";
            cin >> numberColumns;

            int** items = new int*[numberRow];

            for (int i = 0; i < numberRow; i++) {
                items[i] = new int[numberColumns];
            }

            cout << "Enter items:" << endl;
            for (int i = 0; i < numberRow; i++) {
                for (int j = 0; j < numberColumns; j++) {
                    cout << '[' << i << "][" << j << "]: "; 
                    cin >> items[i][j];
                }
            }

            delete *arrayRectangularMatrixInt;
            *arrayRectangularMatrixInt = new ArrayRectangularMatrix<int>(numberRow, numberColumns, items);

            for (int i = 0; i < numberRow; i++) {
                delete[] items[i];
            }

            delete[] items;

            *codeType = 1;
            cout << endl << endl;
            return 0;
            break;

        }

        case 2: {
            cout << "Enter the number of rows" << endl;
            cout << "Enter: ";
            cin >> numberRow;

            cout << "Enter the number of columns" << endl;
            cout << "Enter: ";
            cin >> numberColumns;

            int** items = new int*[numberRow];

            for (int i = 0; i < numberRow; i++) {
                items[i] = new int[numberColumns];
            }

            cout << "Enter items:" << endl;
            for (int i = 0; i < numberRow; i++) {
                for (int j = 0; j < numberColumns; j++) {
                    cout << '[' << i << "][" << j << "]: "; 
                    cin >> items[i][j];
                }
            }

            delete *listRectangularMatrixInt;
            *listRectangularMatrixInt = new ListRectangularMatrix<int>(numberRow, numberColumns, items);

            for (int i = 0; i < numberRow; i++) {
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

int AddNewRow(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    cout << "Enter the index where the new row will be inserted: ";
    int index = 0;
    cin >> index;

    try {

        if (*codeType == 1) {
            int newRow[(*arrayRectangularMatrixInt)->GetNumberColumns()];

            cout << "Enter new row:" << endl;
            for (int i = 0; i < (*arrayRectangularMatrixInt)->GetNumberColumns(); i++) {
                cout << "[" << i << "]: ";
                cin >> newRow[i];
            }

            (*arrayRectangularMatrixInt)->AddRow(newRow, index);        
        }

        if (*codeType == 2) {
            int newRow[(*listRectangularMatrixInt)->GetNumberColumns()];

            for (int i = 0; i < (*listRectangularMatrixInt)->GetNumberColumns(); i++) {
                cout << "[" << i << "]: ";
                cin >> newRow[i];
            }

            (*listRectangularMatrixInt)->AddRow(newRow, index);  
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int AddNewColumn(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    cout << "Enter the index where the new column will be inserted: ";
    int index = 0;
    cin >> index;

    try {

        if (*codeType == 1) {
            int newColumn[(*arrayRectangularMatrixInt)->GetNumberRows()];

            cout << "Enter new column:" << endl;
            for (int i = 0; i < (*arrayRectangularMatrixInt)->GetNumberRows(); i++) {
                cout << "[" << i << "]: ";
                cin >> newColumn[i];
            }

            (*arrayRectangularMatrixInt)->AddColumn(newColumn, index);        
        }

        if (*codeType == 2) {
            int newColumn[(*listRectangularMatrixInt)->GetNumberRows()];

            for (int i = 0; i < (*listRectangularMatrixInt)->GetNumberRows(); i++) {
                cout << "[" << i << "]: ";
                cin >> newColumn[i];
            }

            (*listRectangularMatrixInt)->AddColumn(newColumn, index);  
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int MultRowByDigit(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt) {
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

            (*arrayRectangularMatrixInt)->MultRow(index, digit); 
        }

        if (*codeType == 2) {
            cout << "Enter the number by which you want to multiply the row: ";
            int digit = 0;
            cin >> digit;

            (*listRectangularMatrixInt)->MultRow(index, digit); 
        }
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }

    return 0;
}

int MultColumnByDigit(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt) {
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

            (*arrayRectangularMatrixInt)->MultColumn(index, digit); 
        }

        if (*codeType == 2) {
            cout << "Enter the number by which you want to multiply the column: ";
            int digit = 0;
            cin >> digit;

            (*listRectangularMatrixInt)->MultColumn(index, digit); 
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int AddingRows(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt) {
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

            (*arrayRectangularMatrixInt)->AddRowByRow(indexFromRow, indexToRow, digit); 
        }

        if (*codeType == 2) {
            cout << "Enter the coefficient by which you want to multiply the second row: ";
            int digit = 0;
            cin >> digit;

            (*listRectangularMatrixInt)->AddRowByRow(indexFromRow, indexToRow, digit); 
        }
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }

    return 0;
}

int AddingColumns(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt) {
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

            (*arrayRectangularMatrixInt)->AddColumnByColumn(indexFromColumn, indexToColumn, digit); 
        }

        if (*codeType == 2) {
            cout << "Enter the number by which you want to multiply the column: ";
            int digit = 0;
            cin >> digit;

            (*listRectangularMatrixInt)->AddColumnByColumn(indexFromColumn, indexToColumn, digit); 
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int RowPermutation(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt) {
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
            (*arrayRectangularMatrixInt)->SwapRows(indexFirstRow, indexSecondRow); 
        }

        if (*codeType == 2) {
            (*listRectangularMatrixInt)->SwapRows(indexFirstRow, indexSecondRow); 
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int ColumnPermutation(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt) {
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
            (*arrayRectangularMatrixInt)->SwapColumns(indexFirstColumn, indexSecondColumn); 
        }

        if (*codeType == 2) {
            (*listRectangularMatrixInt)->SwapColumns(indexFirstColumn, indexSecondColumn); 
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int MultByScalar(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    try {

        if (*codeType == 1) {
            cout << "Enter the scalar: ";
            int scalar = 0;
            cin >> scalar;

            (*arrayRectangularMatrixInt)->MultScalar(scalar); 
        }

        if (*codeType == 2) {
            cout << "Enter the scalar: ";
            int scalar = 0;
            cin >> scalar;

            (*listRectangularMatrixInt)->MultScalar(scalar); 
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int AddingMatrix(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    try {

        if (*codeType == 1) {
            int** items = new int*[(*arrayRectangularMatrixInt)->GetNumberRows()];

            for (int i = 0; i < (*arrayRectangularMatrixInt)->GetNumberRows(); i++) {
                items[i] = new int[(*arrayRectangularMatrixInt)->GetNumberColumns()];
            }

            cout << "Enter items:" << endl;
            for (int i = 0; i < (*arrayRectangularMatrixInt)->GetNumberRows(); i++) {
                for (int j = 0; j < (*arrayRectangularMatrixInt)->GetNumberColumns(); j++) {
                    cout << '[' << i << "][" << j << "]: "; 
                    cin >> items[i][j];
                }
            }

            ArrayRectangularMatrix<int>* secondMatrix = new ArrayRectangularMatrix<int>((*arrayRectangularMatrixInt)->GetNumberRows(), (*arrayRectangularMatrixInt)->GetNumberColumns(), items);

            (*arrayRectangularMatrixInt)->AddMatrix(secondMatrix); 

            for (int i = 0; i < (*arrayRectangularMatrixInt)->GetNumberRows(); i++) {
                delete[] items[i];
            }
            delete[] items;
            delete secondMatrix;
        }

        if (*codeType == 2) {
            int** items = new int*[(*listRectangularMatrixInt)->GetNumberRows()];

            for (int i = 0; i < (*listRectangularMatrixInt)->GetNumberRows(); i++) {
                items[i] = new int[(*listRectangularMatrixInt)->GetNumberColumns()];
            }

            cout << "Enter items:" << endl;
            for (int i = 0; i < (*listRectangularMatrixInt)->GetNumberRows(); i++) {
                for (int j = 0; j < (*listRectangularMatrixInt)->GetNumberColumns(); j++) {
                    cout << '[' << i << "][" << j << "]: "; 
                    cin >> items[i][j];
                }
            }

            ListRectangularMatrix<int>* secondMatrix = new ListRectangularMatrix<int>((*listRectangularMatrixInt)->GetNumberRows(), (*listRectangularMatrixInt)->GetNumberColumns(), items);

            (*listRectangularMatrixInt)->AddMatrix(secondMatrix); 

            for (int i = 0; i < (*listRectangularMatrixInt)->GetNumberRows(); i++) {
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

int OutputNorm(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        cout << "Norm: " << (*arrayRectangularMatrixInt)->GetNorm() << endl;
    }

    if (*codeType == 2) {
        cout << "Norm: " << (*listRectangularMatrixInt)->GetNorm() << endl;
    }

    return 0;
}

int OutputDimension(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        cout << "Number rows: " << (*arrayRectangularMatrixInt)->GetNumberRows() << endl;
        cout << "Number columns: " << (*arrayRectangularMatrixInt)->GetNumberColumns() << endl;
    }

    if (*codeType == 2) {
        cout << "Number rows: " << (*listRectangularMatrixInt)->GetNumberRows() << endl;
        cout << "Number columns: " << (*listRectangularMatrixInt)->GetNumberColumns() << endl;
    }

    return 0;
}

int OutputMatrix(int* codeType, ArrayRectangularMatrix<int>** arrayRectangularMatrixInt, ListRectangularMatrix<int>** listRectangularMatrixInt) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        for (int i = 0; i < (*arrayRectangularMatrixInt)->GetNumberRows(); i++) {
            for (int j = 0; j < (*arrayRectangularMatrixInt)->GetNumberColumns(); j++) {
                cout << (*arrayRectangularMatrixInt)->Get(i, j) << " ";
            }
            cout << endl;
        }
    }

    if (*codeType == 2) {
        for (int i = 0; i < (*listRectangularMatrixInt)->GetNumberRows(); i++) {
            for (int j = 0; j < (*listRectangularMatrixInt)->GetNumberColumns(); j++) {
                cout << (*listRectangularMatrixInt)->Get(i, j) << " ";
            }
            cout << endl;
        }
    }

    return 0;
}