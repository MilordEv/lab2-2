#ifndef __LISTDIAGONALMATRIX__
#define __LISTDIAGONALMATRIX__

#include "ListSequence.hpp"
#include <stdexcept>
#include <math.h>

template<typename T>
class ListDiagonalMatrix {
    private:
        ListSequence<T>* items;

    public:
        ListDiagonalMatrix(int dimension, T* items);
        ListDiagonalMatrix();
        ListDiagonalMatrix(const ListDiagonalMatrix<T> &diagonalMatrix);
        ~ListDiagonalMatrix();

        size_t GetDimension() const; 
        T Get(int indexRow, int indexColumn) const;

        void InsertRowOrColumn(int index, T newValue);

        void MultScalar(T scalar);
        void AddMatrix(ListDiagonalMatrix<T>* diagonalMatrix);

        T GetNorm();

        const ListDiagonalMatrix<T> & operator = (const ListDiagonalMatrix<T> & squarearMatrix);

};

template<typename T>
ListDiagonalMatrix<T>::ListDiagonalMatrix(int dimension, T* items) {
    this->items = new ListSequence<T>;
    for (int i = 0; i < dimension; i++) {
        this->items->Append(items[i]);
    }
}

template<typename T>
ListDiagonalMatrix<T>::ListDiagonalMatrix() {
    this->items = nullptr;
}

template<typename T>
ListDiagonalMatrix<T>::ListDiagonalMatrix(const ListDiagonalMatrix<T> &diagonalMatrix) {
    this->items = new ListSequence<T>;

    for (int i = 0; i < diagonalMatrix.GetDimension(); i++) {
            this->items->Append(diagonalMatrix.Get(i, i));
    }
}


template<typename T>
const ListDiagonalMatrix<T> & ListDiagonalMatrix<T>::operator = (const ListDiagonalMatrix<T> & diagonalMatrix) {
    this->items = new ListSequence<T>;

    for (int i = 0; i < diagonalMatrix.GetDimension(); i++) {
            this->items->Append(diagonalMatrix.Get(i, i));
    }

    return *this;
}




template<typename T>
ListDiagonalMatrix<T>::~ListDiagonalMatrix() {
    delete this->items;
}




template<typename T>
size_t ListDiagonalMatrix<T>::GetDimension() const {
    return this->items->GetLength();
}

template<typename T>
T ListDiagonalMatrix<T>::Get(int indexRow, int indexColumn) const {

    if (!(this->items)) {
        throw std::domain_error("Empty matrix")
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
void ListDiagonalMatrix<T>::InsertRowOrColumn(int index, T newValue) {
    if (index >= this->GetDimension() || index < 0) {
        throw std::out_of_range("Out of the range of the matrix");
    }

    this->items->InsertAt(newValue, index);
}

template<typename T>
void ListDiagonalMatrix<T>::MultScalar(T scalar) {
    if (!(scalar)) {
        throw std::invalid_argument("invalid value");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        this->items->Set(this->Get(i, i) * scalar, i);
    }
}

template<typename T>
void ListDiagonalMatrix<T>::AddMatrix(ListDiagonalMatrix<T>* diagonalMatrix) {
    if (this->GetDimension() != diagonalMatrix->GetDimension()) {
        throw std::invalid_argument("the number of rows in the matrix does not match");
    }

    for (int i = 0; i < this->GetDimension(); i++) {
        this->items->Set(this->Get(i, i) + diagonalMatrix->Get(i, i), i);
    }
} 

template<typename T>
T ListDiagonalMatrix<T>::GetNorm() {
    if (!(this->GetDimension())) {
        throw std::domain_error("empty matrix");
    }

    T valueNorm = this->Get(0, 0);
    valueNorm *= valueNorm;

    for (int i = 1; i < this->GetDimension(); i++) {
        valueNorm += this->Get(i, i) * this->Get(i, i);
    }

    return pow(valueNorm, 0.5);
}

#endif