#ifndef __VECTORARRAY__
#define __VECTORARRAY__

#include "ArraySequence.hpp"
#include <stdexcept>
#include <math.h>

template<typename T>
class VectorArray {
    private:
        ArraySequence<T>* items;

    public:
        VectorArray(int dimension, T* items);
        VectorArray();
        VectorArray(const VectorArray<T> &vector);
        ~VectorArray();

        size_t GetDimension() const; 
        T Get(int index) const;

        void ScalarMult(VectorArray<T>* vector);

        void MultScalar(T scalar);
        void AddVector(VectorArray<T>* vector);

        T GetNorm();

        const VectorArray<T> & operator = (const VectorArray<T> & vector);

};

template<typename T>
VectorArray<T>::VectorArray(int dimension, T* items) {
    this->items = new ArraySequence<T>;
    for (int i = 0; i < dimension; i++) {
        this->items->Append(items[i]);
    }
}

template<typename T>
VectorArray<T>::VectorArray() {
    this->items = nullptr;
}

template<typename T>
VectorArray<T>::VectorArray(const VectorArray<T> &vector) {
    this->items = new ArraySequence<T>;

    for (int i = 0; i < vector.GetDimension(); i++) {
            this->items->Append(vector.Get(i));
    }
}


template<typename T>
const VectorArray<T> & VectorArray<T>::operator = (const VectorArray<T> & vector) {
    this->items = new ArraySequence<T>;

    for (int i = 0; i < vector.GetDimension(); i++) {
            this->items->Append(vector.Get(i));
    }

    return *this;
}




template<typename T>
VectorArray<T>::~VectorArray() {
    delete this->items;
}




template<typename T>
size_t VectorArray<T>::GetDimension() const {
    if (!(this->items)) {
        return 0;
    }

    return this->items->GetLength();
}

template<typename T>
T VectorArray<T>::Get(int index) const {

    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

    if (index >= this->GetDimension() || index < 0) {
        throw std::out_of_range("Out of the range of the matrix");
    }

    return this->items->Get(index);
}

template<typename T>
void VectorArray<T>::ScalarMult(VectorArray<T>* vector) {
    if (this->GetDimension() != vector->GetDimension()) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        this->items->Set(this->items->Get(i) * vector->Get(i), i);
    }
}

template<typename T>
void VectorArray<T>::MultScalar(T scalar) {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

    if (!(scalar)) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        this->items->Set(this->Get(i) * scalar, i);
    }
}

template<typename T>
void VectorArray<T>::AddVector(VectorArray<T>* vector) {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

    if (this->GetDimension() != vector->GetDimension()) {
        throw std::invalid_argument("the number of rows in the matrix does not match");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        this->items->Set(this->Get(i) + vector->Get(i), i);
    }
} 

template<typename T>
T VectorArray<T>::GetNorm() {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

    T valueNorm = this->Get(0);
    valueNorm *= valueNorm;

    for (int i = 1; i < this->GetDimension(); i++) {
        valueNorm += this->Get(i) * this->Get(i);
    }

    return pow(valueNorm, 0.5);
}

#endif