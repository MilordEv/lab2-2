#ifndef __ARRAYDIAGONALMATRIX__
#define __ARRAYDIAGONALMATRIX__

#include "ArraySequence.hpp"
#include <stdexcept>
#include <math.h>

template<typename T>
class ArrayDiagonalMatrix {
    private:
        ArraySequence<T>* items;

    public:
        ArrayDiagonalMatrix(int dimension, T* items);
        ArrayDiagonalMatrix();
        ArrayDiagonalMatrix(const ArrayDiagonalMatrix<T> &diagonalMatrix);
        ~ArrayDiagonalMatrix();

        size_t GetDimension() const; 
        T Get(int indexRow, int indexColumn) const;

        void InsertRowOrColumn(int index, T newValue);

        void MultScalar(T scalar);
        void AddMatrix(ArrayDiagonalMatrix<T>* diagonalMatrix);

        T GetNorm();

        const ArrayDiagonalMatrix<T> & operator = (const ArrayDiagonalMatrix<T> & diagonalMatrix);

};

template<typename T>
ArrayDiagonalMatrix<T>::ArrayDiagonalMatrix(int dimension, T* items) {
    this->items = new ArraySequence<T>;
    for (int i = 0; i < dimension; i++) {
        this->items->Append(items[i]);
    }
}

template<typename T>
ArrayDiagonalMatrix<T>::ArrayDiagonalMatrix() {
    this->items = nullptr;
}

template<typename T>
ArrayDiagonalMatrix<T>::ArrayDiagonalMatrix(const ArrayDiagonalMatrix<T> &diagonalMatrix) {
    this->items = new ArraySequence<T>;

    for (int i = 0; i < diagonalMatrix.GetDimension(); i++) {
            this->items->Append(diagonalMatrix.Get(i, i));
    }
}


template<typename T>
const ArrayDiagonalMatrix<T> & ArrayDiagonalMatrix<T>::operator = (const ArrayDiagonalMatrix<T> & diagonalMatrix) {
    this->items = new ArraySequence<T>;

    for (int i = 0; i < diagonalMatrix.GetDimension(); i++) {
            this->items->Append(diagonalMatrix.Get(i, i));
    }

    return *this;
}




template<typename T>
ArrayDiagonalMatrix<T>::~ArrayDiagonalMatrix() {
    delete this->items;
}




template<typename T>
size_t ArrayDiagonalMatrix<T>::GetDimension() const {
    if (!(this->items)) {
        return 0;
    }

    return this->items->GetLength();
}

template<typename T>
T ArrayDiagonalMatrix<T>::Get(int indexRow, int indexColumn) const {

    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

    if (indexRow >= this->GetDimension() || indexRow < 0) {
        throw std::out_of_range("Out of the range of the matrix");
    }

    if (indexColumn >= this->GetDimension() || indexColumn < 0) {
        throw std::out_of_range("Out of the range of the matrix");
    }

    if (indexRow != indexColumn) {
        throw std::out_of_range("Out of the range of the matrix");
    }

    return this->items->Get(indexRow);
}

template<typename T>
void ArrayDiagonalMatrix<T>::InsertRowOrColumn(int index, T newValue) {
    if (this->items) {

        if (index >= this->GetDimension() || index < 0) {
            throw std::out_of_range("Out of the range of the matrix");
        }

        this->items->InsertAt(newValue, index);

    } else {
        this->items = new ArraySequence<T>;
        this->items->Append(newValue);
    }
}

template<typename T>
void ArrayDiagonalMatrix<T>::MultScalar(T scalar) {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

    if (!(scalar)) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        this->items->Set(this->Get(i, i) * scalar, i);
    }
}

template<typename T>
void ArrayDiagonalMatrix<T>::AddMatrix(ArrayDiagonalMatrix<T>* diagonalMatrix) {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

    if (this->GetDimension() != diagonalMatrix->GetDimension()) {
        throw std::invalid_argument("the number of rows in the matrix does not match");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        this->items->Set(this->Get(i, i) + diagonalMatrix->Get(i, i), i);
    }
} 

template<typename T>
T ArrayDiagonalMatrix<T>::GetNorm() {
    if (!(this->items)) {
        throw std::domain_error("Empty matrix");
    }

    T valueNorm = this->Get(0, 0);
    valueNorm *= valueNorm;

    for (int i = 1; i < this->GetDimension(); i++) {
        valueNorm += this->Get(i, i) * this->Get(i, i);
    }

    return pow(valueNorm, 0.5);
}

#endif