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
        void Remove(int index) override;
        ArraySequence<T>* Concat(Sequence <T> *list) override;

        ~ArraySequence();
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
Sequence <T>* ArraySequence<T>::GetSubsequence(int startIndex, int endIndex) {
    if (startIndex >= this->count || startIndex < 0 || endIndex >= this->count || endIndex < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    T* items = new T[endIndex - startIndex + 1];
    for (int i = startIndex; i <= endIndex; i++) {
        items[i - startIndex] = this->items->Get(i);
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

        } else {
            this->items->Resize(2 * this->count);
        }
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

        this->items->Resize(2 * this->count);
    }

    for (int i = this->count; i > 0; i--) {
        this->items->Set(i, this->items->Get(i-1));
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

        this->items->Resize(2 * this->count);
    }

    for (int i = this->count; i > index; i--) {
        this->items->Set(i, this->items->Get(i-1));
    }

    this->items->Set(index, item);
    this->count += 1;
    return;
}

template<typename T>
void ArraySequence<T>::Remove(int index) {
    if (index >= this->count || index < 0) {
        throw std::out_of_range("Out of the range of the array");
    }

    for (int i = index; i < count - 1; i++) {
        this->items->Set(i, this->items->Get(i+1));
    }

    if (this->count < (this->items->GetSize() / 3)) {
        this->items->Resize(this->items->GetSize() / 3);
    }

    this->count -= 1;
}

template<typename T>
ArraySequence<T>* ArraySequence<T>::Concat(Sequence<T> *list) {
    if ((this->count + list->GetLength()) > this->items->GetSize()) {
        this->items->Resize(this->count + list->GetLength());
    }

    for (int i = this->count; i < this->count + list->GetLength(); i++) {
        this->items->Set(i, list->Get(i - this->count));
    }

    this->count += list->GetLength();
    return this;
}

#endif