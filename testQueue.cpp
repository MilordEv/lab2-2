#include <iostream>
#include "testQueue.h"

using namespace std;

int AtdMenu() {

    QueueArray<int>* arrayQueueInt = nullptr;
    QueueArray<double>* arrayQueueDouble = nullptr;

    QueueList<int>* listQueueInt = nullptr;
    QueueList<double>* listQueueDouble = nullptr;

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
                InputData(&codeType, &arrayQueueInt, &arrayQueueDouble, &listQueueInt, &listQueueDouble);
                break;

            case 2:
                Add(&codeType, &arrayQueueInt, &arrayQueueDouble, &listQueueInt, &listQueueDouble);
                break;

            case 3:
                PopQueue(&codeType, &arrayQueueInt, &arrayQueueDouble, &listQueueInt, &listQueueDouble);
                break;

            case 4:
                Map(&codeType, &arrayQueueInt, &arrayQueueDouble, &listQueueInt, &listQueueDouble);
                break;

            case 6:
                ConcateSequence(&codeType, &arrayQueueInt, &arrayQueueDouble, &listQueueInt, &listQueueDouble);
                break;

            case 7:
                DeleteItem(&codeType, &arrayQueueInt, &arrayQueueDouble, &listQueueInt, &listQueueDouble);
                break;

            case 8:
                OutputSequence(&codeType, &arrayQueueInt, &arrayQueueDouble, &listQueueInt, &listQueueDouble);
                break;

            case 9:
               OutputLength(&codeType, &arrayQueueInt, &arrayQueueDouble, &listQueueInt, &listQueueDouble);
               break;

            case 0:
                delete arrayQueueInt;
                delete arrayQueueDouble;
                delete listQueueInt;
                delete listQueueDouble;

                cout << endl << "Exiting the test" << endl;
                return 0;

            default: 
                cout << "Input error, please re-enter" << endl << endl;
        } 

    }

}

int InputData(int* codeData, QueueArray<int>** arrayQueueInt, QueueArray<double>** arrayQueueDouble, QueueList<int>** listQueueInt, QueueList<double>** listQueueDouble) {
    cout << "Enter a number for:" << endl;
    cout << "\t1 - To enter int QueueArray" << endl;
    cout << "\t2 - To enter double QueueArray" << endl;
    cout << "\t3 - To enter int QueueList" << endl;
    cout << "\t4 - To enter double QueueList" << endl << endl;
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

                delete *arrayQueueInt;
                *arrayQueueInt = new QueueArray<int>(items, length);
            } else {
                delete *arrayQueueInt;
                *arrayQueueInt = new QueueArray<int>();
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

                delete *arrayQueueDouble;
                *arrayQueueDouble = new QueueArray<double>(items, length);
            } else {
                delete *arrayQueueDouble;
                *arrayQueueDouble = new QueueArray<double>();
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

                delete *listQueueInt;
                *listQueueInt = new QueueList<int>(items, length);
            } else {
                delete *listQueueInt;
                *listQueueInt = new QueueList<int>();
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

                delete *listQueueDouble;
                *listQueueDouble = new QueueList<double>(items, length);
            } else {
                delete *listQueueDouble;
                *listQueueDouble = new QueueList<double>();
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

int Add(int* codeData, QueueArray<int>** arrayQueueInt, QueueArray<double>** arrayQueueDouble, QueueList<int>** listQueueInt, QueueList<double>** listQueueDouble) {
    if (!(*codeData)) {
        cout << "First enter the data" << endl << endl << endl;
        return -1;
    }

    if (*codeData == 1) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*arrayQueueInt)->Push(value);
    }

    if (*codeData == 2) {
        cout << "Enter the value: ";
        double value;
        cin >> value;

        (*arrayQueueDouble)->Push(value);
    }

    if (*codeData == 3) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*listQueueInt)->Push(value);
    }

    if (*codeData == 4) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*listQueueDouble)->Push(value);
    }

    return 0;
}

int PopQueue(int* codeData, QueueArray<int>** arrayQueueInt, QueueArray<double>** arrayQueueDouble, QueueList<int>** listQueueInt, QueueList<double>** listQueueDouble) {
    if (!(*codeData)) {
        cout << "First enter the data" << endl << endl << endl;
        return -1;
    }

    if (*codeData == 1) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*arrayQueueInt)->Pop();
    }

    if (*codeData == 2) {
        cout << "Enter the value: ";
        double value;
        cin >> value;

        (*arrayQueueDouble)->Pop();
    }

    if (*codeData == 3) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*listQueueInt)->Pop();
    }

    if (*codeData == 4) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*listQueueDouble)->Pop();
    }

    return 0;
}

int Map(int* codeData, QueueArray<int>** arrayQueueInt, QueueArray<double>** arrayQueueDouble, QueueList<int>** listQueueInt, QueueList<double>** listQueueDouble) {
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

        (*arrayQueueInt)->InsertAt(value, index);
    }

    if (*codeData == 2) {
        cout << "Enter the value: ";
        double value;
        cin >> value;

        (*arrayQueueDouble)->InsertAt(value, index);
    }

    if (*codeData == 3) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*listQueueInt)->InsertAt(value, index);
    }

    if (*codeData == 4) {
        cout << "Enter the value: ";
        int value;
        cin >> value;

        (*listQueueDouble)->InsertAt(value, index);
    }

    return 0;
}


int GetSub(int* codeData, QueueArray<int>** arrayQueueInt, QueueArray<double>** arrayQueueDouble, QueueList<int>** listQueueInt, QueueList<double>** listQueueDouble) {
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
        QueueArray<int>* subArraySequence = (QueueArray<int>*) (*arrayQueueInt)->GetSubsequence(startIndex, endiIndex);
        delete *arrayQueueInt;
        *arrayQueueInt = subArraySequence;
    }

    if (*codeData == 2) {      
        QueueArray<double>* subArraySequence = (QueueArray<double>*) (*arrayQueueDouble)->GetSubsequence(startIndex, endiIndex);
        delete *arrayQueueDouble;
        *arrayQueueDouble = subArraySequence;
    }

    if (*codeData == 3) {
        QueueList<int>* subListSequence = (QueueList<int>*) (*listQueueInt)->GetSubsequence(startIndex, endiIndex);
        delete *listQueueInt;
        *listQueueInt = subListSequence;
    }

    if (*codeData == 4) {
        QueueList<double>* subListSequence = (QueueList<double>*) (*listQueueDouble)->GetSubsequence(startIndex, endiIndex);
        delete *listQueueDouble;
        *listQueueDouble = subListSequence;
    }

    return 0;
}

int ConcateSequence(int* codeData, QueueArray<int>** arrayQueueInt, QueueArray<double>** arrayQueueDouble, QueueList<int>** listQueueInt, QueueList<double>** listQueueDouble) {
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

            QueueArray<int>* newSequence = new QueueArray<int>(items, length);
            (*arrayQueueInt)->Concat(newSequence);
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

            QueueArray<double>* newSequence = new QueueArray<double>(items, length);
            (*arrayQueueDouble)->Concat(newSequence);
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

            QueueList<int>* newSequence = new QueueList<int>(items, length);
            (*listQueueInt)->Concat(newSequence);
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

            QueueList<double>* newSequence = new QueueList<double>(items, length);
            (*listQueueDouble)->Concat(newSequence);
            delete newSequence;
        }
    }

    return 0;
}

int DeleteItem(int* codeData, QueueArray<int>** arrayQueueInt, QueueArray<double>** arrayQueueDouble, QueueList<int>** listQueueInt, QueueList<double>** listQueueDouble) {
    if (!(*codeData)) {
        cout << "First enter the data" << endl << endl << endl;
        return -1;
    }

    cout << "Enter the index: ";
    int index;
    cin >> index;

    if (*codeData == 1) {
        (*arrayQueueInt)->Remove(index);
    }

    if (*codeData == 2) {      
        (*arrayQueueDouble)->Remove(index);
    }

    if (*codeData == 3) {
        (*listQueueInt)->Remove(index);
    }

    if (*codeData == 4) {
        (*listQueueDouble)->Remove(index);
    }

    return 0;
}

int OutputSequence(int* codeData, QueueArray<int>** arrayQueueInt, QueueArray<double>** arrayQueueDouble, QueueList<int>** listQueueInt, QueueList<double>** listQueueDouble) {
    if (!(*codeData)) {
        cout << "First enter the data" << endl << endl << endl;
        return -1;
    }

    if (*codeData == 1) {
        for (int i = 0; i < (*arrayQueueInt)->GetLength(); i++) {
            cout << (*arrayQueueInt)->Get(i) << " ";
        }
        cout << endl << endl;
    }

    if (*codeData == 2) { 
        for (int i = 0; i < (*arrayQueueDouble)->GetLength(); i++) {
            cout << (*arrayQueueDouble)->Get(i) << " ";
        }
        cout << endl << endl;
    }

    if (*codeData == 3) {
        for (int i = 0; i < (*listQueueInt)->GetLength(); i++) {
            cout << (*listQueueInt)->Get(i) << " ";
        }
        cout << endl << endl;
    }

    if (*codeData == 4) {
        for (int i = 0; i < (*listQueueDouble)->GetLength(); i++) {
            cout << (*listQueueDouble)->Get(i) << " ";
        }
        cout << endl << endl;
    }

    return 0;
}

int OutputLength(int* codeData, QueueArray<int>** arrayQueueInt, QueueArray<double>** arrayQueueDouble, QueueList<int>** listQueueInt, QueueList<double>** listQueueDouble) {
    if (!(*codeData)) {
        cout << "First enter the data" << endl << endl << endl;
        return -1;
    }

    if (*codeData == 1) {
        cout << (*arrayQueueInt)->GetLength() << endl << endl;
    }

    if (*codeData == 2) { 
        cout << (*arrayQueueDouble)->GetLength() << endl << endl;
    }

    if (*codeData == 3) {
        cout << (*listQueueInt)->GetLength() << endl << endl;
    }

    if (*codeData == 4) {
        cout << (*listQueueDouble)->GetLength() << endl << endl;
    }

    return 0;
}