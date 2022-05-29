#include <iostream>
#include "testVector.h"

using namespace std;

int Vector() {
    VectorArray<int>* vectorArray = nullptr;
    VectorList<int>* vectorList = nullptr;
    int codeType = 0;

     while(1 + 1 == 2) {
        cout << endl;

        cout << "Enter a number for:" << endl;
        cout << "\t1 - To enter data" << endl; 
        cout << "\t2 - Scalar mult" << endl;
        cout << "\t3 - To to for multiplication by scalar" << endl; 
        cout << "\t4 - To adding vector by vector" << endl; 
        cout << "\t5 - To output vector norm" << endl; 
        cout << "\t6 - To output dimension" << endl; 
        cout << "\t7 - To output vector" << endl; 
        cout << "\t0 - To exit the test" << endl; 
        cout << endl << "Enter: ";
        
        int code = 0;
        cin >> code;

        cout << endl;

        switch(code) {
            case 1: 
                InputData(&codeType, &vectorArray, &vectorList);
                break;

            case 2: 
                ScalarMult(&codeType, &vectorArray, &vectorList);
                break;

            case 3: 
                MultByScalar(&codeType, &vectorArray, &vectorList);
                break;

            case 4: 
                AddingVector(&codeType, &vectorArray, &vectorList);
                break;

            case 5: 
                OutputNorm(&codeType, &vectorArray, &vectorList);
                break;

            case 6: 
                OutputDimension(&codeType, &vectorArray, &vectorList);
                break;

            case 7: 
                OutputVector(&codeType, &vectorArray, &vectorList);
                break;

            case 0:
                delete vectorArray;
                delete vectorList;

                cout << endl << "Exiting the test" << endl;
                return 0;

            default: 
                cout << "Input error, please re-enter" << endl << endl;
        } 
     }
}

int InputData(int* codeType, VectorArray<int>** vectorArray, VectorList<int>** vectorList) {
    delete *vectorArray;
    delete *vectorList;

    cout << "Enter a number for:" << endl;
    cout << "\t1 - To enter int VectorArray" << endl;
    cout << "\t2 - To enter int VectorList" << endl;
    cout << "Enter: ";

    int code = 0;
    cin >> code;

    int dimension = 0;
    cout << "Enter the vector dimension" << endl;
    cout << "Enter: ";
    cin >> dimension;

    switch(code) {
        case 1: {
            int* items = new int[dimension];

            cout << "Enter items:" << endl;
            for (int i = 0; i < dimension; i++) {
                cout << '[' << i << "]: "; 
                cin >> items[i];
            }
            

            delete *vectorArray;
            *vectorArray = new VectorArray<int>(dimension, items);

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
                cout << '[' << i << "]: "; 
                cin >> items[i];
            }
            

            delete *vectorList;
            *vectorList = new VectorList<int>(dimension, items);

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

int ScalarMult(int* codeType, VectorArray<int>** vectorArray, VectorList<int>** vectorList) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    try {

        if (*codeType == 1) {
            int* items = new int[(*vectorArray)->GetDimension()];

            cout << "Enter items:" << endl;
            for (int i = 0; i < (*vectorArray)->GetDimension(); i++) {
                cout << '[' << i << "]: "; 
                cin >> items[i];
            }

            VectorArray<int>* vector = new VectorArray<int>((*vectorArray)->GetDimension(), items);

            (*vectorArray)->ScalarMult(vector);     

            delete vector;   
        }

        if (*codeType == 2) {
            int* items = new int[(*vectorArray)->GetDimension()];

            cout << "Enter items:" << endl;
            for (int i = 0; i < (*vectorArray)->GetDimension(); i++) {
                cout << '[' << i << "]: "; 
                cin >> items[i];
            }

            VectorList<int>* vector = new VectorList<int>((*vectorArray)->GetDimension(), items);

            (*vectorList)->ScalarMult(vector);    

            delete vector;
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int MultByScalar(int* codeType, VectorArray<int>** vectorArray, VectorList<int>** vectorList) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    try {

        if (*codeType == 1) {
            cout << "Enter the scalar: ";
            int scalar = 0;
            cin >> scalar;

            (*vectorArray)->MultScalar(scalar); 
        }

        if (*codeType == 2) {
            cout << "Enter the scalar: ";
            int scalar = 0;
            cin >> scalar;

            (*vectorList)->MultScalar(scalar); 
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int AddingVector(int* codeType, VectorArray<int>** vectorArray, VectorList<int>** vectorList) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    try {

        if (*codeType == 1) {
            int* items = new int[(*vectorArray)->GetDimension()];

            cout << "Enter items:" << endl;
            for (int i = 0; i < (*vectorArray)->GetDimension(); i++) {
                cout << '[' << i << "]: "; 
                cin >> items[i];
            }

            VectorArray<int>* vector = new VectorArray<int>((*vectorArray)->GetDimension(), items);

            (*vectorArray)->AddVector(vector); 

            delete[] items;
            delete vector;
        }

        if (*codeType == 2) {
            int* items = new int[(*vectorArray)->GetDimension()];

            cout << "Enter items:" << endl;
            for (int i = 0; i < (*vectorArray)->GetDimension(); i++) {
                cout << '[' << i << "]: "; 
                cin >> items[i];
            }

            VectorList<int>* vector = new VectorList<int>((*vectorArray)->GetDimension(), items);

            (*vectorList)->AddVector(vector);

            delete[] items;
            delete vector;
        }

        return 0;
    } 
    catch (out_of_range err) {
        cout << endl << "An error has occurred: " << err.what() << endl;
        return -1;
    }
}

int OutputNorm(int* codeType, VectorArray<int>** vectorArray, VectorList<int>** vectorList) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        cout << "Norm: " << (*vectorArray)->GetNorm() << endl;
    }

    if (*codeType == 2) {
        cout << "Norm: " << (*vectorList)->GetNorm() << endl;
    }

    return 0;
}

int OutputDimension(int* codeType, VectorArray<int>** vectorArray, VectorList<int>** vectorList) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        cout << "Matrix dimension: " << (*vectorArray)->GetDimension() << endl;
    }

    if (*codeType == 2) {
        cout << "Matrix dimension: " << (*vectorList)->GetDimension() << endl;
    }

    return 0;
}

int OutputVector(int* codeType, VectorArray<int>** vectorArray, VectorList<int>** vectorList) {
    if (!(*codeType)) {
        cout << "First create a matrix" << endl;
        return -1;
    }

    if (*codeType == 1) {
        for (int i = 0; i < (*vectorArray)->GetDimension(); i++) {
            cout << (*vectorArray)->Get(i) << " ";    
            cout << endl;
        }
    }

    if (*codeType == 2) {
        for (int i = 0; i < (*vectorList)->GetDimension(); i++) {
                cout << (*vectorList)->Get(i) << " ";
        }
            
        cout << endl;
    }
    

    return 0;
}