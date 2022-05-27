#include <iostream>
#include "QueueArray.hpp"
using namespace std;

int main() {
    QueueArray<int>* example1 = new QueueArray<int>;
    example1->Push(2);
    cout << example1->Pop() << endl;

    return 0;
}