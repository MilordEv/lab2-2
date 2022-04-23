#ifndef __ARRAY_SEQUENCE__
#define __ARRAY_SEQUENCE__

#include <stdexcept>
#include "Sequence.hpp"
#include "DynamicArray.hpp"

template<typename T>
class ArraySequence : public Sequence<T> {
    private:
        DynamicArray<T>* items;
        int count;

    public:
        ArraySequence(T* items, int count);
        ArraySequence();
        ArraySequence(const ArraySequence<T> &arraySequence);

        T GetFirst() override;
        T GetLast() override;
        T Get(int index) override;
        int GetLength() override;
        Sequence<T>* GetSubsequence(int startIndex, int endIndex) override;

        void Append(T item) override;
        void Prepend(T item) override;
        void InsertAt(T item, int index) override;
        ArraySequence<T>* Concat(Sequence <T> *list) override;

        ~ArraySequence() override;
};

template<typename T>
ArraySequence<T>::ArraySequence(T* items, int count) {
    this->count = count;
    this->items = new DynamicArray<T>(items, count);
}

template<typename T>
ArraySequence<T>::ArraySequence() {
    this->count = 0;
    this->items = new DynamicArray<T>();
}

template<typename T>
ArraySequence<T>::ArraySequence(const ArraySequence<T> &arraySequence) {
    this->count = arraySequence.count;

    if (this->count) {
        this->items = new DynamicArray<T>(arraySequence.items);
    } else {
        this->items = new DynamicArray<T>();
    }
}

template<typename T>
ArraySequence<T>::~ArraySequence() {
    delete this->items;
} 





template<typename T>
T ArraySequence<T>::GetFirst() {
    if (!(this->count)) {
        throw std::out_of_range("Еhe sequence is empty");
    }

    return this->items->Get(0);
}

template<typename T>
T ArraySequence<T>::GetLast() {
    if (!(this->count)) {
        throw std::out_of_range("Еhe sequence is empty");
    }

    return this->items->Get( this->count - 1 );
}

template<typename T>
T ArraySequence<T>::Get(int index) {
    if (index >= this->count || index < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    return this->items->Get(index);
}

template<typename T>
int ArraySequence<T>::GetLength() {
    return this->count;
}

template<typename T>
Sequence<T>* ArraySequence<T>::GetSubsequence(int startIndex, int endIndex) {
    T* items = new T[endIndex - startIndex + 1];
    for (int i = startIndex; i <= endIndex; i++) {
        items[i] = this->items->Get(i);
    }

    ArraySequence<T>* newArraySequence = new ArraySequence(items, endIndex - startIndex + 1);
    delete[] items;

    return newArraySequence;
}

template<typename T>
void ArraySequence<T>::Append(T item) {
    if (this->count >= this->items->GetSize()) {
        if (!(this->count)) {
            this->items->Resize(2);
        }

        this->items->Resize(2 * this->items->GetSize());
    }

    this->items->Set(count, item);
    this->count += 1;
    return;
} 

template<typename T>
void ArraySequence<T>::Prepend(T item) {
    if (this->count >= this->items->GetSize()) {
        if (!(this->count)) {
            this->items->Resize(2);
        }

        this->items->Resize(2 * this->items->GetSize());
    }

    for (int i = 0; i < this->count; i++) {
        this->items->Set(i+1, this->items->Get(i));
    }

    this->items->Set(0, item);
    this->count += 1;
    return;
} 

template<typename T>
void ArraySequence<T>::InsertAt(T item, int index) {
    if (index >= this->count || index < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    if (this->count >= this->items->GetSize()) {
        if (!(this->count)) {
            this->items->Resize(2);
        }

        this->items->Resize(2 * this->items->GetSize());
    }

    for (int i = index; i < this->count; i++) {
        this->items->Set(i+1, this->items->Get(i));
    }

    this->items->Set(index, item);
    this->count += 1;
    return;
}

template<typename T>
ArraySequence<T>* ArraySequence<T>::Concat(Sequence <T> *list) {
    if ((this->count + list->GetLength()) > this->items->GetSize()) {
        this->items->Resize(this->count + list->GetLength());
    }

    for (int i = this->count; i < this->count + list->GetLength(); i++) {
        this->items->Set(i, list->Get(i));
    }

    this->count += list->GetLength();
    return this;
}

#endif