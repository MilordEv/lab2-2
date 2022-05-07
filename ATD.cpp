#include <iostream>
#include "ATD.h"

using namespace std;

int AtdMenu() {

    ArraySequence<int>* arraySequenceInt = nullptr;
    ArraySequence<double>* arraySequenceDouble = nullptr;

    ListSequence<int>* listSequenceInt = nullptr;
    ListSequence<double>* listSequenceDouble = nullptr;

    int codeType = 0;

    while(1 + 1 == 2) {
        cout << "Enter a number for:" << endl;
        cout << "\t1 - To enter data" << endl; 
        cout << "\t2 - Add an element to the end" << endl; 
        cout << "\t3 - Add an element to the beginning" << endl; 
        cout << "\t4 - Insert an element into the sequence" << endl; 
        cout << "\t5 - Get a subsequence" << endl; 
        cout << "\t6 - Сoncatenate sequences" << endl;
        cout << "\t7 - Delete an item" << endl;
        cout << "\t8 - Output the sequence" << endl; 
        cout << "\t9 - Output the length of the sequence" << endl; 
        cout << "\t0 - Exit the test" << endl << endl;
        cout << "Enter: ";

        int code = 0;
        cin >> code;

        switch(code) {
            case 1: 
                InputData(&codeType, &arraySequenceInt, &arraySequenceDouble, &listSequenceInt, &listSequenceDouble);
                break;

            case 2:
                AddEnd(&codeType, &arraySequenceInt, &arraySequenceDouble, &listSequenceInt, &listSequenceDouble);
                break;

            case 3:
                AddBeginning(&codeType, &arraySequenceInt, &arraySequenceDouble, &listSequenceInt, &listSequenceDouble);
                break;

            case 4:
                AddElement(&codeType, &arraySequenceInt, &arraySequenceDouble, &listSequenceInt, &listSequenceDouble);
                break;

            case 5:
                GetSub(&codeType, &arraySequenceInt, &arraySequenceDouble, &listSequenceInt, &listSequenceDouble);
                break;

            case 6:
                ConcateSequence(&codeType, &arraySequenceInt, &arraySequenceDouble, &listSequenceInt, &listSequenceDouble);
                break;

            case 7:
                DeleteItem(&codeType, &arraySequenceInt, &arraySequenceDouble, &listSequenceInt, &listSequenceDouble);
                break;

            case 8:
                OutputSequence(&codeType, &arraySequenceInt, &arraySequenceDouble, &listSequenceInt, &listSequenceDouble);
                break;

            case 9:
               OutputLength(&codeType, &arraySequenceInt, &arraySequenceDouble, &listSequenceInt, &listSequenceDouble);
               break;

            case 0:
                delete arraySequenceInt;
                delete arraySequenceDouble;
                delete listSequenceInt;
                delete listSequenceDouble;

                cout << endl << "Exiting the test" << endl;
                return 0;

            default: 
                cout << "Input error, please re-enter" << endl << endl;
        } 

    }

}

int InputData(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble) {
    cout << "Enter a number for:" << endl;
    cout << "\t1 - To enter int ArraySequence" << endl;
    cout << "\t2 - To enter double ArraySequence" << endl;
    cout << "\t3 - To enter int ListSequence" << endl;
    cout << "\t4 - To enter double ListSequence" << endl << endl;
    cout << "Enter: ";

    int code = 0;
    cin >> code;

    int answer = 0;

    switch(code) {
        case 1:
            cout << "do you want to enter an empty sequence or with data? (not 0 for non-empty sequence, 0 for empty sequence)" << endl << endl;
            cout << "Your answer: ";

            cin >> answer;
            if (answer) {
                cout << "Enter the number of items" << endl;
                cout << "Enter: ";

                int length;
                cin >> length;
                int items[length];

                cout << "Enter items:" << endl;

                for (int i = 0; i < length; i++) {
                    cout << '[' << i << "]: "; 
                    cin >> items[i];
                }

                delete *arraySequenceInt;
                *arraySequenceInt = new ArraySequence<int>(items, length);
            } else {
                delete *arraySequenceInt;
                *arraySequenceInt = new ArraySequence<int>();
            }

            *codeData = 1;
            cout << endl << endl;
            return 0;
            break;

        case 2:
            cout << "do you want to enter an empty sequence or with data? (not 0 for non-empty sequence, 0 for empty sequence)" << endl << endl;
            cout << "Your answer: ";

            cin >> answer;
            if (answer) {
                cout << "Enter the number of items" << endl;
                cout << "Enter: ";

                int length;
                cin >> length;
                double items[length];

                cout << "Enter items:" << endl;

                for (int i = 0; i < length; i++) {
                    cout << '[' << i << "]: "; 
                    cin >> items[i];
                }

                delete *arraySequenceDouble;
                *arraySequenceDouble = new ArraySequence<double>(items, length);
            } else {
                delete *arraySequenceDouble;
                *arraySequenceDouble = new ArraySequence<double>();
            }

            *codeData = 2;
            cout << endl << endl;
            return 0;
            break;

        case 3:
            cout << "do you want to enter an empty sequence or with data? (not 0 for non-empty sequence, 0 for empty sequence)" << endl << endl;
            cout << "Your answer: ";

            cin >> answer;
            if (answer) {
                cout << "Enter the number of items" << endl;
                cout << "Enter: ";

                int length;
                cin >> length;
                int items[length];

                cout << "Enter items:" << endl;

                for (int i = 0; i < length; i++) {
                    cout << '[' << i << "]: "; 
                    cin >> items[i];
                }

                delete *listSequenceInt;
                *listSequenceInt = new ListSequence<int>(items, length);
            } else {
                delete *listSequenceInt;
                *listSequenceInt = new ListSequence<int>();
            }

            *codeData = 3;
            cout << endl << endl;
            return 0;
            break;

        case 4:
            cout << "do you want to enter an empty sequence or with data? (not 0 for non-empty sequence, 0 for empty sequence)" << endl << endl;
            cout << "Your answer: ";

            cin >> answer;
            if (answer) {
                cout << "Enter the number of items" << endl;
                cout << "Enter: ";

                int length;
                cin >> length;
                double items[length];

                cout << "Enter items:" << endl;

                for (int i = 0; i < length; i++) {
                    cout << '[' << i << "]: "; 
                    cin >> items[i];
                }

                delete *listSequenceDouble;
                *listSequenceDouble = new ListSequence<double>(items, length);
            } else {
                delete *listSequenceDouble;
                *listSequenceDouble = new ListSequence<double>();
            }

            *codeData = 4;
            cout << endl << endl;
            return 0;
            break;

        default:
            cout << "You make mistake" << endl << endl << endl;
            return -1;
    }
}

int AddEnd(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble) {
    if (!(*codeData)) {
        cout << "First enter the data" << endl << endl << endl;
        return -1;
    }

    if (*codeData == 1) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*arraySequenceInt)->Append(value);
    }

    if (*codeData == 2) {
        cout << "Enter the value: ";
        double value;
        cin >> value;

        (*arraySequenceDouble)->Append(value);
    }

    if (*codeData == 3) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*listSequenceInt)->Append(value);
    }

    if (*codeData == 4) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*listSequenceDouble)->Append(value);
    }

    return 0;
}

int AddBeginning(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble) {
    if (!(*codeData)) {
        cout << "First enter the data" << endl << endl << endl;
        return -1;
    }

    if (*codeData == 1) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*arraySequenceInt)->Prepend(value);
    }

    if (*codeData == 2) {
        cout << "Enter the value: ";
        double value;
        cin >> value;

        (*arraySequenceDouble)->Prepend(value);
    }

    if (*codeData == 3) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*listSequenceInt)->Prepend(value);
    }

    if (*codeData == 4) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*listSequenceDouble)->Prepend(value);
    }

    return 0;
}

int AddElement(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble) {
    if (!(*codeData)) {
        cout << "First enter the data" << endl << endl << endl;
        return -1;
    }

    cout << "Enter the index: ";
    int index;
    cin >> index;

    if (*codeData == 1) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*arraySequenceInt)->InsertAt(value, index);
    }

    if (*codeData == 2) {
        cout << "Enter the value: ";
        double value;
        cin >> value;

        (*arraySequenceDouble)->InsertAt(value, index);
    }

    if (*codeData == 3) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*listSequenceInt)->InsertAt(value, index);
    }

    if (*codeData == 4) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*listSequenceDouble)->InsertAt(value, index);
    }

    return 0;
}


int GetSub(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble) {
    if (!(*codeData)) {
        cout << "First enter the data" << endl << endl << endl;
        return -1;
    }

    cout << "Enter the startiIndex: ";
    int startIndex;
    cin >> startIndex;

    cout << "Enter the endiIndex: ";
    int endiIndex;
    cin >> endiIndex;

    if (*codeData == 1) {
        ArraySequence<int>* subArraySequence = (ArraySequence<int>*) (*arraySequenceInt)->GetSubsequence(startIndex, endiIndex);
        delete *arraySequenceInt;
        *arraySequenceInt = subArraySequence;
    }

    if (*codeData == 2) {      
        ArraySequence<double>* subArraySequence = (ArraySequence<double>*) (*arraySequenceDouble)->GetSubsequence(startIndex, endiIndex);
        delete *arraySequenceDouble;
        *arraySequenceDouble = subArraySequence;
    }

    if (*codeData == 3) {
        ListSequence<int>* subListSequence = (ListSequence<int>*) (*listSequenceInt)->GetSubsequence(startIndex, endiIndex);
        delete *listSequenceInt;
        *listSequenceInt = subListSequence;
    }

    if (*codeData == 4) {
        ListSequence<double>* subListSequence = (ListSequence<double>*) (*listSequenceDouble)->GetSubsequence(startIndex, endiIndex);
        delete *listSequenceDouble;
        *listSequenceDouble = subListSequence;
    }

    return 0;
}

int ConcateSequence(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble) {
    if (!(*codeData)) {
        cout << "First enter the data" << endl << endl << endl;
        return -1;
    }

    cout << "Enter the number of items: ";
    int length;
    cin >> length;

    if (*codeData == 1) {
        if (length) {
        
            int items[length];
            cout << "Enter items:" << endl;

            for (int i = 0; i < length; i++) {
                cout << '[' << i << "]: "; 
                cin >> items[i];
            }

            ArraySequence<int>* newSequence = new ArraySequence<int>(items, length);
            (*arraySequenceInt)->Concat(newSequence);
            delete newSequence;
        }      
    }

    if (*codeData == 2) {
        if (length) {

            double items[length];
            cout << "Enter items:" << endl;

            for (int i = 0; i < length; i++) {
                cout << '[' << i << "]: "; 
                cin >> items[i];
            }

            ArraySequence<double>* newSequence = new ArraySequence<double>(items, length);
            (*arraySequenceDouble)->Concat(newSequence);
            delete newSequence;
        }
    }

    if (*codeData == 3) {
        if (length) {

            int items[length];
            cout << "Enter items:" << endl;

            for (int i = 0; i < length; i++) {
                cout << '[' << i << "]: "; 
                cin >> items[i];
            }

            ListSequence<int>* newSequence = new ListSequence<int>(items, length);
            (*listSequenceInt)->Concat(newSequence);
            delete newSequence;
        }
    }

    if (*codeData == 4) {
        if (length) {

            double items[length];
            cout << "Enter items:" << endl;

            for (int i = 0; i < length; i++) {
                cout << '[' << i << "]: "; 
                cin >> items[i];
            }

            ListSequence<double>* newSequence = new ListSequence<double>(items, length);
            (*listSequenceDouble)->Concat(newSequence);
            delete newSequence;
        }
    }

    return 0;
}

int DeleteItem(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble) {
    if (!(*codeData)) {
        cout << "First enter the data" << endl << endl << endl;
        return -1;
    }

    cout << "Enter the index: ";
    int index;
    cin >> index;

    if (*codeData == 1) {
        (*arraySequenceInt)->Remove(index);
    }

    if (*codeData == 2) {      
        (*arraySequenceDouble)->Remove(index);
    }

    if (*codeData == 3) {
        (*listSequenceInt)->Remove(index);
    }

    if (*codeData == 4) {
        (*listSequenceDouble)->Remove(index);
    }

    return 0;
}

int OutputSequence(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble) {
    if (!(*codeData)) {
        cout << "First enter the data" << endl << endl << endl;
        return -1;
    }

    if (*codeData == 1) {
        for (int i = 0; i < (*arraySequenceInt)->GetLength(); i++) {
            cout << (*arraySequenceInt)->Get(i) << " ";
        }
        cout << endl << endl;
    }

    if (*codeData == 2) { 
        for (int i = 0; i < (*arraySequenceDouble)->GetLength(); i++) {
            cout << (*arraySequenceDouble)->Get(i) << " ";
        }
        cout << endl << endl;
    }

    if (*codeData == 3) {
        for (int i = 0; i < (*listSequenceInt)->GetLength(); i++) {
            cout << (*listSequenceInt)->Get(i) << " ";
        }
        cout << endl << endl;
    }

    if (*codeData == 4) {
        for (int i = 0; i < (*listSequenceDouble)->GetLength(); i++) {
            cout << (*listSequenceDouble)->Get(i) << " ";
        }
        cout << endl << endl;
    }

    return 0;
}

int OutputLength(int* codeData, ArraySequence<int>** arraySequenceInt, ArraySequence<double>** arraySequenceDouble, ListSequence<int>** listSequenceInt, ListSequence<double>** listSequenceDouble) {
    if (!(*codeData)) {
        cout << "First enter the data" << endl << endl << endl;
        return -1;
    }

    if (*codeData == 1) {
        cout << (*arraySequenceInt)->GetLength() << endl << endl;
    }

    if (*codeData == 2) { 
        cout << (*arraySequenceDouble)->GetLength() << endl << endl;
    }

    if (*codeData == 3) {
        cout << (*listSequenceInt)->GetLength() << endl << endl;
    }

    if (*codeData == 4) {
        cout << (*listSequenceDouble)->GetLength() << endl << endl;
    }

    return 0;
}