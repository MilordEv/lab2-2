#ifndef __STACKLIST__
#define __STACKLIST__

#include <stdexcept>
#include "ListSequence.hpp"

template<typename T>
class StackList{
    private:
        ListSequence<T>* items;

    public:
        StackList(T* items, int count);
        StackList();
        StackList(const StackList<T> &stackList);

        ~StackList();

        int GetLength();
        bool Empty();
        void Push(T item);
        T Pop();
        void Clear();
        void Print();

        StackList<T>* Map(T func(T));
        StackList<T>* Where(bool func(T));
        T Reduce(T func(T, T), T startValue);

        void Concat(StackList<T>* stackList);
        StackList<T>* GetSubQueue(int firstIndex, int lastIndex);
        bool FindSubQueue(StackList<T>* stackList);
};


template<typename T>
StackList<T>::StackList(T* items, int count) {
    this->items = new ListSequence<T>(items, count);
}

template<typename T>
StackList<T>::StackList() {
    this->items = new ListSequence<T>;
}

template<typename T>
StackList<T>::StackList(const StackList<T> &stackList) {
    *(this->items) = *(stackList.items);
}



template<typename T>
StackList<T>::~StackList() {
    delete this->items;
}


template<typename T>
int StackList<T>::GetLength() {
    return this->items->GetLength();
}

template<typename T>
bool StackList<T>::Empty() {
    return this->items->GetLength() == 0;
}

template<typename T>
void StackList<T>::Push(T item) {
    this->items->Append(item);
    return;
}

template<typename T>
T StackList<T>::Pop() {
    T value = this->items->GetLast();
    this->items->Remove(this->items->GetLength() - 1);
    return value;
}

template<typename T>
void StackList<T>::Clear() {
    delete this->items;
    this->items = new ListSequence<T>;
    return;
}

template<typename T>
void StackList<T>::Print() {
    for (int i = 0; i < this->items->GetLength(); i++) {
        std::cout << this->items->Get(i) << " ";
    }
    std::cout << std::endl;
    return;
}

template<typename T>
StackList<T>* StackList<T>::Map(T func(T value)) {
    StackList<T>* newQueue = new StackList<T>;
    ListSequence<T>* listSequence = (ListSequence<T>*) this->items->Map(func);
    for (int i = 0; i < listSequence->GetLength(); i++) {
        newQueue->Push(listSequence->Get(i));
    }

    delete listSequence;
    return newQueue;
}

template<typename T>
StackList<T>* StackList<T>::Where(bool func(T)) {
    StackList<T>* newQueue = new StackList<T>;
    ListSequence<T>* listSequence = (ListSequence<T>*) this->items->Where(func);
    for (int i = 0; i < listSequence->GetLength(); i++) {
        newQueue->Push(listSequence->Get(i));
    }

    delete listSequence;
    return newQueue;
}

template<typename T>
T StackList<T>::Reduce(T func(T v1, T v2), T startValue) {
    return this->items->Reduce(func, startValue);
}

template<typename T>
void StackList<T>::Concat(StackList<T>* stackList) {
    this->items->Concat(stackList->items);
    
    return;
}

template<typename T>
StackList<T>* StackList<T>::GetSubQueue(int firstIndex, int lastIndex) {
    StackList<T>* newQueue = new StackList<T>;
    ListSequence<T>* listSequence = (ListSequence<T>*) this->items->GetSubsequence(firstIndex, lastIndex);
    for (int i = 0; i < listSequence->GetLength(); i++) {
        newQueue->Push(listSequence->Get(i));
    }

    delete listSequence;
    return newQueue;
}

template<typename T>
bool StackList<T>::FindSubQueue(StackList<T>* stackList) {
    if (stackList->GetLength() > this->GetLength()) {
        return false;
    }

    bool answer = false;
    int k = 0;
    int j = stackList->GetLength() - 1;
    while (j < this->GetLength()) {
        answer = true;
        for (int i = k; i <= j; i++) {
            if (this->items->Get(i) != stackList->items->Get(i - k)) {
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