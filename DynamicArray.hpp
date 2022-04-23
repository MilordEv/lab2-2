#ifndef __DYNAMICARRAY__
#define __DYNAMICARRAY__

#include <cstring>
#include <stdexcept>

template <typename T>
class DynamicArray {

    private:
        T* items;
        size_t capacity;

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
    this->capacity = count;
}

template <typename T>
DynamicArray<T>::DynamicArray(int size) : capacity(size) {
    this->items = new T[size];
}

template <typename T>
DynamicArray<T>::DynamicArray() : capacity(0), items(nullptr) {}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &dynamicArray) {

    this->capacity = dynamicArray.capacity;

    if (this->capacity) {
        this->items = new T[this->capacity];
        memcpy(this->items, dynamicArray.items, this->capacity * sizeof(T));
    } else {
        this->items = nullptr;
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] this->items;
}





template <typename T>
T DynamicArray<T>::Get(int index) {
    if (index >= this->capacity || index < 0)  {
        throw std::out_of_range("Out of the range of the array");
    } else {
        return this->items[index];
    }
}

template <typename T>
size_t DynamicArray<T>::GetSize() {
    return this->capacity;
}

template <typename T>
void DynamicArray<T>::Set(int index, T value) {
    if (index >= this->capacity || index < 0)  {
        throw std::out_of_range("Out of the range of the array");
    }

    memcpy(this->items + index, &value, sizeof(T));
    return;
}

template <typename T>
void DynamicArray<T>::Resize(int newSize) {
    if (newSize < 0) {
        throw std::invalid_argument("invalid value");
    }

    if (newSize) {
        T* bufer = new T[newSize];
        memcpy(bufer, this->items, this->capacity * sizeof(T));
        delete[] this->items;
        this->items = bufer;
    } else {
        delete[] this->items;
        this->items = nullptr;
    }
    
    this->capacity = newSize;
    return;
}

#endif