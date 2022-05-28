#ifndef __STACKARRAY__
#define __STACKARRAY__

#include <stdexcept>
#include "ArraySequence.hpp"

template<typename T>
class StackArray{
    private:
        ArraySequence<T>* items;

    public:
        StackArray(T* items, int count);
        StackArray();
        StackArray(const StackArray<T> &stackArray);

        ~StackArray();

        int GetLength();
        bool Empty();
        void Push(T item);
        T Pop();
        void Clear();
        void Print();

        StackArray<T>* Map(T func(T));
        StackArray<T>* Where(bool func(T));
        T Reduce(T func(T, T), T startValue);

        void Concat(StackArray<T>* stackArray);
        StackArray<T>* GetSubQueue(int firstIndex, int lastIndex);
        bool FindSubQueue(StackArray<T>* stackArray);
};


template<typename T>
StackArray<T>::StackArray(T* items, int count) {
    this->items = new ArraySequence<T>(items, count);
}

template<typename T>
StackArray<T>::StackArray() {
    this->items = new ArraySequence<T>;
}

template<typename T>
StackArray<T>::StackArray(const StackArray<T> &stackArray) {
    *(this->items) = *(stackArray.items);
}



template<typename T>
StackArray<T>::~StackArray() {
    delete this->items;
}


template<typename T>
int StackArray<T>::GetLength() {
    return this->items->GetLength();
}

template<typename T>
bool StackArray<T>::Empty() {
    return this->items->GetLength() == 0;
}

template<typename T>
void StackArray<T>::Push(T item) {
    this->items->Append(item);
    return;
}

template<typename T>
T StackArray<T>::Pop() {
    T value = this->items->GetLast();
    this->items->Remove(this->items->GetLength() - 1);
    return value;
}

template<typename T>
void StackArray<T>::Clear() {
    delete this->items;
    this->items = new ArraySequence<T>;
    return;
}

template<typename T>
void StackArray<T>::Print() {
    for (int i = 0; i < this->items->GetLength(); i++) {
        std::cout << this->items->Get(i) << " ";
    }
    std::cout << std::endl;
    return;
}

template<typename T>
StackArray<T>* StackArray<T>::Map(T func(T value)) {
    StackArray<T>* newQueue = new StackArray<T>;
    ArraySequence<T>* arraySequence = (ArraySequence<T>*) this->items->Map(func);
    for (int i = 0; i < arraySequence->GetLength(); i++) {
        newQueue->Push(arraySequence->Get(i));
    }

    delete arraySequence;
    return newQueue;
}

template<typename T>
StackArray<T>* StackArray<T>::Where(bool func(T)) {
    StackArray<T>* newQueue = new StackArray<T>;
    ArraySequence<T>* arraySequence = (ArraySequence<T>*) this->items->Where(func);
    for (int i = 0; i < arraySequence->GetLength(); i++) {
        newQueue->Push(arraySequence->Get(i));
    }

    delete arraySequence;
    return newQueue;
}

template<typename T>
T StackArray<T>::Reduce(T func(T v1, T v2), T startValue) {
    return this->items->Reduce(func, startValue);
}

template<typename T>
void StackArray<T>::Concat(StackArray<T>* stackArray) {
    this->items->Concat(stackArray->items);
    
    return;
}

template<typename T>
StackArray<T>* StackArray<T>::GetSubQueue(int firstIndex, int lastIndex) {
    StackArray<T>* newQueue = new StackArray<T>;
    ArraySequence<T>* arraySequence = (ArraySequence<T>*) this->items->GetSubsequence(firstIndex, lastIndex);
    for (int i = 0; i < arraySequence->GetLength(); i++) {
        newQueue->Push(arraySequence->Get(i));
    }

    delete arraySequence;
    return newQueue;
}

template<typename T>
bool StackArray<T>::FindSubQueue(StackArray<T>* stackArray) {
    if (stackArray->GetLength() > this->GetLength()) {
        return false;
    }

    bool answer = false;
    int k = 0;
    int j = stackArray->GetLength() - 1;
    while (j < this->GetLength()) {
        answer = true;
        for (int i = k; i <= j; i++) {
            if (this->items->Get(i) != stackArray->items->Get(i - k)) {
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