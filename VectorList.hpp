#ifndef __VECTORLIST__
#define __VECTORLIST__

#include "ListSequence.hpp"
#include <stdexcept>
#include <math.h>

template<typename T>
class VectorList {
    private:
        ListSequence<T>* items;

    public:
        VectorList(int dimension, T* items);
        VectorList();
        VectorList(const VectorList<T> &vector);
        ~VectorList();

        size_t GetDimension() const; 
        T Get(int index) const;

        void ScalarMult(VectorList<T>* vector);

        void MultScalar(T scalar);
        void AddVector(VectorList<T>* vector);

        T GetNorm();

        const VectorList<T> & operator = (const VectorList<T> & vector);

};

template<typename T>
VectorList<T>::VectorList(int dimension, T* items) {
    this->items = new ListSequence<T>;
    for (int i = 0; i < dimension; i++) {
        this->items->Append(items[i]);
    }
}

template<typename T>
VectorList<T>::VectorList() {
    this->items = nullptr;
}

template<typename T>
VectorList<T>::VectorList(const VectorList<T> &vector) {
    this->items = new ListSequence<T>;

    for (int i = 0; i < vector.GetDimension(); i++) {
            this->items->Append(vector.Get(i));
    }
}


template<typename T>
const VectorList<T> & VectorList<T>::operator = (const VectorList<T> & vector) {
    this->items = new ListSequence<T>;

    for (int i = 0; i < vector.GetDimension(); i++) {
            this->items->Append(vector.Get(i));
    }

    return *this;
}




template<typename T>
VectorList<T>::~VectorList() {
    delete this->items;
}




template<typename T>
size_t VectorList<T>::GetDimension() const {
    if (!(this->items)) {
        return 0;
    }

    return this->items->GetLength();
}

template<typename T>
T VectorList<T>::Get(int index) const {

    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

    if (index >= this->GetDimension() || index < 0) {
        throw std::out_of_range("Out of the range of the matrix");
    }

    return this->items->Get(index);
}

template<typename T>
void VectorList<T>::ScalarMult(VectorList<T>* vector) {
    if (this->GetDimension() != vector->GetDimension()) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        this->items->Set(this->items->Get(i) * vector->Get(i), i);
    }
}

template<typename T>
void VectorList<T>::MultScalar(T scalar) {
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
void VectorList<T>::AddVector(VectorList<T>* vector) {
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
T VectorList<T>::GetNorm() {
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