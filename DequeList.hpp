#ifndef __DEQUELIST__
#define __DEQUELIST__

#include <stdexcept>
#include "ListSequence.hpp"

template<typename T>
class DequeList{
    private:
        ListSequence<T>* items;

    public:
        DequeList(T* items, int count);
        DequeList();
        DequeList(const DequeList<T> &dequeList);

        ~DequeList();

        int GetLength();
        bool Empty();
        void PushBack(T item);
        T PopBack();
        void PushFront(T item);
        T PopFront();
        void Clear();
        void Print();

        DequeList<T>* Map(T func(T));
        DequeList<T>* Where(bool func(T));
        T Reduce(T func(T, T), T startValue);

        void Concat(DequeList<T>* dequeList);
        DequeList<T>* GetSubQueue(int firstIndex, int lastIndex);
        bool FindSubQueue(DequeList<T>* dequeList);
};


template<typename T>
DequeList<T>::DequeList(T* items, int count) {
    this->items = new ListSequence<T>(items, count);
}

template<typename T>
DequeList<T>::DequeList() {
    this->items = new ListSequence<T>;
}

template<typename T>
DequeList<T>::DequeList(const DequeList<T> &dequeList) {
    *(this->items) = *(dequeList.items);
}



template<typename T>
DequeList<T>::~DequeList() {
    delete this->items;
}


template<typename T>
int DequeList<T>::GetLength() {
    return this->items->GetLength();
}

template<typename T>
bool DequeList<T>::Empty() {
    return this->items->GetLength() == 0;
}

template<typename T>
void DequeList<T>::PushBack(T item) {
    this->items->Append(item);
    return;
}

template<typename T>
T DequeList<T>::PopBack() {
    T value = this->items->GetLast();
    this->items->Remove(this->items->GetLength() - 1);
    return value;
}

template<typename T>
void DequeList<T>::PushFront(T item) {
    this->items->Prepend(item);
    return;
}

template<typename T>
T DequeList<T>::PopFront() {
    T value = this->items->GetFirst();
    this->items->Remove(0);
    return value;
}

template<typename T>
void DequeList<T>::Clear() {
    delete this->items;
    this->items = new ListSequence<T>;
    return;
}

template<typename T>
void DequeList<T>::Print() {
    for (int i = 0; i < this->items->GetLength(); i++) {
        std::cout << this->items->Get(i) << " ";
    }
    std::cout << std::endl;
    return;
}

template<typename T>
DequeList<T>* DequeList<T>::Map(T func(T value)) {
    DequeList<T>* newQueue = new DequeList<T>;
    ListSequence<T>* listSequence = (ListSequence<T>*) this->items->Map(func);
    for (int i = 0; i < listSequence->GetLength(); i++) {
        newQueue->PushBack(listSequence->Get(i));
    }

    delete listSequence;
    return newQueue;
}

template<typename T>
DequeList<T>* DequeList<T>::Where(bool func(T)) {
    DequeList<T>* newQueue = new DequeList<T>;
    ListSequence<T>* listSequence = (ListSequence<T>*) this->items->Where(func);
    for (int i = 0; i < listSequence->GetLength(); i++) {
        newQueue->PushBack(listSequence->Get(i));
    }

    delete listSequence;
    return newQueue;
}

template<typename T>
T DequeList<T>::Reduce(T func(T v1, T v2), T startValue) {
    return this->items->Reduce(func, startValue);
}

template<typename T>
void DequeList<T>::Concat(DequeList<T>* dequeList) {
    this->items->Concat(dequeList->items);
    
    return;
}

template<typename T>
DequeList<T>* DequeList<T>::GetSubQueue(int firstIndex, int lastIndex) {
    DequeList<T>* newQueue = new DequeList<T>;
    ListSequence<T>* listSequence = (ListSequence<T>*) this->items->GetSubsequence(firstIndex, lastIndex);
    for (int i = 0; i < listSequence->GetLength(); i++) {
        newQueue->PushBack(listSequence->Get(i));
    }

    delete listSequence;
    return newQueue;
}

template<typename T>
bool DequeList<T>::FindSubQueue(DequeList<T>* dequeList) {
    if (dequeList->GetLength() > this->GetLength()) {
        return false;
    }

    bool answer = false;
    int k = 0;
    int j = dequeList->GetLength() - 1;
    while (j < this->GetLength()) {
        answer = true;
        for (int i = k; i <= j; i++) {
            if (this->items->Get(i) != dequeList->items->Get(i - k)) {
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

#endif