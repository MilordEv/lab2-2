#include <iostream>
#include "DynamicArray.hpp"
#include "ArraySequence.hpp"

using namespace std;

int main() {

    int array[] = {1, 2, 3, 4, 5};

    ArraySequence<int>* example1 = new ArraySequence<int>(array, 5);

    cout << example1->GetLength() << endl;

    for (int i = 0; i < 5; i++) {
        cout << example1->Get(i) << " ";
    }

    cout << endl << example1->GetFirst() << " " <<  example1->GetLast() << endl;

    example1->Append(6);

    for (int i = 0; i < example1->GetLength(); i++) {
        cout << example1->Get(i) << " ";
    }
    cout << endl;

    example1->Prepend(0);

    for (int i = 0; i < 7; i++) {
        cout << example1->Get(i) << " ";
    }
    cout << endl;

    example1->InsertAt(10, 3);

    for (int i = 0; i < 8; i++) {
        cout << example1->Get(i) << " ";
    }
    cout << endl;

    example1->Remove(3);
    example1->Remove(4);

    for (int i = 0; i < example1->GetLength(); i++) {
        cout << example1->Get(i) << " ";
    }
    cout << endl;

    ArraySequence<int>* example2 = example1->GetSubsequence(4, example1->GetLength() - 1);

    for (int i = 0; i < example2->GetLength(); i++) {
        cout << example2->Get(i) << " ";
    }
    cout << endl;

    example1->Concat(example2);

    for (int i = 0; i < example1->GetLength(); i++) {
        cout << example1->Get(i) << " ";
    }
    cout << endl;

    delete example1;
    delete example2;

    return 0;

}