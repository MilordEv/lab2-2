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

        QueueArray<T>* Map(T func(T));
        QueueArray<T>* Where(bool func(T));
        T Reduce(T func(T, T), T startValue);

        void Concat(QueueArray<T>* queueArray);
        QueueArray<T>* GetSubQueue(int firstIndex, int lastIndex);
        bool FindSubQueue(QueueArray<T>* queueArray);
        QueueArray<T>** Separation(bool func(T));
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

template<typename T>
QueueArray<T>* QueueArray<T>::Map(T func(T value)) {
    QueueArray<T>* newQueue = new QueueArray<T>;
    ArraySequence<T>* arraySequence = (ArraySequence<T>*) this->items->Map(func);
    for (int i = arraySequence->GetLength() - 1; i >= 0; i--) {
        newQueue->Push(arraySequence->Get(i));
    }

    delete arraySequence;
    return newQueue;
}

template<typename T>
QueueArray<T>* QueueArray<T>::Where(bool func(T)) {
    QueueArray<T>* newQueue = new QueueArray<T>;
    ArraySequence<T>* arraySequence = (ArraySequence<T>*) this->items->Where(func);
    for (int i = arraySequence->GetLength() - 1; i >= 0; i--) {
        newQueue->Push(arraySequence->Get(i));
    }

    delete arraySequence;
    return newQueue;
}

template<typename T>
T QueueArray<T>::Reduce(T func(T v1, T v2), T startValue) {
    return this->items->Reduce(func, startValue);
}

template<typename T>
void QueueArray<T>::Concat(QueueArray<T>* queueArray) {
    this->items->Concat(queueArray->items);
    
    return;
}

template<typename T>
QueueArray<T>* QueueArray<T>::GetSubQueue(int firstIndex, int lastIndex) {
    QueueArray<T>* newQueue = new QueueArray<T>;
    ArraySequence<T>* arraySequence = (ArraySequence<T>*) this->items->GetSubsequence(firstIndex, lastIndex);
    for (int i = arraySequence->GetLength() - 1; i >= 0; i--) {
        newQueue->Push(arraySequence->Get(i));
    }

    delete arraySequence;
    return newQueue;
}

template<typename T>
bool QueueArray<T>::FindSubQueue(QueueArray<T>* queueArray) {
    if (queueArray->GetLength() > this->GetLength()) {
        return false;
    }

    bool answer = false;
    int k = 0;
    int j = queueArray->GetLength() - 1;
    while (j < this->GetLength()) {
        answer = true;
        for (int i = k; i <= j; i++) {
            if (this->items->Get(i) != queueArray->items->Get(i - k)) {
                answer = false;
                break;
            }
        }

        if (answer) {
            return true;
        }

        k++;
        j++;
    }

    return false;
}

template<typename T>
QueueArray<T>** QueueArray<T>::Separation(bool func(T)){
    QueueArray<T>** newQueueArray = new QueueArray<T>*[2];
    newQueueArray[0] = new QueueArray<T>();
    newQueueArray[1] = new QueueArray<T>();

    for (int i = this->GetLength() - 1; i >= 0; i--) {
        if (func(this->items->Get(i))) {
            (newQueueArray[0])->Push(this->items->Get(i));
        } else {
            (newQueueArray[1])->Push(this->items->Get(i));
        }
    }

    return newQueueArray;
}

#endif