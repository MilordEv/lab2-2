#ifndef __QUEUELIST__
#define __QUEUELIST__

#include <stdexcept>
#include "ListSequence.hpp"

template<typename T>
class QueueList{
    private:
        ListSequence<T>* items;

    public:
        QueueList(T* items, int count);
        QueueList();
        QueueList(const QueueList<T> &queueList);

        ~QueueList();

        int GetLength();
        bool Empty();
        void Push(T item);
        T Pop();
        void Clear();
        void Print();

        QueueList<T>* Map(T func(T));
        QueueList<T>* Where(bool func(T));
        T Reduce(T func(T, T), T startValue);

        void Concat(QueueList<T>* queueList);
        QueueList<T>* GetSubQueue(int firstIndex, int lastIndex);
        bool FindSubQueue(QueueList<T>* queueList);
        QueueList<T>** Separation(bool func(T));
};


template<typename T>
QueueList<T>::QueueList(T* items, int count) {
    this->items = new ListSequence<T>(items, count);
}

template<typename T>
QueueList<T>::QueueList() {
    this->items = new ListSequence<T>;
}

template<typename T>
QueueList<T>::QueueList(const QueueList<T> &queueList) {
    *(this->items) = *(queueList.items);
}



template<typename T>
QueueList<T>::~QueueList() {
    delete this->items;
}


template<typename T>
int QueueList<T>::GetLength() {
    return this->items->GetLength();
}

template<typename T>
bool QueueList<T>::Empty() {
    return this->items->GetLength() == 0;
}

template<typename T>
void QueueList<T>::Push(T item) {
    this->items->Prepend(item);
    return;
}

template<typename T>
T QueueList<T>::Pop() {
    T value = this->items->GetLast();
    this->items->Remove(this->items->GetLength() - 1);
    return value;
}

template<typename T>
void QueueList<T>::Clear() {
    delete this->items;
    this->items = new ListSequence<T>;
    return;
}

template<typename T>
void QueueList<T>::Print() {
    for (int i = 0; i < this->items->GetLength(); i++) {
        std::cout << this->items->Get(i) << " ";
    }
    std::cout << std::endl;
    return;
}

template<typename T>
QueueList<T>* QueueList<T>::Map(T func(T value)) {
    QueueList<T>* newQueue = new QueueList<T>;
    ListSequence<T>* listSequence = (ListSequence<T>*) this->items->Map(func);
    for (int i = listSequence->GetLength() - 1; i >= 0; i--) {
        newQueue->Push(listSequence->Get(i));
    }

    delete listSequence;
    return newQueue;
}

template<typename T>
QueueList<T>* QueueList<T>::Where(bool func(T)) {
    QueueList<T>* newQueue = new QueueList<T>;
    ListSequence<T>* listSequence = (ListSequence<T>*) this->items->Where(func);
    for (int i = listSequence->GetLength() - 1; i >= 0; i--) {
        newQueue->Push(listSequence->Get(i));
    }

    delete listSequence;
    return newQueue;
}

template<typename T>
T QueueList<T>::Reduce(T func(T v1, T v2), T startValue) {
    return this->items->Reduce(func, startValue);
}

template<typename T>
void QueueList<T>::Concat(QueueList<T>* queueList) {
    this->items->Concat(queueList->items);
    
    return;
}

template<typename T>
QueueList<T>* QueueList<T>::GetSubQueue(int firstIndex, int lastIndex) {
    QueueList<T>* newQueue = new QueueList<T>;
    ListSequence<T>* listSequence = (ListSequence<T>*) this->items->GetSubsequence(firstIndex, lastIndex);
    for (int i = listSequence->GetLength() - 1; i >= 0; i--) {
        newQueue->Push(listSequence->Get(i));
    }

    delete listSequence;
    return newQueue;
}

template<typename T>
bool QueueList<T>::FindSubQueue(QueueList<T>* queueList) {
    if (queueList->GetLength() > this->GetLength()) {
        return false;
    }

    bool answer = false;
    int k = 0;
    int j = queueList->GetLength() - 1;
    while (j < this->GetLength()) {
        answer = true;
        for (int i = k; i <= j; i++) {
            if (this->items->Get(i) != queueList->items->Get(i - k)) {
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
QueueList<T>** QueueList<T>::Separation(bool func(T)){
    QueueList<T>** newQueueList = new QueueList<T>*[2];
    newQueueList[0] = new QueueList<T>();
    newQueueList[1] = new QueueList<T>();

    for (int i = this->GetLength() - 1; i >= 0; i--) {
        if (func(this->items->Get(i))) {
            (newQueueList[0])->Push(this->items->Get(i));
        } else {
            (newQueueList[1])->Push(this->items->Get(i));
        }
    }

    return newQueueList;
}

#endif