#ifndef __QUEUEARRAY__
#define __QUEUEARRAY__

#include <stdexcept>
#include "ArraySequence.hpp"

template<typename T>
class QueueArray{
    private:
        ArraySequence<T>* items;

    public:
        QueueArray(T* items, int count);
        QueueArray();
        QueueArray(const QueueArray<T> &queueArray);

        ~QueueArray();

        int GetLength();
        bool Empty();
        void Push(T item);
        T Pop();
        void Clear();
        void Print();

        QueueArray<T>* Map(void* func(T));
        QueueArray<T>* Where(bool* func(T));
        T Reduce(T* func(T, T));

        QueueArray<T>* Concat(QueueArray<T>* queueArray);
        QueueArray<T>* GetSubQueue(int firstIndex, int lastIndex);
        bool FindSubQueue(QueueArray<T>* queueArray);
        QueueArray<T>* Separation(bool* func(T));

};


template<typename T>
QueueArray<T>::QueueArray(T* items, int count) {
    this->items = new ArraySequence<T>(items, count);
}

template<typename T>
QueueArray<T>::QueueArray() {
    this->items = new ArraySequence<T>;
}

template<typename T>
QueueArray<T>::QueueArray(const QueueArray<T> &queueArray) {
    *(this->items) = *(queueArray.items);
}



template<typename T>
QueueArray<T>::~QueueArray() {
    delete this->items;
}


template<typename T>
int QueueArray<T>::GetLength() {
    return this->items->GetLength();
}

template<typename T>
bool QueueArray<T>::Empty() {
    return this->items->GetLength() == 0;
}

template<typename T>
void QueueArray<T>::Push(T item) {
    this->items->Prepend(item);
    return;
}

template<typename T>
T QueueArray<T>::Pop() {
    T value = this->items->GetLast();
    this->items->Remove(this->items->GetLength() - 1);
    return value;
}

template<typename T>
void QueueArray<T>::Clear() {
    delete this->items;
    this->items = new ArraySequence<T>;
    return;
}

template<typename T>
void QueueArray<T>::Print() {
    for (int i = 0; i < this->items->GetLength(); i++) {
        std::cout << this->items->Get(i) << " ";
    }
    std::cout << std::endl;
    return;
}

#endif