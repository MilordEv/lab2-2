#include <iostream>
#include "DynamicArray.hpp"
#include "ArraySequence.hpp"

using namespace std;

int main() {

    int array[] = {1, 2, 3, 4, 5};

    DynamicArray<int>* example1 = new DynamicArray<int>(array, 5);

    cout << "Size: " << example1->GetSize() << endl;

     for (int i = 0; i < 5; i++) {
        cout << example1->Get(i) << endl;
    }

    DynamicArray<int>* example2 = new DynamicArray<int>(*example1);

    cout << endl;

    for (int i = 0; i < 5; i++) {
        cout << example1->Get(i) << endl;
    }
    
    cout << "Size: " << example2->GetSize() << endl;

    example2->Resize(7);
    
    for (int i = 0; i < 7; i++) {
        example2->Set(i, 7 - i);
    }

    for (int i = 0; i < 7; i++) {
        cout << example2->Get(i) << endl;
    }

    cout << endl;

    for (int i = 0; i < 5; i++) {
        cout << example1->Get(i) << endl;
    }

    cout << endl;

    for (int i = 0; i < 7; i++) {
        cout << example2->Get(i) << endl;
    }


    delete example1;
    delete example2;

    return 0;

}