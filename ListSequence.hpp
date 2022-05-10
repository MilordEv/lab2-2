#ifndef __LIST_SEQUENCE__
#define __LIST_SEQUENCE__

#include <stdexcept>
#include "Sequence.hpp"
#include "LinkedList.hpp"

template<typename T>
class ListSequence : public Sequence<T> {
    private:
        LinkedList<T>* items;

    public:
        ListSequence(T* items, int count);
        ListSequence();
        ListSequence(const ListSequence<T> &listSequence);

        T GetFirst() override;
        T GetLast() override;
        T Get(int index) override;
        int GetLength() override;
        Sequence<T>* GetSubsequence(int startIndex, int endIndex) override;

        void Set(T item, int index) override;
        void Append(T item) override;
        void Prepend(T item) override;
        void InsertAt(T item, int index) override;
        void Remove(int index) override;
        ListSequence<T>* Concat(Sequence<T> *list) override;

        ~ListSequence();
};


template<typename T>
ListSequence<T>::ListSequence(T* items, int count) {
    this->items = new LinkedList<T>(items, count);
}

template<typename T>
ListSequence<T>::ListSequence() {
    this->items = new LinkedList<T>();
}

template<typename T>
ListSequence<T>::ListSequence(const ListSequence<T> &listSequence) {
    if (listSequence.items->GetLength()) {
        this->items = new LinkedList<T>(listSequence.items, listSequence.items->GetLength());
    } else {
        this->items = new LinkedList<T>();
    }
}



template<typename T>
ListSequence<T>::~ListSequence() {
    delete this->items;
}




template<typename T>
T ListSequence<T>::GetFirst() {
    return this->items->GetFirst();
}

template<typename T>
T ListSequence<T>::GetLast() {
    return this->items->GetLast();
}

template<typename T>
T ListSequence<T>::Get(int index) {
    return this->items->Get(index);
}

template<typename T>
int ListSequence<T>::GetLength() {
    return this->items->GetLength();
}

template<typename T>
Sequence<T>* ListSequence<T>::GetSubsequence(int startIndex, int endIndex) {
    ListSequence<T>* subList = new ListSequence<T>();
    for (int i = startIndex; i <= endIndex; i++) {
        subList->Append(this->Get(i));
    }
    return subList;
}



template<typename T>
void ListSequence<T>::Set(T item, int index) {
    if (index >= this->GetLength() || index < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    this->InsertAt(item, index);
    this->Remove(index + 1);
}



template<typename T>
void ListSequence<T>::Append(T item) {
    this->items->Append(item);
    return;
}

template<typename T>
void ListSequence<T>::Prepend(T item) {
    this->items->Prepend(item);
    return;
}

template<typename T>
void ListSequence<T>::InsertAt(T item, int index) {
    this->items->InsertAt(item, index);
    return;
}

template<typename T>
void ListSequence<T>::Remove(int index) {
    this->items->Remove(index);
    return;
}

template<typename T>
ListSequence<T>* ListSequence<T>::Concat(Sequence<T> *list) {
    for(int i = 0; i < list->GetLength(); i++) {
        this->Append(list->Get(i));
    }

    return this;
}
        

#endif