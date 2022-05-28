#ifndef __DEQUEARRAY__
#define __DEQUEARRAY__

#include <stdexcept>
#include "ArraySequence.hpp"

template<typename T>
class DequeArray{
    private:
        ArraySequence<T>* items;

    public:
        DequeArray(T* items, int count);
        DequeArray();
        DequeArray(const DequeArray<T> &dequeArray);

        ~DequeArray();

        int GetLength();
        bool Empty();
        void PushBack(T item);
        T PopBack();
        void PushFront(T item);
        T PopFront();
        void Clear();
        void Print();

        DequeArray<T>* Map(T func(T));
        DequeArray<T>* Where(bool func(T));
        T Reduce(T func(T, T), T startValue);

        void Concat(DequeArray<T>* dequeArray);
        DequeArray<T>* GetSubQueue(int firstIndex, int lastIndex);
        bool FindSubQueue(DequeArray<T>* dequeArray);
};


template<typename T>
DequeArray<T>::DequeArray(T* items, int count) {
    this->items = new ArraySequence<T>(items, count);
}

template<typename T>
DequeArray<T>::DequeArray() {
    this->items = new ArraySequence<T>;
}

template<typename T>
DequeArray<T>::DequeArray(const DequeArray<T> &dequeArray) {
    *(this->items) = *(dequeArray.items);
}



template<typename T>
DequeArray<T>::~DequeArray() {
    delete this->items;
}


template<typename T>
int DequeArray<T>::GetLength() {
    return this->items->GetLength();
}

template<typename T>
bool DequeArray<T>::Empty() {
    return this->items->GetLength() == 0;
}

template<typename T>
void DequeArray<T>::PushBack(T item) {
    this->items->Append(item);
    return;
}

template<typename T>
T DequeArray<T>::PopBack() {
    T value = this->items->GetLast();
    this->items->Remove(this->items->GetLength() - 1);
    return value;
}

template<typename T>
void DequeArray<T>::PushFront(T item) {
    this->items->Prepend(item);
    return;
}

template<typename T>
T DequeArray<T>::PopFront() {
    T value = this->items->GetFirst();
    this->items->Remove(0);
    return value;
}

template<typename T>
void DequeArray<T>::Clear() {
    delete this->items;
    this->items = new ArraySequence<T>;
    return;
}

template<typename T>
void DequeArray<T>::Print() {
    for (int i = 0; i < this->items->GetLength(); i++) {
        std::cout << this->items->Get(i) << " ";
    }
    std::cout << std::endl;
    return;
}

template<typename T>
DequeArray<T>* DequeArray<T>::Map(T func(T value)) {
    DequeArray<T>* newQueue = new DequeArray<T>;
    ArraySequence<T>* arraySequence = (ArraySequence<T>*) this->items->Map(func);
    for (int i = 0; i < arraySequence->GetLength(); i++) {
        newQueue->PushBack(arraySequence->Get(i));
    }

    delete arraySequence;
    return newQueue;
}

template<typename T>
DequeArray<T>* DequeArray<T>::Where(bool func(T)) {
    DequeArray<T>* newQueue = new DequeArray<T>;
    ArraySequence<T>* arraySequence = (ArraySequence<T>*) this->items->Where(func);
    for (int i = 0; i < arraySequence->GetLength(); i++) {
        newQueue->PushBack(arraySequence->Get(i));
    }

    delete arraySequence;
    return newQueue;
}

template<typename T>
T DequeArray<T>::Reduce(T func(T v1, T v2), T startValue) {
    return this->items->Reduce(func, startValue);
}

template<typename T>
void DequeArray<T>::Concat(DequeArray<T>* dequeArray) {
    this->items->Concat(dequeArray->items);
    
    return;
}

template<typename T>
DequeArray<T>* DequeArray<T>::GetSubQueue(int firstIndex, int lastIndex) {
    DequeArray<T>* newQueue = new DequeArray<T>;
    ArraySequence<T>* arraySequence = (ArraySequence<T>*) this->items->GetSubsequence(firstIndex, lastIndex);
    for (int i = 0; i < arraySequence->GetLength(); i++) {
        newQueue->PushBack(arraySequence->Get(i));
    }

    delete arraySequence;
    return newQueue;
}

template<typename T>
bool DequeArray<T>::FindSubQueue(DequeArray<T>* dequeArray) {
    if (dequeArray->GetLength() > this->GetLength()) {
        return false;
    }

    bool answer = false;
    int k = 0;
    int j = dequeArray->GetLength() - 1;
    while (j < this->GetLength()) {
        answer = true;
        for (int i = k; i <= j; i++) {
            if (this->items->Get(i) != dequeArray->items->Get(i - k)) {
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