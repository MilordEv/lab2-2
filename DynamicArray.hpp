#ifndef __DYNAMICARRAY__
#define __DYNAMICARRAY__

#include <iostream>
#include <cstring>
#include <stdexcept>

template <typename T>
class DynamicArray {

    private:
        T* items;
        size_t count;

    public:
       DynamicArray(T* items, int count);
       DynamicArray(int size);
       DynamicArray();
       DynamicArray(const DynamicArray<T> &dynamicArray); 

       ~DynamicArray();

    public:
        T Get(int index);
        size_t GetSize();
        void Set(int index, T value);
        void Resize(int newSize);
};

template <typename T>
DynamicArray<T>::DynamicArray(T* items, int count) {
    this->items = new T[count];
    memcpy(this->items, items, count * sizeof(T));
    this->count = count;
}

template <typename T>
DynamicArray<T>::DynamicArray(int size) : count(size) {
    this->items = new T[size];
}

template <typename T>
DynamicArray<T>::DynamicArray() : count(0), items(nullptr) {}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &dynamicArray) {

    std::cout << "zero" << std::endl;

    this->count = dynamicArray.count;

    if (this->count) {
        this->items = new T[this->count];
        memcpy(this->items, dynamicArray.items, this->count * sizeof(T));
        std::cout << "second" << std::endl;
    } else {
        std::cout << "third" << std::endl;
        this->items = nullptr;
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] this->items;
}





template <typename T>
T DynamicArray<T>::Get(int index) {
    if (index >= this->count || index < 0)  {
        throw std::out_of_range("Out of the range of the array");
    } else {
        return this->items[index];
    }
}

template <typename T>
size_t DynamicArray<T>::GetSize() {
    return this->count;
}

template <typename T>
void DynamicArray<T>::Set(int index, T value) {
    if (index >= this->count || index < 0)  {
        throw std::out_of_range("Out of the range of the array");
    }

    memcpy(this->items + index, &value, sizeof(T));
}

template <typename T>
void DynamicArray<T>::Resize(int newSize) {
    if (newSize < 0) {
        throw std::invalid_argument("invalid value");
    }

    if (newSize) {
        T* bufer = new T[newSize];
        memcpy(bufer, this->items, this->count * sizeof(T));
        delete[] this->items;
        this->items = bufer;
    } else {
        delete[] this->items;
        this->items = nullptr;
    }
    
    this->count = newSize;
}

#endif