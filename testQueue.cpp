#include <iostream>
#include "QueueList.hpp"
using namespace std;

int Sqr(int v) {
    return v*v;
}

bool f1(int value) {
    return value % 2;
}

int f2(int v1, int v2) {
    return v1 + v2;
}

int main() {
    int array[4] = {1, 2, 3, 4};
    QueueList<int>* example1 = new QueueList<int>(array, 4);
    example1->Push(2);
    cout << example1->Empty() << endl;
    cout << example1->Pop() << endl;
    example1->Print();
    cout << endl << endl;

    QueueList<int>** example3 = example1->Separation(f1);
    QueueList<int>* example2 = example3[1];
    example2->Print();
    cout << example1->Reduce(f2, 0) << endl;

    example1->Print();
    example2->Push(-10);
    cout << example1->FindSubQueue(example2) << endl;

    delete example1;
    delete example2;
    return 0;
}